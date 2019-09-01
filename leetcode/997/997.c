

int findJudge(int N, int** trust, int trustSize, int* trustColSize)
{
    int i = 0, j = 0,k;
    int *trustMatrix;
    int trustee; // [1,2]: 2
    int truster; // [1,2]: 1
    int found = 0;

    if (N == 0) return -1;
    if (N == 1 && trustSize == 0) return N;
    
    trustMatrix = (int*)malloc(sizeof(int)*N*N);
    if (!trustMatrix) return -1;
    (void)memset(trustMatrix, 0, sizeof(int)*N*N);

    for (i = 0; i < trustSize; i++) {
        trustee = trust[i][1];
        truster = trust[i][0];   
        trustMatrix[(trustee-1)*N + truster-1] = 1;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i != j && trustMatrix[i*N + j] == 0) break;
        }
        if (j == N) {            
            for (k = 0; k < N; k++) {
                if (trustMatrix[k*N + i] != 0) break;
            }
            if (k == N) {
                free(trustMatrix);
                return i+1;
            }
        }
    }

    free(trustMatrix);
    return -1;
}


