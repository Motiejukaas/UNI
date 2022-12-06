/*
2213804
motiejus.sveikauskas@mif.stud.vu.lt
2 uzduotis
4 variantas
*/

/*Įvesti sveiką skaičių N. Įvesti N sveikų skaičių.
Tarp įvestų skaičių rasti ir išvesti du skaičius artimiausius įvestų skaičių vidurkiui:
vieną mažesnį už vidurkį, o kitą - didesnį.
*/
#include <ctype.h>
#include <stdio.h>

int validateInt(void) {
    int x;
    while ((scanf("%d", &x) != 1) || (getchar() != '\n')) {
        printf("Entered data is not an integer! Enter an integer: ");
        while (getchar() != '\n') {
            ;
        }
    }
    return x;
}

int findNearestIntBelowAvg(int array[], double avg, int N) {
    int x_below = array[0];
    for (int i = 0; i < N; ++i) {
        if (array[i] < x_below) {
            x_below = array[i];
        }
    }
    for (int i = 0; i < N; ++i) {
        if (array[i] < avg && array[i] > x_below) {
            x_below = array[i];
        }
    }
    return x_below;
}

int findNearestIntAboveAvg(int array[], double avg, int N) {
    int x_above = array[0];
    for (int i = 0; i < N; ++i) {
        if (array[i] > x_above) {
            x_above = array[i];
        }
    }
    for (int i = 0; i < N; ++i) {
        if (array[i] > avg && array[i] < x_above) {
            x_above = array[i];
        }
    }
    return x_above;
}

int main() {
    int N;
    double avg = 0;  // average of the entered sequence
    int below_avg, above_avg;

    // N input and validation
    printf("Enter whole number N: ");
    do {
        N = validateInt();
        if (N >= 0) break;
        printf("Entered number is not whole! Enter a whole number: ");
    } while (N < 0);
    printf("N entered successfully!\n");

    // array input and validation
    int array[N];  // array of N amount of whole numbers

    for (int i = 0; i < N; ++i) {
        printf("Enter integer %d: ", i + 1);
        array[i] = validateInt();
        avg += array[i];
    }

    avg /= N;

    // data output or error message if sequence is empty
    if (N == 0) {
        printf("Sequence is empty!\n");
    } else {
        below_avg = findNearestIntBelowAvg(array, avg, N);
        above_avg = findNearestIntAboveAvg(array, avg, N);
        printf("Number that is closest to and below the average is: %d\n", below_avg);
        printf("Number that is closest to and above the average is: %d\n", above_avg);
    }
    return 0;
}