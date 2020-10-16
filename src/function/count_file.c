#include "uls.h"

//количество тектовых файлов среди указанных argv
//для выделения памяти под массив строк

int count_file(char **name, int argc) {   
	void *dir = NULL; 							
	char *file = NULL;
	int serial_number = 1;
	int count_file = 0;	
	
	while(name[serial_number]) {
		dir = opendir(name[serial_number]);
			if(dir == NULL) {
				file = mx_file_to_str(name[serial_number]);

			if (file != NULL) 
				count_file++;
		}
	serial_number++;
	}	
return count_file;
}
