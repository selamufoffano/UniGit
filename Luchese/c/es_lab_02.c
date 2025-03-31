#include <stdio.h>

// Function to calculate the sum of divisors of n
int modulo(int n)
{
    int somma = 0;
    for (int i = 1; i <= n; i++) // Start loop from 1 to avoid division by zero
    {
        if (n % i == 0)
        {
            somma += i;
        }
    }
    return somma; // Return the sum of divisors
}

int main(void)
{
    int age;
    printf("Enter a number: ");
    int result = scanf("%d", &age);

    if (result != 1)  // Check if scanf successfully read a number
    {
        printf("Invalid input. Please enter a valid number.\n");
        return 1; // Exit with an error code
    }

    int somma = modulo(age);
    printf("The sum of divisors of %d is %d\n", age, somma);

    return 0;  // Return 0 to indicate successful execution
}
