#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){

	char *dir = "./tmp/";
	DIR* dirp = opendir(dir);
	if (dirp == NULL) {
		printf("Directory cannot be opened");
		return -1;
	}
	
	struct dirent *dent;
	while ((dent = readdir(dirp)) != NULL){

		char *name = dent->d_name;
		if (name[0] != '.'){
			struct stat s;
			char path[100];
			strcpy(path, dir);
			strcat(path, name);
			stat(path, &s);
			if (s.st_nlink > 1) {
				printf("File: %s - %d links\n", name, s.st_nlink);
				char cmd[100];
				char str[40];
				snprintf(str, 40, "%d", s.st_ino);
				strcpy(cmd, "find ./ -inum ");
				printf("%s", path);
				strcat(cmd, str);
				//strcat(cmd, " ");
				//strcat(cmd, path);
				system(cmd);	
			}
		}	
	}
	return 0;

    }
