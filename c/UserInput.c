#include <stdio.h>
#include <string.h>//to use in order to get rid of the newline character

int main()
{
    char name[25];//bytes
    int age;

    printf("\nWhats your name?: ");
    //can read up until any white spaces
    //scanf("%s", &name);
    
    //fgets can be used to include white space
    fgets(name, sizeof(name), stdin);//stdin means standard input
    name[strlen(name)-1] = '\0';//to get rit of newline character

    printf("How old are you?: ");
    scanf("%d", &age);

    printf("\nHello %s, how are you?", name);
    printf("\nYou are %d years old", age);

    return 0;
}