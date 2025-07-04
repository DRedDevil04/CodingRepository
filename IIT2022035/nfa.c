#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
 
int row = 0;
 
// A structure to represent an adjacency list node
struct node
{
    int data;
    struct node* next;
    char edgetype;
 
}typedef node;
 

node* push(node* first , char edgetype , int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->edgetype = edgetype;
    new_node->data = data;
    new_node->next = NULL;
    if (first==NULL)
    {
        first = new_node;
        return new_node;
    }
    first->next = push(first->next,edgetype,data);
    return first;
}
 
//Recursive function to check acceptance of input
int nfa(node** graph, int current, char* input,
        int* accept, int start)
{
    if (start==(int)strlen(input))
        return accept[current];
 
    node* temp = graph[current];
    while (temp != NULL)
    {
      if (input[start]==temp->edgetype)
        if (nfa(graph,temp->data,input,accept,start+1==1))
           return 1;
      temp=temp->next;
    }
    return 0;
}
 
//Function to generate binary strings of size n

 
// Driver program to test above functions
int main()
{
    int n;
    int i, j;
    scanf("%d", &n); //Number of nodes
    node* graph[n+1]; //Create a graph
 
    for (i=0;i<n+1;i++)
        graph[i]=NULL;
 
 
    int accept[n+1]; //Array to store state of vertex
 
    for (i=0; i<n; i++)
    {
        //Index of vertex , Acceptance state , Number of edges
        int index,acc,number_nodes;
        scanf("%d%d%d",&index,&acc,&number_nodes);
        accept[index]=acc; //Store acceptance
 
        for (j=0;j<number_nodes;j++) //Add all edges
        {
            int node_add;
            int edge;
            scanf("%d%d",&edge,&node_add);
            graph[index] = push(graph[index],'0'+edge,node_add);
        }
    }
 
    int size = 1; //Size of input
    int count = 0; //Keep count of output strings
 
    if (accept[1]==1) //Check for empty string
    {
        printf("e\n");
        count++;
    }
 
   
        char** arr;
        int power = pow(2,size);
        arr = (char**)malloc(power*sizeof(char*));
 
        for (i=0;i<power;i++)
            arr[i] = (char*)malloc(size*sizeof(char));
 
        char a[20] = {'\0'};
 
        // generate((char**)arr,size,a); //Generate inputs
 
        for (i=0; i<power; i++)
        {
            char input[20] = "abbbbba";
 
            for (j=0; j<size; j++)
            {
                char foo[2];
                foo[0] = arr[i][size-1-j];
                foo[1] = '\0';
                strcat(input,foo);
                                //Copy generated string input
            }
 
            int result = nfa(graph,1,input,accept,0);
                        // Store result of nfa
 
            if (result==1)
            {
                printf("%s\n",input);
                                // Print if accepted
                count++;
            }
 
            if (count==10)
                return 0;
        }
 
        size++; //Increment size of binary string input
        row=0;
    
 
    return 0;
}