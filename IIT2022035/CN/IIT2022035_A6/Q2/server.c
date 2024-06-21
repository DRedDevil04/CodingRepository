#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
void piperead (int signum);
int dd, pd[2];
void (*oldsigio) ();
int main (int argc, char *argv[])
{
  
    int flags, ct;
    char buf [80], ch;
    /*
    * Open a pipe, then close stdout and using dup, set up pd[1] to
    * be the same file descriptor.
    */
    if (pipe (pd) < 0)
    {
        fprintf (stderr, "Couldn't open pipe");
        exit (0);
    }
    close (1);
    dd = dup (pd[1]);
    /*
    * Make I/O on pd[1] asynchronous, which means this program can get
    * the signals from the OS.
    */
    flags = fcntl (pd[0], F_GETFL, 0);
    fcntl (pd[0], F_SETFL, flags | FASYNC |O_NDELAY); /*
    * Tell the system to catch the SIGIO signal. Technically, we could get
    * in trouble, since it will catch all asynchronous I/O, but that
    shouldn't * be a problem here.
    */
    if((oldsigio = signal (SIGIO, piperead))==SIG_ERR){
        fprintf(stderr,"ERROR IN CREATING HANDLER");
        exit(-1);
    }
    /*
    * Do the system command, which if it writes to stdout (file 1), it
    * will come back to the process via the signal handler. Note that the
    * "system" call will not return until the created child process
    completes * and terminates.
    */

   
    system ("ls");
     write(pd[1],"HEHHEHEHHE",20);
    /*
    * Reset signal to be safe and clean
    up. */
    signal (SIGIO, oldsigio);
    close (pd[0]);
    close (pd [1]);
    close (dd);
}
/*
* Asynchronous signal handler. Reads anything waiting at pd[1] and
* prints it out. It only executes when the system knows that something
* is waiting.
*/
void piperead (int signum)
{
    fprintf (stderr, " Devam is me\n" );
    char buf [80];
    /*
    * Read the pipe and output to the terminal. Stderr has to be used
    * because stdout has been closed. Note, this may output a strange
    * line at the end because it doesn't check for a line containing
    * a new line alone.
    */
    FILE *fptr=fopen("./ans.txt","w+");
    if (read (pd[0], buf, 80) > 3){
    fprintf (stderr, " Devam %s\n", buf);
    }
    return;
}
