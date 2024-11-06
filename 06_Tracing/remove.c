#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

typedef int (*orig_remove_f_type)(const char *pathname);



int remove(const char *pathname) {
	orig_remove_f_type orig_remove;
	orig_remove = (orig_remove_f_type)dlsym(RTLD_NEXT,"remove");
	if(strstr(pathname, "PROTECT") != NULL) {
		printf("Noone can take away my power\n");
		return 0;
	}
	return orig_remove(pathname);
}
