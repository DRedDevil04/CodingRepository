#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void printCurve(double a, double b, double c) {
  int i;
  double x;
  
  for (i = 0; i < 360; i++) {
    x = PI * i / 180;
    printf("%f %f\n", x, a * sin(b * x) + c);
  }
}

int main() {
  double a, b, c;
  
  printf("Enter the values of a, b and c: ");
  scanf("%lf%lf%lf", &a, &b, &c);
  
  printCurve(a, b, c);
  
  return 0;
}

