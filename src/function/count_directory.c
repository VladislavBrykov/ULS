#include "uls.h"

//считает количество вложенных папок во всех аргументах
int count_directory(int argc, char **name) {
    DIR *dir;
    struct dirent *directory;                            
    int serial_number = 1;
    int count_dir = 1; 
 
    while(name[serial_number] != NULL) {
        dir = opendir(name[serial_number]);
            while ((directory = readdir(dir)) != NULL) {
                count_dir++;
            }
    serial_number++;
    }   
closedir(dir);
return count_dir;
}
