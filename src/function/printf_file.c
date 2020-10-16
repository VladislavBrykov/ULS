#include "uls.h"

void printf_file_directory(char **name, int argc) {
	argc = argc-1;
	char **array = no_such_directory(name, argc);
	int my_size_consol = size_consol();
	struct dirent *directory;
	int coount_file = count_file(name, argc);					//кол текстовых файлов
	int max_long = 0;
	int serial_number = 0;
	int serial_number_arr = 1;									//рассматривает с первого елемента
	int count_line = 0;
	

/*##########################################################################*/
	while(array[serial_number_arr] != NULL) {					//высчитываю длину самого длинного елемента в двумерном массиве 
		if(mx_strlen(array[serial_number_arr]) > serial_number_arr) 
			max_long = mx_strlen(array[serial_number_arr]);
		serial_number_arr++;
	}

	while((max_long % 8) != 0)
		max_long++;
	
	int point = ((max_long * argc));  //моя длина всех строк сумарно
/*##########################################################################*/


/*##########################################################################*/
//если помещается в одну строку с учетом пробелов (кол файлов)
	if(point <= my_size_consol) {
		while(array[serial_number] != NULL) {
			mx_printstr(array[serial_number]);
			serial_number++;
		}
	mx_printstr("\n");
	serial_number = 0;
	}
/*##########################################################################*/



/*##########################################################################*/
//если не помещается в одну строку с учетом пробелов (кол файлов)
	if (point > my_size_consol) {
		int max_count_element = my_size_consol/max_long;

	while(argc >=0) {
		argc = argc - max_count_element;
		count_line++;
	}

	int count_line_resurs = 0;	
	while(count_line_resurs < count_line) {
		serial_number = count_line_resurs;
			while(serial_number < coount_file) {
				mx_printstr(array[serial_number]);
				serial_number = serial_number + count_line;
			}
			mx_printstr("\n");
			count_line_resurs++;
			serial_number = 0;
		}
	} 
/*##########################################################################*/
}
