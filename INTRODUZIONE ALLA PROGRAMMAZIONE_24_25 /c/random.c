#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printRandoms(int min, int max)
{
    srand(time(0));
    printf("Random numbers between %d and %d: ", min, max);
    int rd_num = rand() % (max - min + 1) + min;
    printf("%d ", rd_num);
}

int main()
{
    int min = 0, max = 7;
    printRandoms(min, max);
    return 0;
}