#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int create_feature(char name[20])
{
  char SUBFOLDERS[6][26] = {"bin","doc","src","test","lib","config"}; //creates the local variable containing an array of strings containing the name of the subfolders to be created
  char command[20] = "mkdir "; //creates the local variable command contains "mkdir "
  strcat(command, name); //concatenates the variable command and the parameter name and stores it in the the variable command
  system(command); //executes the contents of the variable command in the command line, creating a new directory with the name stored in the parameter
  sleep(1); //halts the program for 1 second to ensure the directory was created
  strcpy(command, "./");
  strcat(command, name);
  chdir(command);
  for(int i=0;i<6;i++) //for loop executes the following lines of code 6 times
  {
    strcpy(command, "mkdir "); //copies "mkdir " to the variable command
    strcat(command, SUBFOLDERS[i]); //concatenate the variable command with the string in the variable subfolders with the index i
    system(command); //executes the command in the commmand line, eventually creating 6 new subdirectories
  }
  return 0;
}
