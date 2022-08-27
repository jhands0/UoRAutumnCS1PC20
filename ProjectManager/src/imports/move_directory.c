#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int move_directory(char old_location[20], char new_location[20]) //parameter old_location is the name of the old location of the directory, parameter new_location is the name of the new location of the directory
{
    char command[20] = "mv "; //creates local variable command containing "mv "
    char space[20] = " "; //creates local variable space containg a space
    strcat(space, new_location); //concatenates the variable space with the parameter new_location, creating " new_location"
    strcat(command, old_location); //concatenates the variable command with parameter old_location, creating "mv old_location"
    strcat(command, space); //concatenates the variable command with the variable space, creating "mv old_location new_location"
    system(command); //executes the value of the variable command in the command line, moving the directory named old_location to the new location called new_location
    return 0;
}
