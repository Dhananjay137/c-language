#include<stdio.h>

// Write program to read two floating point numbers.
// Add this numbers and assign the result to an integer
// Finally, display the value of all the three variable.

int main(){
  float num1,num2;
  int result;

  printf("Enter first floating point number: ");
  scanf("%f",&num1);

  printf("Enter second floating point number: ");
  scanf("%f",&num2);

  result = num1 + num2;

  printf("%f + %f = %d\n",num1,num2,result);

  return 0;
}