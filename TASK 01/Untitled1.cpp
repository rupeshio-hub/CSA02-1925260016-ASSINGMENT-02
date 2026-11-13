#include <stdio.h>

int main()
{
    int price, qty, senior;
    int count = 0;

    int gross;
    int total, net;

    double discount, tax;
    double correct_total, correct_net;

    printf("PHARMACY BILLING SYSTEM\n");

    for (int i = 1; i <= 3; i++)
    {
        printf("\nEnter Bill %d Details\n", i);

        printf("Enter price: ");
        scanf("%d", &price);

        printf("Enter quantity: ");
        scanf("%d", &qty);

        printf("Senior Citizen (1-Yes, 0-No): ");
        scanf("%d", &senior);

        gross = price * qty;

        
        total = price * qty
              - price * qty * 15 / 100 * senior
              + price * qty * 5 / 100;

        net = total > 1000 ? total - 50 : total;

        
        discount = senior ? gross * 0.15 : 0;
        tax = gross * 0.05;

        correct_total = gross - discount + tax;

        correct_net = correct_total > 1000
                    ? correct_total - 50
                    : correct_total;

        printf("\nOriginal Total = %d", total);
        printf("\nOriginal Net = %d", net);

        printf("\nCorrect Total = %.2f", correct_total);
        printf("\nCorrect Net = %.2f\n", correct_net);

        count++;
    }

    printf("\nTotal Bills Processed = %d\n", count);

    return 0;
}
