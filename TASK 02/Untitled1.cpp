#include <stdio.h>

#define N 1000

int senior_calls = 0;
int eligible_calls = 0;
int verify_calls = 0;

int audit_log[N];
int audit_count = 0;

typedef struct
{
    int id;
    int senior;
    int eligible;
    int disability;
} Passenger;

int check_senior(Passenger p)
{
    senior_calls++;
    return p.senior;
}

int check_eligible(Passenger p)
{
    eligible_calls++;
    return p.eligible;
}

int verify_card(Passenger p)
{
    verify_calls++;

    audit_log[audit_count++] = p.id;

    return p.disability;
}

void reset_counts()
{
    senior_calls = 0;
    eligible_calls = 0;
    verify_calls = 0;
    audit_count = 0;
}

int main()
{
    Passenger p[N];
    int i;
    int result;
    int granted;

   

    for (i = 0; i < N; i++)
    {
        p[i].id = i + 1;
        p[i].senior = (i % 4 == 0);
        p[i].eligible = (i % 5 != 0);
        p[i].disability = (i % 10 == 0);
    }

    printf("RAILWAY CONCESSION SYSTEM\n");

    

    reset_counts();
    granted = 0;

    for (i = 0; i < N; i++)
    {
        result = (check_senior(p[i]) &&
                  check_eligible(p[i])) ||
                  verify_card(p[i]);

        if (result)
            granted++;
    }

    printf("\nMETHOD 1: Senior condition first\n");
    printf("Concessions = %d\n", granted);
    printf("Senior calls = %d\n", senior_calls);
    printf("Eligible calls = %d\n", eligible_calls);
    printf("Verification calls = %d\n", verify_calls);
    printf("Audit records = %d\n", audit_count);

    

    reset_counts();
    granted = 0;

    for (i = 0; i < N; i++)
    {
        result = verify_card(p[i]) ||
                 (check_senior(p[i]) &&
                  check_eligible(p[i]));

        if (result)
            granted++;
    }

    printf("\nMETHOD 2: Verification first\n");
    printf("Concessions = %d\n", granted);
    printf("Senior calls = %d\n", senior_calls);
    printf("Eligible calls = %d\n", eligible_calls);
    printf("Verification calls = %d\n", verify_calls);
    printf("Audit records = %d\n", audit_count);

    

    reset_counts();
    granted = 0;

    for (i = 0; i < N; i++)
    {
        result = (check_senior(p[i]) &
                  check_eligible(p[i])) |
                  verify_card(p[i]);

        if (result)
            granted++;
    }

    printf("\nMETHOD 3: Bitwise operators\n");
    printf("Concessions = %d\n", granted);
    printf("Senior calls = %d\n", senior_calls);
    printf("Eligible calls = %d\n", eligible_calls);
    printf("Verification calls = %d\n", verify_calls);
    printf("Audit records = %d\n", audit_count);

    return 0;
}
