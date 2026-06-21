#include <stdio.h>

int main(void)
{
    int i = 6720, j=4;

    while(i%j == 0){
      i = i/j;
      j = j + 1;
    }
    printf("%d",j);
    return 0;
}
