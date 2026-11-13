#include <stdio.h>



char grade_if(int marks)
{
    if (marks < 0 || marks > 100)
        return '?';

    if (marks >= 90)
        return 'S';
    else if (marks >= 80)
        return 'A';
    else if (marks >= 70)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if (marks >= 50)
        return 'D';
    else
        return 'F';
}



char grade_switch(int marks)
{
    if (marks < 0 || marks > 100)
        return '?';

    switch (marks / 10)
    {
        case 10:
        case 9:
            return 'S';

        case 8:
            return 'A';

        case 7:
            return 'B';

        case 6:
            return 'C';

        case 5:
            return 'D';

        default:
            return 'F';
    }
}



void scholarship(char g, int income)
{
    if (g == '?')
    {
        printf("Invalid Marks\n");
    }
    else if (g == 'S' || g == 'A')
    {
        if (income <= 200000)
            printf("Scholarship Eligible\n");
        else
            printf("Not Eligible\n");
    }
    else
    {
        printf("Not Eligible\n");
    }
}

int main()
{
    int marks, income;

    int test[] = {100, 90, 89, 0, -1, 101};

    printf("UNIVERSITY GRADE CLASSIFICATION\n");

    printf("\nELSE-IF LADDER\n");

    for (int i = 0; i < 6; i++)
    {
        printf("%d : %c\n", test[i], grade_if(test[i]));
    }

    printf("\nSWITCH STATEMENT\n");

    for (int i = 0; i < 6; i++)
    {
        printf("%d : %c\n", test[i], grade_switch(test[i]));
    }

    printf("\nSCHOLARSHIP CLASSIFICATION\n");

    printf("Enter marks: ");
    scanf("%d", &marks);

    printf("Enter annual family income: ");
    scanf("%d", &income);

    printf("Grade: %c\n", grade_switch(marks));

    scholarship(grade_switch(marks), income);

    return 0;
}
