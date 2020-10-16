#include "uls.h"

int num_max_file(char **arr) {   //ретерню номер элемента с самой большой длиной
	int serial_number = 0;
	int long_zero_arr = mx_strlen(arr[0]);
	int num_max_file = 0;

	while (arr[serial_number] != NULL) {
		if(mx_strlen(arr[serial_number]) > long_zero_arr) {
			long_zero_arr = mx_strlen(arr[serial_number]);
			num_max_file = serial_number;
		}
	serial_number++;
	}
return num_max_file;
}
