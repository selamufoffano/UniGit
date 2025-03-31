#include <stdio.h>
int x = 10;
int f(int z)
{
    {
        int z = ++x + 1;
        int x = z+1;
        return x;
    }
}

int main(void)
{
    printf("%d %d \n", f(0), f(0));
}