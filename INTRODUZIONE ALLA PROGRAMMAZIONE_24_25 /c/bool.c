#include <stdio.h>
#include <stdbool.h>
int main (void)
{

    // C interpretta tutto ciò che è diverso da zero (0) come VERO e ciòc he è uguale a zero (0) come FALSO

    bool a = false, b = true;

    if (a==false) // (!a)
    {
        printf("Vero");
    } else {
        printf("Falso");
    }

    printf("Fine");

    return 0;
     
}