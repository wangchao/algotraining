
int calLiveAround(int** board, int x, int y, int row, int col) {
    int i;
    int j;
    int LiveCnt = 0;

    for (i=x-1; i<=x+1; i++) {
        for (j=y-1; j<=y+1; j++) {
            if (i<0 || j<0 || i>=row || j>=col) continue;
            if (i==x && j==y) continue;
            if (board[i][j]) LiveCnt++;
        }
    }
    return LiveCnt;
}


void gameOfLife(int** board, int boardSize, int* boardColSize){
    int row = boardSize;
    int col = *boardColSize;
    int i;
    int j;
    int liveCnt;

    if (boardSize == 0 || board == NULL) {
        return;
    }

    int **mir = (int**)malloc(row*sizeof(int*));
    if (!mir) return;

    for (i=0; i<row; i++) {
        mir[i] = (int*)malloc(col*sizeof(int));
        (void)memcpy(mir[i], board[i], col*sizeof(int));
    }

    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            liveCnt =calLiveAround(mir, i, j, row, col);
            if (liveCnt < 2 && board[i][j]) board[i][j] = 0;
            else if ((liveCnt == 2 || liveCnt == 3) && board[i][j]) board[i][j] = 1;
            else if (liveCnt > 3 && board[i][j]) board[i][j] = 0;
            else if (liveCnt == 3 && !board[i][j]) board[i][j] = 1;
        }
    }

    for (i=0; i<row; i++) {
        (void)free(mir[i]);
    }
    free(mir);

    return;
}

