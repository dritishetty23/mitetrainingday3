#include <stdio.h>

void displayAges(short int* ages, int length, int index) {
    if (index >= length) {
        return;
    }
    printf("%d ", ages[index]); // Corrected: ages[index]
    displayAges(ages, length, index + 1);
}

int main() {
    short int ages[] = {45, 42, 14, 28, 70};
    displayAges(ages, 5, 0);
    return 0;
}
