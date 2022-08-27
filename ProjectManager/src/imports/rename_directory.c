#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rename_directory(char old_name[20], char new_name[20])
{
    char command[20] = "mv "; //creates local variable command with the contents "rename "
    char space[20] = " "; //creates local variable space containing a space
    strcat(space, new_name); //concatenates space and new_name, creating " new_name"
    strcat(command, old_name); //concatenates command and old_name, creating "rename old_name"
    strcat(command, space); //concatenates command and space, creating "rename old_name new_name"
    system(command); //executes the contents of command in the command line, renaming a directory with the name old_name to new_name
    return 0;
}
