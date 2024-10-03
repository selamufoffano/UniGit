#include <stdio.h>
void sommaFun();
void convertBin();
int main(void)
{
    convertBin();
}

void sommaFun()
{
    // Verificare se l’espressione (0.1+0.1+0.1)==0.3 è vera.
    float somma = 0.1 + 0.1 + 0.1;
    if (somma == 0.3f)
    {
        printf("Vero");
    }
    else
    {
        printf("False");
    }
    /*
    // in Questo caso il codice restituisce Vero.
    // Confronto un float (varibaile somma) con un valore 0.3f (che questo caso è di tipo float)
    if(somma == 0.3f){
        printf("Vero");
    }else{
        printf("False");
    }
    return 0;
    */
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// L’assegnamento è un’espressione, qual è il suo valore?
// L'operazione di assegnamento consente di asegnare un certo valore ad una varibaile precedentemente dichiarata
void assegnamento()
{
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ES: Date le lunghezze di tre segmenti, dire se questi possono formare un triangolo.
/*
La proprietà fondamentale dei lati di un triangolo dice che:"In un triangolo ogni lato è minore della somma degli altri due".
Tale proprietà (che può essere dimostrata razionalmente) può essere giustificata intuitivamente anche
nel seguente modo:"il percorso più breve che unisce due vertici di un triangolo( e più in generale due punti qualsiasi)
è costituito dal segmento che li unisce" .
Tale proprietà può essere usata per stabilire se è possibile costruire un triangolo con tre segmenti assegnati.
In pratica basta verificare se :"il segmento maggiore è minore della somma degli altri
due"(infatti per i due segmenti minori la relazione è automaticamente verificata).
Tanto premesso stabilisci se in ciascuno dei seguenti casi è possibile costruire un triangolo:
 */
float triangolo(float a, float b, float c)
{
    // trovo il segmento maggiore e faccio il confronto
    // OPPURE verifico che non ci sia nessun segmento maggiore della somma di due segmenti, (la somma dei due segmenti deve essere minore del segmento maggiore)
    if (a < b + c && b < a + c && c < a + b)
        printf("esiste");
    else
        printf("non esiste");

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Date le lunghezze di tre segmenti, dire se questi possono formare un triangolo rettangolo.
// devo trovare prima l'ipotenusa

// Il cateto maggiore è la ipotenusa, devo trovare il cateto maggiore
void triangoloRettangolo()
{
    int a, b, c;

    if (a > b && a > c)
    {
        if (a * a == b * b + c * c)
        {
            printf("Esiste");
        }
        else
        {
            printf("Non esiste");
        }
    }
    else if (b > a && b > c)
    {
        if (b * b == a * a + c * c)
        {
            printf("Esiste");
        }
        else
        {
            printf("Non esiste");
        }
    }
    else
    {
        if (c * c == a * a + b * b)
        {
            printf("Esiste");
        }
        else
        {
            printf("Non esiste");
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Dato in input un numero intero <=255, visualizzare la sua rappresentazione binaria
// ci sono due modi di risolvere il problema. sottrazione e divisione della potenza massima

void convertBin()
{
    int num = 8;
    while (num != 0)
    {
        if (num % 2 == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        num = num/2;
    }
}
