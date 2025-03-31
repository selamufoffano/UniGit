#include <stdio.h>
int main (void)
{
    // dato il numero di giorni indicare quanti anni, settimane
    int user_days, anni, settimane, giorni;
     printf("Insert n Days: ");
     scanf("%d", &user_days);
     
     // un anno sono 365 giorni
     // una settimana sono 7 giorni

     anni = user_days / 365;
     settimane = user_days / 7;
     giorni = user_days;
      printf("years: %d, week: %d, days: %d \n", anni, settimane, giorni);

      return 0;
     
}