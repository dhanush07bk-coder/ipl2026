#include <stdio.h>
#include <stdlib.h> 

struct Student
{
    int id;
    char name[30];
    float marks;
};

void writeRecords();
void getRecord(int m);
void deleteRecord(int delId);

int main()
{
    int choice, m, delId;

    while (1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Store Records\n");
        printf("2. Get Mth Record\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                writeRecords();
                break;

            case 2:
                printf("Enter record number to display: ");
                scanf("%d", &m);
                getRecord(m);
                break;

            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &delId);
                deleteRecord(delId);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


void writeRecords()
{
    FILE *fp;
    struct Student s;
    int n, i;

    fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        printf("File cannot be opened!\n");
        return;
    }

    printf("Enter number of records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &s.id);

        printf("Name: ");
        scanf("%s", s.name);

        printf("Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(struct Student), 1, fp);
    }

    fclose(fp);

    printf("\nRecords stored successfully.\n");
}


void getRecord(int m)
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    fseek(fp, (m - 1) * sizeof(struct Student), SEEK_SET);

    if (fread(&s, sizeof(struct Student), 1, fp) == 1)
    {
        printf("\nRecord %d Details:\n", m);
        printf("ID    : %d\n", s.id);
        printf("Name  : %s\n", s.name);
        printf("Marks : %.2f\n", s.marks);
    }
    else
    {
        printf("Record not found!\n");
    }

    fclose(fp);
}


void deleteRecord(int delId)
{
    FILE *fp, *temp;
    struct Student s;
    int found = 0;

    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp))
    {
        if (s.id == delId)
        {
            found = 1;
            continue;
        }

        fwrite(&s, sizeof(struct Student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found)
        printf("Record deleted successfully.\n");
    else
        printf("Record not found.\n");
}