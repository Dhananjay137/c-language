#include<stdio.h>

// Write a program to print the count of even numbers betwoon 1-200.
// Also print their sum.

int main(){
  int even_count=0,even_sum=0;
  int i,n=200;

  // Loop through even numbers starting from 2 up to 200
  for(i=2; i<=n; i += 2){
    even_count++; // Increment the count of even numbers
    even_sum += i; // Add the current even number to the total sum
  }

  printf("--- Results for Even Numbers (1-%d) ---\n",n);
  printf("Even number count: %d\n",even_count);
  printf("Even number sum: %d\n",even_sum);

  return 0;
}