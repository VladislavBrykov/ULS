#include "uls.h"

int size_consol(void) {
	struct winsize window;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
	int size = window.ws_col;	
return size;
}
