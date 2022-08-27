#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define _DIR 1
#define _FILE 2
#define MAX_NUM 100
#define NAME_LENGTH 100

const char* slash ="/";
void make_path(char result[], char path[], char fname[])
{
                  strcpy(result, path);
                  strcat(result, slash);
                  strcat(result, fname);

}
int list_file_type(char type, char result[MAX_NUM][NAME_LENGTH],int index, char path[])
{
  DIR *d;
  struct dirent *dir_entry;
  d = opendir(path);
  if (d)
  {
    while ((dir_entry = readdir(d)) != NULL) {
          if (type == _DIR && dir_entry->d_type == DT_DIR)
          {
                if (dir_entry->d_name[0] != '.')
                {
                  char temp[NAME_LENGTH];
                  make_path(temp, path, dir_entry->d_name);
                  strcpy(result[index++],temp);
                  index=list_file_type(_DIR, result, index, temp);
                }
          }
          if (type == _FILE && dir_entry->d_type == DT_REG)
          {
                strcpy(result[index++],dir_entry->d_name);
          }
    }
    closedir(d);
  }
  return(index);
}

int scan(void)
{
  char typ=_DIR;
  char result_list[MAX_NUM][NAME_LENGTH];
  int num_found;
  printf("Directories\n");
  num_found= list_file_type(typ, result_list, 0, ".");
  for (int i=0;i<num_found;i++)
    printf("%s\n",result_list[i]);

  printf("\nFiles\n");
  typ=_FILE;
  num_found= list_file_type(typ, result_list, 0, ".");
  for (int i=0;i<num_found;i++)
    printf("%s\n",result_list[i]);
}

int search_directory(char name[20])
{
  printf("\nStarting Search directory\n");
  char typ=_DIR;
  char result_list[MAX_NUM][NAME_LENGTH];
  int num_found;
  int created = 0;
  char search[40];
  strcpy(search,"./");
  if(strcmp(name, "Projects") == 0)
  {
    strcpy(search, "./Projects");
    num_found= list_file_type(typ, result_list, 0, ".");
    for (int i=0;i<num_found;i++)
    {
      if(strcmp(search, result_list[i]) == 0)
      {
        created = 1;
        break;
      }
    }
    return(created);
  }
  if(strcmp(name, "Projects") != 0)
  {
    strcat(search, name);
    num_found= list_file_type(typ, result_list, 0, ".");
    for (int i=0;i<num_found;i++)
    {
      if(strcmp(search, result_list[i]) == 0)
      {
        created = 1;
        break;
      }
    }
    return(created);
  }
}

int search_files(char name[20])
{
  char typ=_FILE;
  char result_list[MAX_NUM][NAME_LENGTH];
  int num_found;
  int created = 0;
  printf("Files\n");
  num_found= list_file_type(typ, result_list, 0, ".");
  for (int i=0;i<num_found;i++)
  {
    if(strcmp(result_list[i],name) == 0)
    {
      created = 1;
      break;
    }
  }
  return(created);
}
