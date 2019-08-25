char * longestPalindrome(char * s){
	int i,j;
	int n = strlen(s);
	int *f = (int*)malloc(sizeof(int)*n*n);
	(void*)memset(f,0,sizeof(int)*n*n);
	int maxlen = 1, beginIdx = n-1, endIdx = n-1;
	char *result;

	if (n == 0) return s; /////

	for (i=n-1; i>=0; i--) {
		f[i*n+i] = 1;
		for (j=i+1; j<n; j++){
			if (s[i] == s[j]) {
				if (i+1 == j) f[i*n+j] = 1;
				else if (f[(i+1)*n+j-1]) f[i*n+j] = 1;

				if (f[i*n+j] && j-i+1 > maxlen) {
					maxlen = j-i+1;
					beginIdx = i;
					endIdx = j;
				}
			}
		}
	}
	
	free(f);
	s[endIdx+1] = '\0';
	return s+beginIdx;
}
