#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int uniquePaths(int m, int n){
	int x = 0;
	int y = 0;
	int i = 0;
	int row = 0;
	int col = 0;
	int dots = m*n;
	int *f;

	if (m == 0 && n == 0) return 0;

	f = malloc(m*n*sizeof(int));
	(void)memset(f, 0, m*n*sizeof(int));

	for (row = 0; row < n; row++) {
		for (col = 0; col < m; col++) {
			i = row * m + col;
			if (i == 0) {
				f[i] = 1;
				continue;
			}
			
			if (col != 0) f[i] += f[i-1];
			if (row != 0) f[i] += f[(row-1)*m+col];
		}
	}

	return f[m*n-1];
}


int main(int argc, char *argv[]) {
	printf("%d %d:%d\n", 3, 2, uniquePaths(3,2));
	printf("%d %d:%d\n", 7, 3, uniquePaths(7,3));
	printf("%d %d:%d\n", 1, 1, uniquePaths(1,1));
	printf("%d %d:%d\n", 2, 1, uniquePaths(2,1));
	printf("%d %d:%d\n", 1, 2, uniquePaths(1,2));
	return 0;
}
