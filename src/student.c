#include "../include/student.h"
#include "../include/logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addStudent()
{
    struct student s;
    int valid = 0;

    while (!valid)
    {
        printf("Enter roll number: ");
        scanf("%d", &s.roll);
        getchar();

        if (s.roll < 92000 || s.roll > 100000)
        {
            printf("Invalid roll range! Enter again.\n");
            continue;
        }

        FILE *fp = fopen("students.txt", "r");
        int duplicate = 0;

        if (fp != NULL)
        {
            char line[200];
            int r;
            float m;
            char n[50];

            while (fgets(line, sizeof(line), fp))
            {
                if (sscanf(line, "%d %f %[^\n]", &r, &m, n) == 3)
                {
                    if (r == s.roll)
                    {
                        duplicate = 1;
                        break;
                    }
                }
            }
            fclose(fp);
        }

        if (duplicate)
            printf("Roll number already exists! Try again.\n");
        else
            valid = 1;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    while (s.marks < 0 || s.marks > 100)
    {
        printf("Invalid marks! Enter again: ");
        scanf("%f", &s.marks);
    }

    FILE *fp = fopen("students.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening students file!\n");
        return;
    }

    fprintf(fp, "%d %.2f %s\n", s.roll, s.marks, s.name);
    fclose(fp);

    char logbuf[80];
    sprintf(logbuf, "Roll %d added", s.roll);
    logAction("ADD_STUDENT", logbuf);

    printf("Student added successfully!\n");
}

void viewStudents()
{
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("No records found!\n");
        return;
    }

    printf("\nROLL        MARKS      NAME\n");
    printf("---------------------------------------------\n");

    char line[200];
    int r;
    float m;
    char n[50];
    int found = 0;

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d %f %[^\n]", &r, &m, n) == 3)
        {
            found = 1;
            printf("%d     %-10.2f   %s\n", r, m, n);
        }
    }

    if (!found)
        printf("No students available.\n");

    fclose(fp);
}

void searchStudent()
{
    int roll;
    printf("Enter roll to search: ");
    scanf("%d", &roll);

    FILE *fp = fopen("students.txt", "r");
    if (!fp)
    {
        printf("File not found!\n");
        return;
    }

    char line[200];
    int r;
    float m;
    char n[50];
    int found = 0;

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d %f %[^\n]", &r, &m, n) == 3)
        {
            if (r == roll)
            {
                found = 1;
                printf("\nRecord found:\n");
                printf("Roll : %d\n", r);
                printf("Name : %s\n", n);
                printf("Marks: %.2f\n", m);
                break;
            }
        }
    }

    if (!found)
        printf("Student not found!\n");

    fclose(fp);
}

void updateStudent()
{
    int roll;
    printf("Enter roll to update: ");
    scanf("%d", &roll);
    getchar();

    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp)
    {
        printf("File error!\n");
        return;
    }

    char line[200];
    int r;
    float m;
    char n[50];
    int found = 0;

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d %f %[^\n]", &r, &m, n) == 3)
        {
            if (r == roll)
            {
                found = 1;
                printf("Enter new name: ");
                scanf(" %[^\n]", n);

                printf("Enter new marks: ");
                scanf("%f", &m);
            }
            fprintf(temp, "%d %.2f %s\n", r, m, n);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
    {
        char logbuf[80];
        sprintf(logbuf, "Roll %d updated", roll);
        logAction("UPDATE_STUDENT", logbuf);
        printf("Record updated successfully!\n");
    }
    else
        printf("Student not found!\n");
}

void deleteStudent()
{
    int roll;
    printf("Enter roll to delete: ");
    scanf("%d", &roll);

    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp)
    {
        printf("File error!\n");
        return;
    }

    char line[200];
    int r;
    float m;
    char n[50];
    int found = 0;

    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d %f %[^\n]", &r, &m, n) == 3)
        {
            if (r == roll)
            {
                found = 1;
                continue;
            }
            fprintf(temp, "%d %.2f %s\n", r, m, n);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
    {
        char logbuf[80];
        sprintf(logbuf, "Roll %d deleted", roll);
        logAction("DELETE_STUDENT", logbuf);
        printf("Record deleted successfully!\n");
    }
    else
        printf("Student not found!\n");
}
