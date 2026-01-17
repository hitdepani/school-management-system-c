#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

// data structure
struct student {
    int roll;
    char name[50];
    float marks;
};

// core operations
void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

// menu
void menu();

#endif
