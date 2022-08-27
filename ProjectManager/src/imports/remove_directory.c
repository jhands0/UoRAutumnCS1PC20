#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int remove_directory(char name[20])
{
  char command[20] = "rm -rf "; //creates the local variable command with the contents "rm -rf "
  strcat(command, name); //concatenates the variable command with the parameter name, creating "rm -rf name"
  system(command); //executes the value of command in the command line, deleting the directory with the name of the parameter name
  return 0;
}
