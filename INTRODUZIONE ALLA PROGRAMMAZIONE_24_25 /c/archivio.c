#include <stdio.h>
// -------------Prova Intermedia del 04/11/2020 A

// 1. Scope. (Variante A ‑ punti 4)
/*
int x = 1;
int g(int y)
{
    return ++x + y;
}

int f(int x)
{
    int z = x;
    {
        int x = g(z);
        return x + 1;
    }
}

int main(void)
{
    printf("%d", f(0));
}
*/

// 2. Puntatori. (Variante A ‑ punti 4)
/*
int main(void)
{
    int a = 2;
    int *b = &a;
    int c[3] = {0, 1, 2};
    int *d = c;
    if (*(d + a) == c[a])
        *b = *c;
    c[*b] = *(c + *d + 1);
    int length = sizeof(c) / sizeof(c[0]);
    for (int i = 0; i < length; i++)
    {
        printf("%d", c[i]);
    }
}
*/

// 3. Array e Matrici. (Variante A ‑ punti 4)
/*
long mult_2nd_diag(int a[10][10]);
int main()
{
    int a[10][10];

    // Fill the matrix as a[i][j] = i + j + 1
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = i + j + 1;
        }
    }
    // Call the function to calculate the product of the secondary diagonal
    long result = mult_2nd_diag(a);
    printf("Product of the secondary diagonal: %ld\n", result);
    return 0;
}

long mult_2nd_diag(int a[10][10])
{
    long product = 1L; // Initialize product to 1
    for (int i = 0; i < 10; i++)
    {
        product *= a[i][9 - i]; // Access the secondary diagonal element
        printf("P: %ld\n", product);
    }
    return product;
}
*/

// 4. Loops. (Variante A ‑ punti 4)
/*
int main(void){
    int i = 0;
    while (i++ < 12)
    {S
        printf("%d", ++i);
    }
    return 0;
}
*/


//5. Tipi
