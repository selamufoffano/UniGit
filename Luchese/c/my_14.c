#include <stdio.h>
#include <string.h>

// array con i puntatori
void print_array(int *a_begin, int *a_end)
{
    printf("[");
    while (a_begin != a_end)
    {
        printf(" %d", *(a_begin));
        a_begin++;
    }
    printf(" ]\n");
}

// date due stringhe a e b,
// dire quante volte a occorre in b
// anche con sovrapposizioni
// ed. "abab" 3 volte in "ababxabababx"
//                        ^    ^ ^
// es: "abab" 6 volte in "ababxabababxabxabaxababab"

int letterCounter_V0(const char *a, const char *b)
{
    int counter = 0;
    int valid = 0;
    for (int i = 0; i < strlen(b); i++)
    {
        // printf("index b: %d\n", i);
        for (int j = 0; j < strlen(a); j++)
        {
            // printf("--> index a: %d\n", j);
            if (a[j] == b[j])
            {
                valid++;
            }
            if (valid == strlen(a))
            {
                counter++;
            }
        }
    }
    return counter;
}
int letterCounter_V1(const char *a, const char *b)
{
    int counter = 0;
    int a_len = strlen(a);
    int b_len = strlen(b);

    for (int i = 0; i <= b_len - a_len; i++)
    {
        int match = 1; // Flag per verificare la corrispondenza
        for (int j = 0; j < a_len; j++)
        {
            if (a[j] != b[i + j])
            {
                match = 0; // Non c'è corrispondenza
                break;
            }
        }
        if (match)
        {
            counter++;
        }
    }
    return counter;
}

int letterCounter(const char *a, const char *b)
{
    int count = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);

    for (int i = 0; i <= len_b - len_a; i++)
    {
        // Confronta la sottostringa di lunghezza len_a con a
        if (strncmp(&b[i], a, len_a) == 0)
        {
            count++;
        }
    }
    return count;
}

// data una stringa, restituire una nuova stringa
// dopo aver eleminato tutto quello che non è
// racchiuso tra parentesi
// es.  "(I ) do not (Love ) wasting my time at (Coding) badly" => "I Love Coding"
// non ci sono parentesi annidate, e sono sempre corrette


//arrayStatico
char arr()
{
    char str[100];
    // inizializzo la
    str[0] = '\0';
    int count = 0;
    for (char c = 'C'; c <= 'H'; c++)
    {
        str[count] = c;
        count++;
        str[count] = '\0';
    }
    return str;
}


// scrivere un programma che data una stringa 
// salvi solo l'ultima occorenza
// es: "ggniigocc" --> "coging"

int main(void)
{
    /*
    int array[] = {5, 2, 3, 4, 5}; // Un array di esempio
    int size = sizeof(array) / sizeof(array[0]); // Calcolo della dimensione dell'array

    // Utilizzo della funzione print_array
    print_array(array, array+sizeof(array[0]));

    return 0;
    */
    const char *a = "abab";
    const char *b = "ababxabababxabxabaxababab";
    int result = letterCounter_V1(a, b);
    printf("Occorrenze di '%s' in '%s': %d\n", a, b, result);
    //return 0;
    // Dimensione di a in byte
    printf("Dimensione di a con sizeof: %lu\n", sizeof(a));
    // Lunghezza di a (escluso il terminatore null)
    printf("Lunghezza di a con strlen: %lu\n", strlen(a));

    // printf("%lu", a[0]);
    /*int result = letterCounter(a, b);
    printf("La stringa '%s' appare %d volte nella stringa '%s'\n", a, result, b);
    */

    
    char res = arr();
    printf("%s", res);
    return 0;
}
// ricorsivo e iterativo