#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _DIR 1
#define _FILE 2
#define MAX_NUM 100
#define NAME_LENGTH 100

int write_tag(char tag[20], char title[20])
{
    FILE *file;
    file = fopen(title, "w");
    fputs(tag, file);
    fclose(file);
}

int read_tag(char tag[20])
{
    FILE *file;
    char buffer[255];
    file = fopen(".pm_tag", "r");
    fgets(buffer, 255, (FILE*)file);
    printf("%s", buffer);
}

const char* dash ="/";
void make_route(char result[], char path[], char fname[])
{
                  strcpy(result, path);
                  strcat(result, dash);
                  strcat(result, fname);

}
int tag_tree_crawl(char type, char result[MAX_NUM][NAME_LENGTH],int index, char path[])
{
  DIR *d;
  int count = 0;
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
                  const char* tag = "F";
                  count = count + 1;
                  char name[20];
                  strcpy(name, dir_entry->d_name);
                  char *num;
                  char buffer[MAX_NUM];
                  if (sprintf(num, "%d", count) == -1) 
                  {
                    perror("sprintf");
                  } 
                  else 
                  {
                    strcpy(buffer, tag);
                    strcat(buffer, num);
                    printf("%s\n", buffer);
                    free(num);
                  }
                  chdir(name);
                  write_tag(buffer, ".pm_tag");
                  chdir("..");
                  make_route(temp, path, dir_entry->d_name);
                  strcpy(result[index++],temp);
                  index=tag_tree_crawl(_DIR, result, index, temp);
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

int plantuml_tree_crawl(char type, char result[MAX_NUM][NAME_LENGTH],int index, char path[], char start[20])
{
  DIR *d;
  int count = 0;
  int total = 0;
  char space[20] = " ";
  char empty[20] = "";
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
                  total = total + 1;
                  char name[20];
                  strcpy(name, dir_entry->d_name);
                  for(count = 1; count < total; count = count + 1)
                  {
                    strcat(empty, "*");
                  }
                  strcat(empty, space);
                  strcat(empty, name);
                  write_tag(empty, start);
                  make_route(temp, path, dir_entry->d_name);
                  strcpy(result[index++],temp);
                  index=plantuml_tree_crawl(_DIR, result, index, temp, start);
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

int create_tree(char name[20])
{
  char command[150] = "java -jar ~/pc20_pm_cw2/plantuml-1.2021.16.jar ";
  strcat(command, name);
  system(command);
  sleep(1);
  printf("Created Tree");
}

int add_tags(void)
{
  char typ=_DIR;
  char result_list[MAX_NUM][NAME_LENGTH];
  int num_found;
  num_found= tag_tree_crawl(typ, result_list, 0, ".");
  return 0;
}

int generate_tree(char start[20])
{
  char typ=_DIR;
  char result_list[MAX_NUM][NAME_LENGTH];
  int num_found;
  chdir(start);
  strcat(start,".txt");
  sleep(1);
  write_tag("@startwbs", start);
  num_found= plantuml_tree_crawl(typ, result_list, 0, ".", start);
  write_tag("@endwbs", start);
  create_tree(start);
  return 0;
}
