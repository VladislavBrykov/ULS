#include "uls.h"

//сортировка, доработанный бабл сорт, ретернит именно отсортированный массив

char **my_bubble_sort_file(char **arr, int size) {
	char *arr_reserv;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (mx_strcmp(arr[i], arr[j]) > 0) {
				arr_reserv = arr[i];
				arr[i] = arr[j];
				arr[j] = arr_reserv;
			}
		}
	}
return arr;
}
