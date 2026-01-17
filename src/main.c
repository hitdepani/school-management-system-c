#include "../include/auth.h"
#include "../include/student.h"

int main()
{
    if(login())
    {
        menu();
    }
    
    else
    {
        printf("Access denied.\n");

    }
    
}
