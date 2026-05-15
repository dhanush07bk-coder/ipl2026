#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure definition
typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

// Function to write array of structures to file in ASCII format
void writeToFile(const char *filename, Student s[], int n) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %f\n", s[i].id, s[i].name, s[i].marks);
    }

    fclose(fp);
}

// Function to store seek positions of each record
int createIndex(const char *filename, long pos[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file!\n");
        return 0;
    }

    int count = 0;

    while (!feof(fp)) {
        pos[count] = ftell(fp);   // store position
        int id;
        char name[50];
        float marks;

        if (fscanf(fp, "%d %s %f", &id, name, &marks) != 3)
            break;

        count++;
    }

    fclose(fp);
    return count;
}

// Function to display record at given position
void displayRecord(const char *filename, long position) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    fseek(fp, position, SEEK_SET);

    int id;
    char name[50];
    float marks;

    if (fscanf(fp, "%d %s %f", &id, name, &marks) == 3) {
        printf("Record:\n");
        printf("ID: %d\nName: %s\nMarks: %.2f\n", id, name, marks);
    } else {
        printf("Invalid position!\n");
    }

    fclose(fp);
}

// Main function
int main() {
    Student s[MAX];
    long pos[MAX];
    int n;

    printf("Enter number of records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Write to file
    writeToFile("students.txt", s, n);

    // Create index
    int total = createIndex("students.txt", pos);

    printf("\nStored %d record positions.\n", total);

    // Display records using stored positions
    int choice;
    printf("\nEnter record number to display (1 to %d): ", total);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= total) {
        displayRecord("students.txt", pos[choice - 1]);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}