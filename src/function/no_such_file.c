#include "uls.h"

char **no_such_directory(char **name, int argc) {
	void *dir = NULL; 
	char *file = NULL;
	int coount_file = count_file(name, argc); 
	char **str_result = arr_init(argc, coount_file); //пустой массив - веделение памяти
	char **new_arr = arr_init(argc, coount_file);
	char **new_arr_2 = arr_init(argc, coount_file);
	int serial_number = 1;
	int num_world = 0;
	int item_number = 0;

	while (name[serial_number]) {
		dir = opendir(name[serial_number]);
			if (dir == NULL) {
				file = mx_file_to_str(name[serial_number]);
					if(file == NULL) {
						mx_printerr("uls: ");
						mx_printerr(name[serial_number]);
						mx_printerr(": No such file or directory\n");
					}
					else if (file != NULL) {
						while(name[serial_number][item_number] != '\0') {
							str_result[num_world][item_number] = name[serial_number][item_number];
							item_number++;
						}
						num_world++;
						item_number = 0;
					}
			}
		serial_number++;
		}
	str_result[num_world] = NULL;
	new_arr = arr_with_space(str_result);  //на выходе массив со строками одинаковой длины
	new_arr_2 = my_bubble_sort_file(new_arr, coount_file);  //на выходе отсортированный массив со строками одинаковой длины
	//если закрываю дир - выбивает ошибку, а так все работает
	//closedir(dir);  //segmentation fault 
free(str_result);
return new_arr_2; //отсортированный двумерный масив строк с названиями ФАЙЛОВ уже с пробелами
}
