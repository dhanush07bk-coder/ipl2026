#include <stdio.h>

/* Union with bit fields */
union decision {
    unsigned char flags;

    struct field {
        int your_choice : 1;
        int your_mothers_choice : 1;
        int your_fathers_choice : 1;
        int socially_acceptable : 1;
        int financially_viable : 1;
        int do_you_have_aptitude : 1;
        int do_you_like_it : 1;
        int decision : 1;
    } f;
};

/* Function Prototypes */
union decision input();
void make_decision(union decision *d);
void print_decision(union decision d);
void print_conclusion_based_on_flags(union decision d);

int main() {
    union decision d;

    d = input();

    make_decision(&d);

    print_decision(d);

    print_conclusion_based_on_flags(d);

    return 0;
}

/* Input function */
union decision input() {

    union decision d;
    int temp;

    printf("Enter your choice (1/0): ");
    scanf("%d", &temp);
    d.f.your_choice = temp;

    printf("Enter your mother's choice (1/0): ");
    scanf("%d", &temp);
    d.f.your_mothers_choice = temp;

    printf("Enter your father's choice (1/0): ");
    scanf("%d", &temp);
    d.f.your_fathers_choice = temp;

    printf("Is it socially acceptable? (1/0): ");
    scanf("%d", &temp);
    d.f.socially_acceptable = temp;

    printf("Is it financially viable? (1/0): ");
    scanf("%d", &temp);
    d.f.financially_viable = temp;

    printf("Do you have aptitude? (1/0): ");
    scanf("%d", &temp);
    d.f.do_you_have_aptitude = temp;

    printf("Do you like it? (1/0): ");
    scanf("%d", &temp);
    d.f.do_you_like_it = temp;

    d.f.decision = 0;

    return d;
}

/* Decision Logic */
void make_decision(union decision *d) {

    /* Decision expression */
    d->f.decision =
        (d->f.your_choice &&
         d->f.financially_viable &&
         d->f.do_you_have_aptitude &&
         d->f.do_you_like_it);

}

/* Print narrative */
void print_decision(union decision d) {

    printf("\n------ Decision Report ------\n");

    if (d.f.decision) {
        printf("You should go ahead with the decision.\n");
        printf("Reason: You like it, have aptitude, ");
        printf("and it is financially viable.\n");
    }
    else {
        printf("You should rethink the decision.\n");

        if (!d.f.financially_viable)
            printf("- Financial issues detected.\n");

        if (!d.f.do_you_have_aptitude)
            printf("- Aptitude mismatch.\n");

        if (!d.f.do_you_like_it)
            printf("- You are not genuinely interested.\n");
    }
}

/* Using flags */
void print_conclusion_based_on_flags(union decision d) {

    printf("\n------ Flags Interpretation ------\n");

    printf("Flags value = %u\n", d.flags);

    if (d.flags == 255)
        printf("Perfect alignment! Everything supports your decision.\n");

    else if (d.flags > 150)
        printf("Most conditions are positive. Good chance of success.\n");

    else if (d.flags > 50)
        printf("Mixed signals. Think carefully before proceeding.\n");

    else
        printf("Too many negative factors. Better reconsider.\n");
}