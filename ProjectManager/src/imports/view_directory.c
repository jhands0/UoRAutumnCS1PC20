#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int view_directory(void)
{
  char command[20] = "ls -al"; //creates local variable command with the contents "ls -al"
  system(command); //executes the command "ls -al", outputting all the subdirectories and files in the current directory
  return 0;
}
