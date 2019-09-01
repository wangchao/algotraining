#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int countSubstrings(char * s){
	int i, j, len;
	int **f;
	int count = 0;

	if (!s) return 0;

	len = strlen(s);
	f = (int**)malloc(sizeof(int*)*len);
	for (i=0; i<len; i++) {
		f[i] = (int*)malloc(sizeof(int)*len);
		memset(f[i], 0, sizeof(int)*len);
	}

	for (i=len-1; i>=0; i--) {
		for (j=i; j<len; j++) {
			if (i==j) {
				f[i][j] = 1;
				count++;
			}
			else if (s[i] == s[j] && j == i+1) {
				f[i][j] = 1;
				count++;
			}
			else if (s[i] == s[j] && f[i+1][j-1]) {
				f[i][j] = 1;
				count++;
			}
		}
	}

	for (i=0; i<len; i++) {
		free(f[i]);
	}
	free(f);

	return count;
}


int main(int argc, char* argv[]) {
	printf("abc: %d\n", countSubstrings("abc"));
	printf("aaa: %d\n", countSubstrings("aaa"));
	printf("abcba: %d\n", countSubstrings("abcba"));
	printf("a: %d\n", countSubstrings("a"));
	return 0;
}
