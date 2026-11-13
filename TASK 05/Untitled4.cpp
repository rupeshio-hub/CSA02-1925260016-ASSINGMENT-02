#include <stdio.h>

unsigned long checks;



int prime_for_normal(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i < n; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}



int prime_for(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i <= n / i; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}



int prime_while(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    unsigned long i = 2;

    while (i <= n / i)
    {
        checks++;

        if (n % i == 0)
            return 0;

        i++;
    }

    return 1;
}



int prime_do(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    unsigned long i = 2;

    do
    {
        if (i > n / i)
            break;

        checks++;

        if (n % i == 0)
            return 0;

        i++;

    } while (1);

    return 1;
}

int main()
{
    unsigned long tickets[] =
    {
        97, 100, 7919, 1000003
    };

    int size = 4;

    printf("PRIME NUMBER CHECKING\n");

    printf("\nNORMAL FOR LOOP\n");

    for (int k = 0; k < size; k++)
    {
        int result = prime_for_normal(tickets[k]);

        printf("%lu - %s - Divisions = %lu\n",
               tickets[k],
               result ? "Prime" : "Not Prime",
               checks);
    }

    printf("\nIMPROVED FOR LOOP\n");

    for (int k = 0; k < size; k++)
    {
        int result = prime_for(tickets[k]);

        printf("%lu - %s - Divisions = %lu\n",
               tickets[k],
               result ? "Prime" : "Not Prime",
               checks);
    }

    printf("\nIMPROVED WHILE LOOP\n");

    for (int k = 0; k < size; k++)
    {
        int result = prime_while(tickets[k]);

        printf("%lu - %s - Divisions = %lu\n",
               tickets[k],
               result ? "Prime" : "Not Prime",
               checks);
    }

    printf("\nIMPROVED DO-WHILE LOOP\n");

    for (int k = 0; k < size; k++)
    {
        int result = prime_do(tickets[k]);

        printf("%lu - %s - Divisions = %lu\n",
               tickets[k],
               result ? "Prime" : "Not Prime",
               checks);
    }

    return 0;
}
