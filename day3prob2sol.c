#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int marks;
} Student;

int main() {
    int numStudents;

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for the student records using malloc
    Student* students = (Student*)malloc(numStudents * sizeof(Student));

    // Check if memory allocation was successful
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Indicate an error
    }

    // Input student details
    for (int i = 0; i < numStudents; i++) {
        printf("Enter Student %d Name: ", i + 1);
        scanf(" %[^\n]s", students[i].name); // Read name with spaces

        printf("Enter Marks: ");
        scanf("%d", &students[i].marks);
    }

    // Output student details
    printf("\nStudent Records:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }


    // Free the dynamically allocated memory using free
    free(students);
    students = NULL; // Good practice: set the pointer to NULL after freeing

    return 0; // Indicate successful execution
}
