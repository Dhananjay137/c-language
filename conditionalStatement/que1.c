#include <stdio.h>
int main()
{
    int i, j, count;
    count=0;
    i=0;
    for(j=-3; j <=3; j++)
    {
        if (( j >= 0) && (i++))
        count = count + j;

        printf("\ni: %d, j: %d, count: %d",i,j,count);
    }
    count = count +i;
    printf("%d", count);
    return 0;
}