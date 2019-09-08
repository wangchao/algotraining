#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>



int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
	int x,y,i,j,dot,result;
	unsigned int *f; // int will cause 'signed integer overflow' for some testcase

	if (obstacleGridSize == 0 || *obstacleGridColSize == 0) return 0;
        
	f = (unsigned int*)malloc(sizeof(unsigned int) * obstacleGridSize * (*obstacleGridColSize));
	(void)memset(f, 0, sizeof(unsigned int) * obstacleGridSize * (*obstacleGridColSize));

	for (i=0; i<obstacleGridSize; i++) {
		for (j=0; j<*obstacleGridColSize; j++) {
			dot = i* *obstacleGridColSize + j;
			if (obstacleGrid[i][j]) { //先判断障碍， [[1]]用例
				f[dot] = 0;
				continue;
			}
			
			if (dot == 0) {
				f[dot] = 1;
				continue;
			}

			if (j != 0) f[dot] += f[dot-1];
			if (i != 0) f[dot] += f[(i-1)* *obstacleGridColSize + j];
		}
	}
	result = f[obstacleGridSize * *obstacleGridColSize - 1];
	free(f);
	return result;
}


int main(int argc, char *argv[]) {
	int row1[] = {0,0,0};
	int row2[] = {0,1,0};
	int row3[] = {0,0,0};
	int* grid1[3] = {row1, row2, row3};

	int col1 = 3;
	printf("grid1: %d\n", uniquePathsWithObstacles((int**)grid1, 3, &col1));

	int row11[] = {0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0};
	int row12[] = {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	int row13[] = {0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0};
	int row14[] = {1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1};
	int row15[] = {0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0};
	int row16[] = {0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0};
	int row17[] = {1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0};
	int row18[] = {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0};
	int row19[] = {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0};
	int row110[]= {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0};
	int row111[]= {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0};
	int row112[]= {1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1};
	int row113[]= {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0};
	int row114[]= {0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0};
	int row115[]= {0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1};
	int row116[]= {1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int row117[]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0};
	int row118[]= {0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1};
	int row119[]= {0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1};
	int row120[]= {1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0};
	int row121[]= {0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1};
	int row122[]= {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0};
	int *grid2[22] = {row11,row12,row13,row14,row15,row16,row17,row18,row19,row110,row111,row112,row113,row114,row115,row116,row117,row118,row119,row120,row121,row122};

	int col2 = 33;
	printf("grid2: %d\n", uniquePathsWithObstacles((int**)grid2, 22, &col2));
	return 0;
}
