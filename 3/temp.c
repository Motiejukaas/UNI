/*
Parašyti funkciją, kuri randa ir atspausdina visus žodžius, kurie vienodai skaitomi iš pradžios ir iš galo.
*/

/*
2213804
motiejus.sveikauskas@mif.stud.vu.lt
3 uzduotis
2 variantas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *create_file(char open_type[], char io_msg[], char error_msg[]) {
    char filename[100];
    printf("%s", io_msg);
    scanf("%s", &filename);
    FILE *ioFile;
    ioFile = fopen(filename, open_type);
    while (ioFile == NULL) {
        printf("%s", error_msg);
        scanf("%s", &filename);
        ioFile = fopen(filename, open_type);
    }
    return ioFile;
}

void *findPalindrome(FILE *inFile, char ***palindrome_array, int *palindrome_count) {
    while (!feof(inFile)) {
        char line[255];

        // fgets 255 characters (or less if encountered \n or EOF) from inFile into char line[255]
        while (fgets(line, 256, inFile) == NULL) {
            inFile = create_file("r", "Opened file is empty! Enter input file name: ", "File not found or unable to open file! Enter input file name: ");
        }
        printf("[[%s]]", line);

        // checks if there is \n character anywhere in line
        if (strchr(line, '\n') == NULL) {
            // if \n is not found fgets and deletes remaining data in file's line
            char del[1024];
            printf("nerado newline\n");
            fgets(del, 1024, inFile);  // notepad max characters per line is 1024
            *del = 0;
        } else {
            printf("rado newline\n");
            line[strcspn(line, "\n")] = 0;  // removes newline char from string line, if it is found
        }

        const char s[2] = " ";
        char *string;

        string = strtok(line, s);  // breaks line into a series of tokens using delimiter: " " (whitespace)

        while (string != NULL) {
            printf("\n[%s]", string);

            // checking if string is a palindrome and flagging accordingly
            int palindrome_flag = 1;
            int b = 0, e = strlen(string) - 1;
            while (e > b) {
                if (string[b++] != string[e--]) {
                    palindrome_flag = 0;
                    break;
                }
            }

            // if string is flagged as palindrome (1), string is written into palindrome_array
            if (palindrome_flag == 1) {
                *palindrome_array = (char **)realloc(*palindrome_array, ++(*palindrome_count) * sizeof(char *));  // memory allocation for 1 more char array
                (*palindrome_array)[*palindrome_count - 1] = (char *)calloc(strlen(string) + 1, sizeof(char));    // memory allocation for char array of strlen(string) + 1 size
                if ((*palindrome_array)[*palindrome_count - 1] == NULL) {
                    printf("Memory not allocated.\n");
                    exit(0);
                }
                strncpy((*palindrome_array)[*palindrome_count - 1], string, strlen(string) + 1);
                printf(" String entered into array: [%s]", (*palindrome_array)[*palindrome_count - 1]);
            }
            string = strtok(NULL, s);
        }
    }
}

int main() {
    // input of input file name
    FILE *inFile = create_file("r", "Enter input file name: ", "File not found or unable to open file! Enter input file name: ");

    int palindrome_count = 0;
    char **palindrome_array = (char **)calloc(palindrome_count, sizeof(char *));
    if (palindrome_array == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    findPalindrome(inFile, &palindrome_array, &palindrome_count);
    printf("\nNumber of palindromes: %d\n", palindrome_count);

    fclose(inFile);

    // input of output file name
    FILE *outFile = create_file("w", "Enter output file name: ", "Unable to create file! Enter output file name: ");

    // data output
    for (int i = 0; i < palindrome_count; ++i) {
        fprintf(outFile, "%s\n", palindrome_array[i]);
        printf("[%s]\n", palindrome_array[i]);
    }

    // memory freeing
    for (int i = 0; i < palindrome_count; ++i) {
        free(palindrome_array[i]);
    }
    free(palindrome_array);

    fclose(outFile);
    return 0;
}