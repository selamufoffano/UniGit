#include <stdio.h>

int main(void) {
  int a = 10, b = 20;
  // Scambia i valori di a e b
  int aux;
  aux = a;
  a = b;
  b = aux;
  printf("%d\n", a); 
  printf("%d\n", b); 

  /* Dati 3 interi corrispondenti a ore, minuti e secondi, visualizzare il numero di secondi trascorsi dall’inizio della giornata */
  /*
  int ore = 11, minuti = 49, secondi = 33;
  int tot_secondi;
  tot_secondi = ore*60*60 + minuti*60 + secondi;
  printf("%d\n", tot_secondi); // printf a int
  */

  
  /* Calcolare la circonferenza di un cerchio dato il suo raggio */
  /*
  float raggio = 10.0f;
  float pi = 3.1415927f;
  float circ = 2.0f * pi * raggio;
  printf("%f\n", circ); // printf a float
  */
  return 0;
}
