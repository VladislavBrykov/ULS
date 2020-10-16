#include "uls.h"

void printf_directory(int argc, int signal) {

int count_of_lines = 1;


while(count_of_lines < argc) {
	char **array = in_data.str_directory[count_of_lines];
	int size_of_consol = size_consol();  //ширина консоли
	int max_long_arr = 0;       //максимальная длина строки
	int num_arr_1 = 1;        //рассматривает с первого елемента
	max_long_arr = mx_strlen(array[num_arr_1]);  //высчитываю длину самого длинного елемента в двумерном массиве
	int num_arr_2 = 1;
	int count_of_text_file = 1;
	int num = 1;
	int item_number = 0;
	int length_of_all_lines = 0;

	while(array[num_arr_1] != NULL) { 
		if(mx_strlen(array[num_arr_1]) > max_long_arr) 
			max_long_arr = mx_strlen(array[num_arr_1]);
		num_arr_1++;
	}


	while (array[num_arr_2] != NULL) {
		if(!mx_isspace(array[num_arr_2][0]))
			count_of_text_file++;
		num_arr_2++;
	}

	count_of_text_file = count_of_text_file - 1;        //кол текстовых файлов

	while((max_long_arr % 8) != 0)    //максимально длинный элемент строки округляю до числа кратного 8
		max_long_arr++;

	length_of_all_lines = ((max_long_arr * count_of_text_file) + count_of_text_file); //моя длина всех строк сумарно


/*##############################################################################################*/

	if(length_of_all_lines <= size_of_consol) {
		while(array[0][item_number] != '\t')
			item_number++;

		if((argc > 2) || (signal > 1)) {
			array[0][item_number] = ':';
			array[0][item_number + 1] = '\0';
		}

		if(count_of_lines > 1) 
			mx_printstr("\n");
	
		if((argc > 2) || (signal > 1)) {
			mx_printstr(array[0]);
			mx_printstr("\n");
		}

		while(array[num] != NULL) {
			mx_printstr(array[num]);
			num++;
		}
	mx_printstr("\n");
	num = 0;
	}

 	int del = 0;

/*##############################################################################################*/


/*##############################################################################################*/

	if (length_of_all_lines > size_of_consol) {

		if(count_of_lines > 1) 
			mx_printstr("\n");

		item_number = 0;

		while(array[0][item_number] != '\t')
			item_number++;

		if((argc > 2) || (signal > 1)) {
			array[0][item_number] = ':';
			array[0][item_number+1] = '\0';
			mx_printstr(array[0]);
			mx_printstr("\n");
		}

		while((max_long_arr % 8) != 0)
			max_long_arr++;


		int max = size_of_consol/max_long_arr;

		while ((count_of_text_file % max) != 0)
			count_of_text_file++;

		del = count_of_text_file/max;

		int resurs = 1;
		
		while(resurs <= del) {
			num = resurs;
			while(num <= count_of_text_file) {
				mx_printstr(array[num]);
				num = num + del;
			}
			mx_printstr("\n");
			resurs++;
			num = 0;
		}
	}
/*##############################################################################################*/
	count_of_lines++;
	}
}

