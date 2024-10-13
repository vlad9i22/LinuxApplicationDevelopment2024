#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if(argc == 1) {
		printf("Provide some arguments: one for range [0, N), two for range [M, N), three for range [M, M + S, M + 2*S, ...]");
	} else if(argc >= 2) {
		int n = atoi(argv[1]);
		int m = 0;
		int s = 1;
		if(argc >= 3) {
			m = atoi(argv[2]);
			int cur_sw = n;
			n = m;
			m = cur_sw;
		}
		if(argc >= 4) {
			s = atoi(argv[3]);
		}
		for(int i = m; i < n; i += s) {
			printf("%d\n", i);
		}
	}
}
