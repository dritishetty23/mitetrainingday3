#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isspace()

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int marks;
} Student;

// Function to safely read a string (preventing buffer overflows)
int read_string(char *buffer, int max_length) {
    if (fgets(buffer, max_length, stdin) == NULL) {
        return 0; // Error reading string
    }
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    return 1; // Success
}

// Function to safely read an integer (with input validation)
int read_int(int *value) {
    if (scanf("%d", value) != 1) {
        // Clear the input buffer in case of invalid input
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return 0; // Error reading integer
    }
    return 1; // Success
}



int main() {
    int numStudents;

    printf("Enter number of students: ");
    if (!read_int(&numStudents) || numStudents <= 0) {
        fprintf(stderr, "Invalid input for number of students.\n");
        return 1;
    }

    Student* students = (Student*)malloc(numStudents * sizeof(Student));

    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Enter Student %d Name: ", i + 1);
        if (!read_string(students[i].name, MAX_NAME_LENGTH)) {
            fprintf(stderr, "Error reading name.\n");
            free(students);
            return 1;
        }

        printf("Enter Marks: ");
        if (!read_int(&students[i].marks)) {
            fprintf(stderr, "Invalid input for marks.\n");
            free(students);
            return 1;
        }
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }

    free(students);
    students = NULL;

    return 0;
}
