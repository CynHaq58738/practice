#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int n;

    FILE *pF = fopen("Q1.in", "r");
   
    for(i = 0; i<6; i++)
    {
        fscanf(pF, "%d\n", &n);

        if(n>7)
        {
            printf("GOALIE\n");
        }
        else if(n>=4)
        {
            printf("DEFENSEMAN\n");
        }
        else
        {
            printf("FORWARD\n");
        }

    }
    fclose(pF);
    return 0;
}