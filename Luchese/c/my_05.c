#include <stdio.h>
#include <math.h>

int main(void) {
    float a, b, c;
    printf("Inserisci a: "); scanf("%f", &a);
    printf("Inserisci b: "); scanf("%f", &b);
    printf("Inserisci c: "); scanf("%f", &c);

    float delta = b * b - 4 * a * c;
    if (delta < 0) {
        printf("Non ci sono soluzioni reali (delta < 0).\n");
    } else {
        float sol1 = (-b + sqrt(delta)) / (2 * a);
        float sol2 = (-b - sqrt(delta)) / (2 * a);
        printf("Soluzione 1: %.2f\n", sol1);
        printf("Soluzione 2: %.2f\n", sol2);
    }
    
    return 0;
}
