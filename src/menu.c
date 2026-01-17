#include "../include/student.h"
#include "../include/auth.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void menu()
{
    int choice;

    while(1)
    {
        printf("\n-------------------------------------\n");
        printf("   STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("-------------------------------------\n");

        if(strcmp(currentRole,"VIEW")==0)
        {
            printf("1. View All Students\n");
            printf("2. Search Student\n");
            printf("3. Exit\n");
            printf("Enter choice: ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1: viewStudents(); break;
                case 2: searchStudent(); break;
                case 3: exit(0);
                default: printf("Invalid choice\n");
            }
        }
        else   // ADMIN
        {
            printf("1. Add Student\n");
            printf("2. View All Students\n");
            printf("3. Search Student\n");
            printf("4. Update Student\n");
            printf("5. Delete Student\n");
            printf("6. Exit\n");
            printf("Enter choice: ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1: addStudent(); break;
                case 2: viewStudents(); break;
                case 3: searchStudent(); break;
                case 4: updateStudent(); break;
                case 5: deleteStudent(); break;
                case 6: exit(0);
                default: printf("Invalid choice\n");
            }
        }
    }
}
