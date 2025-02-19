#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit()

#define MAX_NAME_LENGTH 255

struct Student {
    char name[MAX_NAME_LENGTH];
    int marks;
};

typedef struct Student Student_t;

// Safe string reading function
int read_string(char *buffer, int max_length) {
    if (fgets(buffer, max_length, stdin) == NULL) {
        return 0; // Error reading string
    }
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    return 1; // Success
}

// Safe integer reading function
int read_int(int *value) {
    if (scanf("%d", value) != 1) {
        // Clear the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return 0; // Error reading integer
    }
    return 1; // Success
}


void readStudents(Student_t* students, int length) {
    for (int i = 0; i < length; i++) {
        printf("Student %d Name: ", i + 1);
        if (!read_string(students[i].name, MAX_NAME_LENGTH)) {
            fprintf(stderr, "Error reading name.\n");
            exit(1); // Or handle the error as needed
        }

        printf("Student marks: ");
        if (!read_int(&students[i].marks)) {
            fprintf(stderr, "Invalid input for marks.\n");
            exit(1); // Or handle the error as needed
        }
    }
}

void printStudents(Student_t* students, int length) {
    printf("Student Records: \n");
    for (int i = 0; i < length; i++) {
        printf("%s %d\n", students[i].name, students[i].marks);
    }
}

int main() {
    Student_t students[1000];
    int studentsCount;

    printf("Enter number of students: ");
    if (!read_int(&studentsCount) || studentsCount <= 0 || studentsCount > 1000) {
        fprintf(stderr, "Invalid number of students.\n");
        return 1;
    }

    readStudents(students, studentsCount);
    printStudents(students, studentsCount);

    return 0;
}
