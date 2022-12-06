/*
2213804
motiejus.sveikauskas@mif.stud.vu.lt
1 uzduotis
7 variantas
*/
#include <ctype.h>
#include <stdio.h>

int main() {
    int G;

    int sequence;
    int sequence_n = 0;
    int sequence_positive_n = 0;
    int sequence_negative_n = 0;
    int sequence_negative_sum = 0;
    int sequence_negative_multiplication = 1;

    printf("Enter integer G: ");

    while ((scanf("%d", &G) != 1) || (getchar() != '\n')) {
        printf("Invalid input! Enter integer G: ");
        while (getchar() != '\n') {
            ;
        }
    }
    printf("You entered: %d\n", G);

    // Writing and processing data
    while (sequence != G) {
        printf("Enter an integer: ");
        while ((scanf("%d", &sequence) != 1) || (getchar() != '\n')) {
            printf("Invalid input! Enter an integer: ");
            while (getchar() != '\n') {
                ;
            }
        }
        if (sequence == G) {
            break;
        }
        sequence_n++;
        if (sequence > 0) {
            sequence_positive_n++;
        } else if (sequence < 0) {
            sequence_negative_n++;
            sequence_negative_sum += sequence;
            sequence_negative_multiplication *= sequence;
        }
    }

    // Output of processed data
    if (sequence_n == 0) {
        printf("Sequence is empty!");
    } else {
        printf("Sequence length: %d\n", sequence_n);
        printf("Amount of positive integers: %d\n", sequence_positive_n);
        printf("Sum of negative integers: %d\n", sequence_negative_sum);
        if (sequence_negative_n == 0) {
            printf("Multiplication of negative integers: There are no negative integers!");
        } else {
            printf("Multiplication of negative integers: %d", sequence_negative_multiplication);
        }
    }
    return 0;
}