#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "imports/create_directory.h"
#include "imports/create_feature.h"
#include "imports/remove_directory.h"
#include "imports/search_directories.h"
#include "imports/view_directory.h"
#include "imports/move_directory.h"
#include "imports/read_and_write.h"
#include "imports/add_branch.h"
#include "imports/rename_directory.h"

int ProjectManager(void)
{
  char choice[20]; //creates local variable choice
  char select[20]; //creates local variable select
  char name[20]; //creates local variable name
  char temp[20]; //creates local variable temp
  char command[40] = "./"; //creates local variable command with the contents "cd "
  char y_or_n[20]; //creates local variable y_or_n
  chdir("");
  sleep(1); //halts the program for 1 second, ensuring that the directory has been changed
  created = search_directory("Projects"); //searches for a directory with the name "Projects"
  if(created == 0) //if "Projects" was not created
  {
    system("mkdir Projects"); //the directory "Projects" is created
    sleep(1); //halts the program for 1 second to ensure the directory has been created
    chdir("./Projects");
  }
  if(created == 1) //checks to see if "Projects" was created
  {
    sleep(1); //halts the program for 1 second to ensure the directory has been created
    chdir("./Projects");
  }
  system("clear"); //clears the screen
  printf("Welcome to the Project Manager\n" );
  printf("\nFile Manager = FM \nExit = E \n\nWhat would you like to do: ");
  scanf("%s", choice); //takes a user input, storing the contents in variable choice
  while(strcmp(choice, "E") != 0) //while the variable choice is not equal to "E", the user will stay in the file manager
  {
    system("clear");
    printf("Welcome to the File Manager\n" );
    printf("\nCreate Project = CP \nCreate Feature = CF \nDelete Project = DP \nMove Project = MP \nRename Project = RP \nAdd Tags = AT \nAdd Branch = AB \nGenerate Tree = GT \nBack = B \n\nWhat would you like to do: ");
    scanf("%s", select); //takes a user input, storing the contents in variable select
    while(strcmp(select, "B") != 0) //while the variable choice is not equal to "B", the prompt will keep appearing as the user is still in the file manager
    {
      if(strcmp(select, "CP") == 0) //if statement used to check if the user input was equal to one of the options provided
      {
        system("clear");
        printf("Enter the chosen name of your project: ");
        scanf("%s", name); //takes a user input for name, storing the contents in variable name
        created = search_directory(name); //searches for a directory with the name requested to see if a directory of that name already exists
        if(created == 1) //variable created returns 1 if the project has been created
        {
          printf("This project already exists");
        }
        if(created == 0)
        {
          create_directory(name); //variable name is used as the input for the create_directory function, which creates a directory
          printf("\nMaking project\n" );
          view_directory();
        }
      }
      if(strcmp(select, "CF") == 0)
      {
        system("clear"); //clears the screen
        printf("Enter the chosen name of the project to put your feature in: ");
        scanf("%s", name); //takes a user input for the name, storing it in the variable name
        created = search_directory(name); //searches for a directory with the name requested
        if(created == 0)
        {
          printf("This project does not exist, would you like to create it (Y = Yes/ N = No): ");
          scanf("%s", y_or_n); //user input that is stored in variable y_or_n
          if(strcmp(y_or_n, "Y") == 0)
          {
            create_directory(name); //creates a new directory with the name chosen by the user
            printf("\nMaking project\n" );
            view_directory(); //outputs the subdirectories and files in "Projects", showing that the new directory has been created
          }
          if(strcmp(y_or_n, "N") == 0)
          {
            return 0;
          }
        }
        if(created == 1)
        {
          sleep(1); //halts the program for 1 second to ensure the directory has been created
          strcat(command, name);
          chdir(command);
          sleep(1); //halts the program for 1 second to ensure the directory has been changed
          printf("Enter the chosen name of your feature: ");
          scanf("%s", name); //user input that is stored in variable name
          created = search_directory(name); //searches for a directory with the name requested
          if(created == 0)
          {
            create_feature(name); //creates a directory of the requeted name with subdirectories
            printf("\nMaking Feature\n" );
            view_directory(); //outputs the subdirectories and files in "Projects", showing that the new directory has been created
          }
          if(created == 1)
          {
            printf("This feature already exists");
          }
        }
      }
      if(strcmp(select, "DP") == 0)
      {
        system("clear"); //clears the screen
        printf("Enter the name of the project you would like to remove: ");
        scanf("%s", name); //takes a user input and stores it in the variable name
        created = search_directory(name); //searches to see if the directory with the inputted name exists
        if(created == 1)
        {
          remove_directory(name); //removes the directory with the chosen name
          printf("\nRemoving Project/Feature\n" );
          view_directory(); //outputs the subdirectories and files in "Projects", showing that the directory has been removed
        }
        if(created == 0)
        {
          printf("This project/feature does not exist");
        }
      }
      if(strcmp(select, "MP") == 0)
      {
        char temp[20]; //creates local variable temp
        system("clear"); //clears the screen
        printf("Enter the name of project/feature you would like to move: ");
        scanf("%s", name); //takes a user input, storing it in the variable name
        created = search_directory(name); //searches the directory Projects for the directory inputted by the user
        if(created == 1)
        {
          strcpy(temp,name); //copies the name of the directory to be moved to a new variable called temp
          printf("Enter the name of the new location for the project/feature: ");
          scanf("%s", name); //takes a user input, storing it in the variable name
          created = search_directory(name); //searches the directory Projects for the directory inputted by the user
          if(created == 1)
          {
            move_directory(temp, name); //moves the directory from it's old location to the new location requested by the user
            printf("\nProject/feature moved");
            view_directory(); //outputs the changed file structure
          }
          if(created == 0)
          {
            printf("The new location for the project/feature does not exist");
          }
        }
      }
      if(strcmp(select, "RP") == 0)
      {
        char temp[20]; //creates a new variable called temp
        system("clear"); //clears the screen
        printf("Enter the name of project/feature you would like to rename: ");
        scanf("%s", name); //takes a user input and stores it in variable name
        created = search_directory(name); //searches the file structure for the inputted directory
        if(created == 1)
        {
          strcpy(temp,name); //copies the name of the chosen directory to the variable temp
          printf("Enter the new name for the project/feature: ");
          scanf("%s", name); //takes a user input and stores it in variable name
          created = search_directory(name); //searches the file structure for the inputted directory
          if(created == 0)
          {
            rename_directory(temp, name); //renames the chosen directory to the new name inputted
            printf("\nProject/feature renamed\n");
            view_directory(); //outputs the subdirectories and files in "Projects", showing that the directory has been renamed
          }
          if(created == 1)
          {
            printf("The new name for the project already exists elsewhere");
          }
        }
      }
      if(strcmp(select, "AT") == 0)
      {
        system("clear"); //clears the screen
        printf("Enter the name of the project you want to add tags to: ");
        scanf("%s", name); //takes a user input and stores it in the variable name
        created = search_directory(name); //searches the file structure for the inputted directory
        if(created == 1)
        {
          strcat(command, name);
          chdir(command); //changes the working directory to the requested directory
          sleep(1); //halts the program for 1 second to ensure the directory has been changed
          add_tags(); //adds tags to all subdirectories in the chosen project
          printf("\nAdded tags\n");
          view_directory(); //outputs the subdirectories and files in the project selected, showing all the tags that have been added
        }
        if(created == 0)
        {
          printf("This project does not exist, would you like to create it (Y = Yes/ N = No): ");
          scanf("%s", y_or_n); //takes a user input and stores it in the variable name
          if(strcmp(y_or_n, "Y") == 0)
          {
            create_directory(name); //creates a new directory of the chosen name 
            printf("\nMaking project\n" );
            view_directory(); //outputs the subdirectories and files in "Projects", showing that the new directory has been created
          }
          if(strcmp(y_or_n, "N") == 0)
          {
            return 0;
          }
        }
      }
      if(strcmp(select, "AB") == 0)
      {
        system("clear"); //clears the screen
        printf("Enter the name of the project you want to create a new branch for: ");
        scanf("%s", name);
        strcat(command, name);
        chdir(command);
        sleep(1);
        printf("Enter the name of the new branch you want to create: ");
        scanf("%s", name); //takes a user input and stores it in the variable name
        add_branch(name); //creates a new brnach with the chosen name
        printf("Added new branch");
      }
      if(strcmp(select, "GT") == 0)
      {
        system("clear"); //clears the screen
        printf("Enter the name of the project you want to be at the top of the tree: ");
        scanf("%s", name); //takes a user input and stores it in the variable name
        created = search_directory(name); //searches to see if the directory chosen to be at the top of the tree exists
        if(created == 1)
        {
          generate_tree(name); //generates a text file called name.txt and a picture of the tree structure in the chosen directory
          printf("\nGenerated Tree\n");
          view_directory(); //outputs the subdirectories and files in "Projects", showing that the new files have been created
        }
        if(created == 0)
        {
          printf("This project does not exist, would you like to create it (Y = Yes/ N = No): ");
          scanf("%s", y_or_n); //takes a user input and stores it in the variable name
          if(strcmp(y_or_n, "Y") == 0)
          {
            create_directory(name); //creates the directory with the chosen name
            printf("\nMaking project\n" );
            view_directory(); //outputs the subdirectories and files in "Projects", showing that the new directory has been created
          }
          if(strcmp(y_or_n, "N") == 0)
          {
            return 0;
          }
        }
      }
      system("clear"); //clears the screen
      printf("Welcome to the File Manager\n" );
      printf("\nCreate Project = CP \nCreate Feature = CF \nDelete Project = DP \nMove Project = MP \nRename Project = RP \nAdd Tags = AT \nAdd Branch = AB \nGenerate Tree = GT \nBack = B \n\nWhat would you like to do: ");
      scanf("%s", select); //takes a user input, storing it in variable select
    }
    system("clear"); //clears the screen
    printf("Welcome to the Project Manager\n" );
    printf("\nFile Manager = FM \nExit = E \n\nWhat would you like to do: ");
    scanf("%s", choice); //takes a user input, storing it in variable choice
    return 0;
  }
  printf("\nExiting");
  return 0;
}

