#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

  if (false) {
    float A[] = {1.0f, 2.0f, 0.0f, 0.0f, 5.0f};
    float B[] = {2.0f, 1.0f, 3.0f, 0.0f, 1.0f};

    float sum = 0.0f;
    for (int i = 0; i < 5; i++)
      sum += A[i] * B[i];
    printf("%f \n", sum);
  }

  if (false) {
    float btc[7] = {1000, 2000, 3000, 4000, 5000, 6000, 7000};
    // CALCOLA LA MEDIA DEI VALORI IN BTC
    float partial_sum = 0.0;
    for (int i = 0; i < 7; i++)
      partial_sum += btc[i];
    float avg = partial_sum / 7.0;
    printf(" %f \n", avg);
  }

  return 0;
}
