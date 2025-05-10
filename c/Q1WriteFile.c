#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pF = fopen("Q1.out", "w");
   
    fprintf(pF, "FORWARD\n");
    fprintf(pF, "DEFENSEMAN\n");
    fprintf(pF, "GOALIE\n");
    fprintf(pF, "DEFENSEMAN\n");
    fprintf(pF, "FORWARD\n");
    fprintf(pF, "DEFENSEMAN\n");

    fclose(pF);
    return 0;
}