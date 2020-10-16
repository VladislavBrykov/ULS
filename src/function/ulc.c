#include "uls.h"

/*################################################################*/
//создание трехмерного массива, заполнен символами конца строки
static void arr_init_3p(int argc, int number) {
  in_data.str_directory = (char***)malloc(sizeof(char**) * (argc));
  for (int i = 0; i < argc; i++) {
    in_data.str_directory[i] = (char**)malloc(sizeof(char*) * (number + 2));
    for (int j = 0; j < number; j++) {
      in_data.str_directory[i][j] = mx_strnew(255);
    }
  }
}
/*################################################################*/

/*################################################################*/
//выводит отсортированный массив с табами в каждой строке своими
void uls(int argc, char **name) {
	DIR *d = NULL;
  struct dirent *directory;
  int item_number = 0;
  int serial_number = 1;
  int num_dir = 0;
  int num_in_dir = 0;
  int number_of_directories = count_directory(argc, name);
  arr_init_3p(argc, number_of_directories);


  if (argc > 1) {
    while (serial_number < argc) {
      d = opendir(name[serial_number]);
        
        while((name[serial_number][item_number] != '\0') && (name[serial_number] != NULL)) {
           in_data.str_directory[num_dir][num_in_dir][item_number] = name[serial_number][item_number];
           item_number++;
        }        
        item_number=0;
        num_in_dir++;

        while ((directory = readdir(d)) != NULL) {
          if (directory->d_name[0] != '.') {
            char *sss = (directory->d_name);
              while(sss[item_number] != '\0') {
                in_data.str_directory[num_dir][num_in_dir][item_number] = sss[item_number];
                item_number++;
              }
              num_in_dir++;   
              item_number=0;
            }
          }
    num_in_dir = 0;
    num_dir++; 
    serial_number++;
    }
  }

  my_bubble_sort_directory(argc);
  num_dir = 1;
  
  while(num_dir < argc) {
    arr_with_space(in_data.str_directory[num_dir]);
    num_dir++;
  }
closedir(d);
}
