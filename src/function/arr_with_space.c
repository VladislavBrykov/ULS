#include "uls.h"

static int arr_tab(char **arr) {  
	int serial_number = 1;
	int len_arr_zero = 0;
	len_arr_zero = mx_strlen(arr[0]);

	while (arr[serial_number] != NULL) {
		if(mx_strlen(arr[serial_number]) > len_arr_zero) {
			len_arr_zero = mx_strlen(arr[serial_number]);
			arr[serial_number][len_arr_zero] = '\t';
			len_arr_zero = mx_strlen(arr[serial_number]);	//дописываю таб к самому длинному слову массива
		}
	serial_number++;
	}
while (len_arr_zero % 8 != 0)
	len_arr_zero++;											//ретерню округленное значение с учетом таба кратное 8
	
return len_arr_zero;
}

/*######################################################################*/
//arr_with_space
//смотрим на длину максимально длинного слова
//дописываем пробелы чтоб все строки имели одинаковую длину
//заполнение пробелами + табуляция
/*######################################################################*/

char **arr_with_space(char **arr) {
	int serial_number = 0;
	int len_arr_serial_num = 0;
	int count_symbol_smaller_max = 0;
	int amount_of_elements = 0;
	int num_num = num_max_file(arr); //номер элемента с максимальной длиной, 
	int max_long = mx_strlen(arr[num_num]);  //максимальная длина без таба

	if((max_long % 8) == 0)		//если длина кратна 8 + 8 (1 tab)
		max_long = max_long + 8;
	else {
		while((max_long % 8) != 0)
			max_long++;			//на выходе имею длину кратную 8 к ней приводу все остальные элементы
	}

	while(arr[serial_number] != NULL) {
		len_arr_serial_num = mx_strlen(arr[serial_number]);
		count_symbol_smaller_max = max_long - len_arr_serial_num;

		while((count_symbol_smaller_max % 8) != 0)
			count_symbol_smaller_max++;

		if(count_symbol_smaller_max == 8) 
			amount_of_elements = 1;

		if(count_symbol_smaller_max > 8)
			amount_of_elements = count_symbol_smaller_max/8;

		while(amount_of_elements != 0) {
			arr[serial_number][len_arr_serial_num] = '\t';
			len_arr_serial_num++;
			amount_of_elements--;
		}
	serial_number++;
	}
return arr;  //на выходе массив со строками одинаковой длины
}
