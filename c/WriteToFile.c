#include <stdio.h>

// w to overwrite
// a to append 



int main()
{
    FILE *pf = fopen("test.txt", "a");

    fprintf(pf, "\nSpongebob Squarepants");
    fclose(pf);





    return 0;


}