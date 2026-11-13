#include <stdio.h>

int main()
{
    int n, i, isPrime = 1;
    int count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 2)
    {
        isPrime = 0;
    }
    else
    {
        for (i = 2; i <= n / i; i++)
        {
            count++;

            if (n % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime == 1)
        printf("%d is a Prime Number\n", n);
    else
        printf("%d is Not a Prime Number\n", n);

    printf("Number of divisions = %d\n", count);

    return 0;
}
