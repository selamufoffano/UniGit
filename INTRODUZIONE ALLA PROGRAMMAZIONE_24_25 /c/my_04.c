#include <stdio.h>
int main(void)
{
    // Dato in input un numero (positivo) intero <=255,
    // visualizzare la sua rappresentazione binaria
    // 1 => 1
    // 2 => 10
    // 7 => 111
    /*
    n/2=res -> resto
    16/2=8 -> 0
    8/2=4 -> 0
    4/2=2 -> 0
    2/2=1 -> 0
    1/2=0 -> 1
    int n;
    printf("Insert n: ");
    scanf("%d", &n);
    do
    {
        // printf("%d", n);
        if (n % 2 == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        n = n / 2;

    } while (n > 0);

    return 0;
    int n, p, count;
    count =0;
    int pow = 1;
    printf("Insert n: ");scanf("%d", &n);
    printf("power of: ");scanf("%d", &p);
    do
    {

        pow=pow*n;
        count++;
    } while (count<p);
    printf("%d", pow);
    return 0;
    */
   	// Date le lunghezze di tre segmenti, 
	// dire se questi possono formare un triangolo.
	// se la somma di due è maggiore del terzo, per ogni coppia
    int a=4, b=2, c=2;
    if(a+b > c && a+c>b && c+b>a)
    {
        printf("Triangolo");
    }
    else
    {
        printf("Non Triangolo");
    }
}