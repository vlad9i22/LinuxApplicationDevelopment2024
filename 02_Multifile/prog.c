#include "outlib.h"
int main(int argc, char *argv[]) {
    Count = argc;
	if(argc == 1) {
		output("Help: I will not help you figure out stuff yourself");
		return 0;
	}
    output("<INIT>");
    output(argc>1 ? argv[1] : "<NOPE>");
    output("<DONE>");
    return 0;
}
