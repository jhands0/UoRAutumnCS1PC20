#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int create_directory(char name[20])
{
  char command[20] = "mkdir "; //local variable command created with the contents "mkdir "
  strcat(command, name); //concatenates the command variable with the parameter name
  system(command); //executes the concatenated variable command which creates a new directory
  sleep(1); //halts the program for 1 second to ensure that the directory the program will be changing to exists
  strcpy(command, "cd "); //copies "cd " to the variable command
  strcat(command, name); //concatenates the command variable with the parameter name
  system(command); //executes the concatenated variable command, changing the directory to the directory created
  strcpy(command, "git init "); //copies "git init " to the variable command
  strcat(command, name); //concatenates the command variable with parameter name
  system(command); //executes the concatenated command variable the parameter name
  return 0;
}
