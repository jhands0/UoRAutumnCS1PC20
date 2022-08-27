#define _DIR 1
#define _FILE 2
#define MAX_NUM 100
#define NAME_LENGTH 100

const char* dash ="/";
void make_route(char result[], char path[], char fname[]);
int tag_tree_crawl(char type, char result[MAX_NUM][NAME_LENGTH], int index, char path[]);
int plantuml_tree_crawl(char type, char result[MAX_NUM][NAME_LENGTH], int index, char path[]);
int read_tag(char tag[20]);
int write_tag(char tag[20], char title[20]);
int add_tags(void);
int generate_tree(char start[20]);
int create_tree(char name[20]);
