#include<stdio.h>

int main() {
  int marks[20][5] = {
    {56, 86, 79, 45, 98},  // Student 1
    {64, 45, 98, 45, 65},  // Student 3
    {47, 98, 65, 45, 78},  // Student 2
    {87, 78, 15, 78, 45},  // Student 4
    {68, 79, 87, 95, 45},  // Student 5
    {79, 64, 64, 97, 67},  // Student 6
    {88, 76, 92, 84, 79},  // Student 7
    {55, 62, 71, 80, 68},  // Student 8
    {90, 95, 89, 94, 91},  // Student 9
    {42, 58, 66, 49, 53},  // Student 10
    {73, 81, 77, 85, 89},  // Student 11
    {61, 70, 68, 74, 72},  // Student 12
    {85, 87, 90, 88, 92},  // Student 13
    {50, 52, 60, 45, 58},  // Student 14
    {67, 75, 70, 69, 74},  // Student 15
    {93, 91, 96, 99, 95},  // Student 16
    {78, 84, 80, 82, 86},  // Student 17
    {59, 63, 61, 57, 65},  // Student 18
    {82, 80, 85, 88, 84},  // Student 19
    {70, 72, 74, 71, 73}   // Student 20
  };

  int avg_mark_of_sub[5] = {0,0,0,0,0};
  int avg_mark_of_stud[20];
  int i, j;

  // Average mark obtained in each subject
  for(i=0; i<5; i++){
    int sum=0;
    for(j=0; j<20; j++)
      sum += marks[j][i];
    
    avg_mark_of_sub[i] = sum/20;
  }

  printf("Average mark of each subjects\n\n");
  // printf avg mark of each subject
  for(i=0; i<5; i++)
    printf("%d ",avg_mark_of_sub[i]);
  printf("\n");

  // Assign Avg mark of student to 0
  for(i=0; i<20; i++)
    avg_mark_of_stud[i] = 0;

  // calculate avg mark of student
  for (i = 0; i < 20; i++)
  {
    int sum=0;
    for (j = 0; j < 5; j++)
      sum += marks[i][j];

    avg_mark_of_stud[i] = sum/5;
  }

  printf("Student average mark\n\n");
  // print avg mark of student
  for(i=0; i<20; i++)
    printf("studnet %d -> %d\n",i+1,avg_mark_of_stud[i]);
  
  printf("Student whose average makr is below than 50\n\n");
  for(i=0; i<20; i++){
    if(avg_mark_of_stud[i] < 60)
      printf("student %d -> %d\n",i+1,avg_mark_of_stud[i]);
  }
  

  return 0;
}