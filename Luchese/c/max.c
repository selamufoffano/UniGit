#include <stdio.h>

int main (void)
{
    int num1, num2, num3, max;
    printf("Inserire il primo valore: "); scanf("%d", &num1);
    printf("Inserire il primo valore: "); scanf("%d", &num2);
    printf("Inserire il primo valore: "); scanf("%d", &num3);

    if (num1 >= num2 && num1 >= num3){
        max = num1;
    }else if (num2 >= num1 && num2 >= num3)
    {
        max = num2;
    }else if (num3 >= num1 && num1 >= num2)
    {
        max = num3;
    }
    

    printf ("I numeri sono: %D %d %D \n", num1, num2, num3);

    printf("Il valore Max è: %d", max);
    return 0;
}