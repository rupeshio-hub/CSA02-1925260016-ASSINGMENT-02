#include <stdio.h>

int main()
{
    double balance = 10000;
    double rate = 2;
    double repayment = 2000;

    double interest, payment, total_interest = 0;
    int month = 0;

    printf("LOAN REPAYMENT SCHEDULE\n");
    printf("-----------------------------------------\n");
    printf("Month\tInterest\tPayment\t\tBalance\n");
    printf("-----------------------------------------\n");

    while (balance > 0.005 && month < 360)
    {
        month++;

        interest = balance * rate / 100;
        balance = balance + interest;

        
        if (repayment <= interest)
        {
            printf("\nRepayment is insufficient.\n");
            printf("Loan cannot be cleared.\n");
            return 0;
        }

        payment = repayment;

        
        if (payment > balance)
        {
            payment = balance;
        }

        balance = balance - payment;
        total_interest = total_interest + interest;

        if (balance < 0.005)
        {
            balance = 0;
        }

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",
               month, interest, payment, balance);
    }

    printf("-----------------------------------------\n");

    if (balance == 0)
    {
        printf("Total Months       : %d\n", month);
        printf("Total Interest     : Rs. %.2f\n", total_interest);
        printf("Loan Status        : Fully Repaid\n");
    }
    else
    {
        printf("Loan not cleared within 360 months.\n");
    }

    return 0;
}
