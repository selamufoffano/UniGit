#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 4, 5};
    // int arr[4] = {1, 2, 4, 5};
    int min = 5;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("L'elemento più piccolo dell'array è: %d ", min);
}