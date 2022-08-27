#define _DIR 1
#define _FILE 2
#define MAX_NUM 100
#define NAME_LENGTH 100

const char* slash ="/";
void make_path(char result[], char path[], char fname[]);
int list_file_type(char type, char result[MAX_NUM][NAME_LENGTH], int index, char path[]);
int scan(void);
int created;
int search_directory(char name[20]);
int search_files(char name[20]);