int main(int argc, const char **argv)
{
  if (argc < 1) //if statement checks to see if the number of arguments when the program is executed are less than 1
  {
    printf("Too few arguments" ); //gives user feedback based on how many arguments are added when executing the program
  }
  if (argc > 2) //if statement checks to see if the number of arguments when the program is executed are more than 1
  {
    printf("Too many arguments" ); //gives user feedback based on how many arguments are added when executing the program
  }
  if(strcmp(argv[1], "PM") == 0) //if statement checks if the argument is equal to "PM"
  {
    ProjectManager(); //executes the function ProjectManager()
  }
  if(strcmp(argv[1], "CP") == 0) //if statement checks if the argument is equal to "CP"
  {
    char name[20]; //creates local variable name
    char command[20]; //creates local variable command
    chdir("");
    created = search_directory("Projects"); //searches for a directory with the name "Projects"
    if(created == 0) //if "Projects" was not created
    {
      system("mkdir Projects"); //the directory "Projects" is created
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects");
    }
    if(created == 1) //checks to see if "Projects" was created
    {
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects");
    }
    system("clear"); //clears the screen
    printf("Enter the chosen name of your project: ");
    scanf("%s", name); //takes an input from the user, storing it in the variable name
    created = search_directory(name); //searches for a directory called the value of name
    if(created == 1) //checks to see if name was created
    {
      printf("This project already exists");
    }
    if(created == 0) //checks to see if name not was created
    {
      create_directory(name); //creates a directory called name
      printf("\nMaking project\n" );
      view_directory(); //outputs the subdirectories and files in "Projects", showing that the new directory has been created
    }
  }
  if(strcmp(argv[1], "CF") == 0) //if statement checks if the argument is equal to "CF"
  {
    char name[20]; //creates local variable name
    char command[40] = "./"; //creates local variable command
    char y_or_n[20]; //creates local variable y_or_n
    chdir("");
    created = search_directory("Projects"); //searches for a directory with the name "Projects"
    if(created == 0) //if "Projects" was not created
    {
      system("mkdir Projects"); //the directory "Projects" is created
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    if(created == 1) //checks to see if "Projects" was created
    {
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    system("clear");
    printf("Enter the chosen name of the project to put your feature in: ");
    scanf("%s", name); //takes a user input for the name of the project, stores it in the variable name
    created = search_directory(name); //searches to see if that project already exists
    if(created == 0)
    {
      printf("This project does not exist, would you like to create it (Y = Yes/ N = No): "); //prompts the user to create a new project if the requested project does not exist
      scanf("%s", y_or_n); //takes an input from the user, storing it in the variable y_or_n
      if(strcmp(y_or_n, "Y") == 0)
      {
        create_directory(name); //creates the project
        printf("\nMaking project\n" );
        view_directory(); //shows that the project has been created
        strcpy(y_or_n,"");
      }
      if(strcmp(y_or_n, "N") == 0)
      {
        return 0;
      }
    }
    if(created == 1)
    {
      sleep(1);
      strcat(command, name);
      chdir(command);
      sleep(1);
      printf("Enter the chosen name of your feature: ");
      scanf("%s", name); //takes an input from the user, storing it in the variable name
      created = search_directory(name); //searches for a directory with the name chosen by the user
      if(created == 0)
      {
        create_feature(name); //creates a directory with the chosen name and all the nessasery subfolders inside
        printf("\nMaking Feature\n" );
        view_directory(); //outputs the subdirectories and files in the requested project, showing that the new directory has been created
      }
      if(created == 1)
      {
        printf("This feature already exists");
      }
    }
  }
  if(strcmp(argv[1], "DP") == 0) //if statement checks if the argument is equal to "DP"
  {
    char name[20]; //creates local variable name
    char command[40] = "./"; //creates local variable command
    chdir("");
    created = search_directory("Projects"); //searches for a directory with the name "Projects"
    if(created == 0) //if "Projects" was not created
    {
      system("mkdir Projects"); //the directory "Projects" is created
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    if(created == 1) //checks to see if "Projects" was created
    {
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    system("clear"); //clears the screen
    printf("Enter the name of the project/feature you would like to remove: ");
    scanf("%s", name); //takes an input from the user, storing it in the variable name
    created = search_directory(name); //searches for a directory with the name chosen by the user
    if(created == 1)
    {
      remove_directory(name); //removes the directory with the name chosen by the user
      printf("\nRemoving Project/Feature\n" );
      view_directory(); //outputs the subdirectories and files in "Projects", showing that the directory has been removed
    }
    if(created == 0)
    {
      printf("This project/feature does not exist");
    }
  }
  if(strcmp(argv[1], "MP") == 0) //if statement checks if the argument is equal to "MP"
  {
    char temp[20]; //creates local variable temp
    char name[20]; //creates local variable name
    char command[20]; //creates local variable command
    chdir("");
    created = search_directory("Projects"); //searches for a directory with the name "Projects"
    if(created == 0) //if "Projects" was not created
    {
      system("mkdir Projects"); //the directory "Projects" is created
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    if(created == 1) //checks to see if "Projects" was created
    {
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    system("clear"); //clears the screen
    printf("Enter the name of project/feature you would like to move: ");
    scanf("%s", name); //takes an input from the user, storing it in the variable name
    created = search_directory(name); //searches for a directory with the name chosen by the user
    if(created == 1)
    {
      strcpy(temp,name); //copies the variable name to the variable temp
      printf("Enter the name of the new location for the project/feature: ");
      scanf("%s", name); //takes an input from the user, storing it in the variable name
      created = search_directory(name); //searches for a directory with the name chosen by the user
      if(created == 1)
      {
        move_directory(temp, name); //moves the directory from the old location to the new location
        printf("\nProject/feature moved");
        view_directory(); //outputs the subdirectories and files in "Projects", showing that the directory has been moved
      }
      if(created == 0)
      {
        printf("The new location for the project/feature does not exist");
      }
    }
  }
  if(strcmp(argv[1], "RP") == 0) //if statement checks if the argument is equal to "RP"
  {
    char temp[20]; //creates local variable temp
    char name[20]; //creates local variable name
    char command[20]; //creates local variable command
    chdir("");
    created = search_directory("Projects"); //searches for a directory with the name "Projects"
    if(created == 0) //if "Projects" was not created
    {
      system("mkdir Projects"); //the directory "Projects" is created
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    if(created == 1) //checks to see if "Projects" was created
    {
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    system("clear"); //clears the screen
    printf("Enter the name of project/feature you would like to rename: ");
    scanf("%s", name); //takes an input from the user, storing it in the variable name
    created = search_directory(name); //searches for a directory with the name chosen by the user
    if(created == 1)
    {
      strcpy(temp,name);
      printf("Enter the new name for the project/feature: ");
      scanf("%s", name); //takes an input from the user, storing it in the variable name
      created = search_directory(name);
      if(created == 0)
      {
        rename_directory(temp, name); //renames the directory to the new name chosen by the user
        printf("\nProject/feature renamed");
        view_directory(); //outputs the subdirectories and files in "Projects", showing that the directory has been renamed
      }
      if(created == 1)
      {
        printf("The new name for the project already exists elsewhere");
      }
    }
    if(created == 0)
    {
      printf("The chosen project/feature does not exist");
    }
  }
  if(strcmp(argv[1], "AT") == 0) //if statement checks if the argument is equal to "AT"
  {
    char name[20]; //creates local variable name
    char command[40] = "./"; //creates local variable command
    char y_or_n[20]; //creates local variable y_or_n
    chdir("");
    created = search_directory("Projects"); //searches for a directory with the name "Projects"
    if(created == 0) //if "Projects" was not created
    {
      system("mkdir Projects"); //the directory "Projects" is created
      chdir("./Projects/");
    }
    if(created == 1) //checks to see if "Projects" was created
    {
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    system("clear"); //clears the screen
    printf("Enter the name of the project/feature you want to tag: ");
    scanf("%s", name); //takes an input from the user, storing it in the variable name
    created = search_directory(name); //searches for a directory with the name chosen by the user
    if(created == 1)
    {
      strcat(command, name);
      chdir(command); //changes directory to the directory with the name chosen by the user
      sleep(1);
      add_tags();
      printf("\nAdded tags\n");
      view_directory(); //outputs the subdirectories and files in "Projects", showing that the new directory has been created
    }
    if(created == 0)
    {
      printf("This project does not exist, would you like to create it (Y = Yes/ N = No): ");
      scanf("%s", y_or_n); //takes an input from the user, storing it in the variable y_or_n
      if(strcmp(y_or_n, "Y") == 0)
      {
        create_directory(name); //create a new directory with the name chosen by the user
        printf("\nMaking project\n" );
        view_directory(); //outputs the subdirectories and files in "Projects", showing that the new directory has been created
      }
      if(strcmp(y_or_n, "N") == 0)
      {
        return(0);
      }
    }
  }
  if(strcmp(argv[1], "AB") == 0) //if statement checks if the argument is equal to "AB"
  {
    char name[20]; //creates local variable name
    char command[40] = "./"; //creates local variable command
    chdir("");
    created = search_directory("Projects"); //searches for a directory with the name "Projects"
    if(created == 0) //if "Projects" was not created
    {
      system("mkdir Projects"); //the directory "Projects" is created
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    if(created == 1) //checks to see if "Projects" was created
    {
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    system("clear"); //clears the screen
    printf("Enter the name of the project you want to create a new branch for: ");
    scanf("%s", name);
    strcat(command, name);
    chdir(command);
    sleep(1);
    printf("Enter the name of the new branch you want to create: ");
    scanf("%s", name); //takes an input from the user, storing it in the variable name
    add_branch(name); //creates a new branch with the chosen name
  }
  if(strcmp(argv[1], "GT") == 0) //if statement checks if the argument is equal to "GT"
  {
    char name[20]; //creates local variable name
    char command[20]; //creates local variable command
    char y_or_n[20]; //creates local varaiable y_or_n
    chdir("");
    created = search_directory("Projects"); //searches for a directory with the name "Projects"
    if(created == 0) //if "Projects" was not created
    {
      system("mkdir Projects"); //the directory "Projects" is created
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    if(created == 1) //checks to see if "Projects" was created
    {
      sleep(1); //halts the program for 1 second to ensure the directory has been created
      chdir("./Projects/");
    }
    system("clear");
    printf("Enter the name of the project you want to be at the top of the tree: ");
    scanf("%s", name); //takes an input from the user, storing it in the variable name
    created = search_directory(name); //searches for a directory with the name chosen by the user
    if(created == 1)
    {
      generate_tree(name);
      printf("\nGenerated Tree\n");
      view_directory(); //outputs the subdirectories and files in "Projects", showing that the new files have been created
    }
    if(created == 0)
    {
      printf("This project does not exist, would you like to create it (Y = Yes/ N = No): ");
      scanf("%s", y_or_n); //takes an input from the user, storing it in the variable y_or_n
      if(strcmp(y_or_n, "Y") == 0)
      {
        create_directory(name);
        printf("\nMaking project\n" );
        view_directory(); //outputs the subdirectories and files in "Projects", showing that the new directory has been created
      }
      if(strcmp(y_or_n, "N") == 0)
      {
        return 0;
      }
    }
  }
  if(strcmp(argv[1], "S") == 0) //if statement checks if the argument is equal to "S"
  {
    scan();
  } 
  return 0;
} 
