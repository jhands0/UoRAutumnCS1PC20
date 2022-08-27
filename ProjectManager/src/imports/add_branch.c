#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int add_branch(char name[20])
{
    char command[20] = "git branch "; //local variable command created to hold the command to be executed via system()
    char y_or_n[2]; //local variable y_or_no created to store user input
    strcat(command, name); //concatenates the contents of command and the parameter name containing the name of the branch to be created
    system(command); //executes the new value stored in command, creating a new branch with the name requested
    printf("Created new branch, would you like to switch to it? (Y/N): "); //print statement for user feedback
    scanf("%s", y_or_n); //scanf used to take user input and store it in variable y_or_n
    if (strcmp(y_or_n, "Y") == 0) //if statement checks to see if the user has inputted "Y"
    {
        strcpy(command, "git switch "); //variable command changed to "git switch "
        strcat(command, name); //command is concatenated again to include the name of the branch created
        system(command); //executes the value stored in command, switching to the new branch as requested
        return 0;
    }
    if (strcmp(y_or_n, "N") == 0) //if statement checks to see if the user has inputted "N"
    {
        printf("Exiting");
        return 0;
    }
}
