#include <stdio.h>
int main (void)
{
    /*
    int x = 60;
    int *ptrX = &x;
    printf("%d\n", x);
    printf("%p\n", &x);
    printf("%p", ptrX);
    // Dereferencing
    printf("%d", *ptrX);

    int y[4] = {10,20,30,40};
    printf("%p\n", &y);
    printf("%p\n", &y[0]); // medesima cosa di fare  printf("%p", &x); in quanto punta all'indirizzo 0
    printf("%p\n", &y[1]);
    printf("%p\n", &y[2]);
    printf("%p\n", &y[3]);

    printf("%d", *y);

    */
    int i;
    char c;
    printf("int: %lu byte - char: %lu byte", sizeof(int), sizeof(char));
    return 0;
}