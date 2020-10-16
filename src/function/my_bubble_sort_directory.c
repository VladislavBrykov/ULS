#include "uls.h"

static int x_strcmp(const char *s1, const char *s2) {

    while ((*s1 != '\0' || *s2 != '\0') && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    if (*s1 != *s2)
        return *s1 - *s2;
    else
        return 0;
}

void my_bubble_sort_directory(int argc) {
/*################################################################*/
//сортировка по содержимому папок
	char *kesh;
    int serial_number = 0;
    while(serial_number < argc) {
        for (int i = 1; in_data.str_directory[serial_number][i][0] != '\0'; i++) {
            for (int j = i + 1; in_data.str_directory[serial_number][j][0] != '\0'; j++) {
		      	if (x_strcmp(in_data.str_directory[serial_number][i], in_data.str_directory[serial_number][j]) > 0) {
			     	kesh = in_data.str_directory[serial_number][i];
				    in_data.str_directory[serial_number][i] = in_data.str_directory[serial_number][j];
				    in_data.str_directory[serial_number][j] = kesh;
                }
            }
        }
    serial_number++;
    }
/*################################################################*/

  
/*################################################################*/    
//сортировка по корневым папкам
    char **kesh_1;
    int size = argc;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((mx_strcmp(*in_data.str_directory[i], *in_data.str_directory[j]) > 0) && ((*in_data.str_directory[i] != '\0') || (*in_data.str_directory[j] != '\0'))) {
                kesh_1 = in_data.str_directory[i];
                in_data.str_directory[i] = in_data.str_directory[j];
                in_data.str_directory[j] = kesh_1;
            }
        }
    }
/*################################################################*/
}
