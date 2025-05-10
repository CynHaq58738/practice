#include <stdio.h>

// r to read a file

int main()
{

    FILE *pf = fopen("test.txt", "r");
    char buffer[255];

    while( fgets(buffer, 255, pf) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(pf);

    return 0;
}