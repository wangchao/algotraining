#define MAX(a,b) ((a) > (b) ? (a) : (b))

int longestPalindromeSubseq(char * s){
	int n = strlen(s);
	int *f = (int*)malloc(n*n*sizeof(int));
	int i,j;
	int result;
	for (i=n-1;i>=0;i--) {
		f[i*n+i] = 1;
		for (j=i+1;j<n;j++) {
			if (s[i] == s[j]) {
				if (i+1 == j) f[i*n+j] = 2;
				else f[i*n+j] = f[(i+1)*n + j-1] + 2;
			}
			else {
				if (i+1 == j) f[i*n+j] = 1;
				else f[i*n+j] = MAX(f[(i+1)*n+j], f[i*n+j-1]);
			}
		}
	}
	result = f[0*n+n-1];
	free(f);
	return result;
}
