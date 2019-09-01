
int calcCutCnt(int **wall, int wallSize, int cutPos, int curRow, int wide)
{
    int i;
    int j;
    int tmpWide;
    int cutThrough = 0;

    for (i=0; i<wallSize; i++) {
        if (i == curRow) continue;

        tmpWide = 0;
        j = 0;
        while (tmpWide < wide) {
            tmpWide += wall[i][j++];
            if (tmpWide == cutPos) break;
            if (tmpWide > cutPos) {
                cutThrough++;
                break;
            }
            if (tmpWide == wide) break;
        }
    }

    return cutThrough;
}

int leastBricks(int** wall, int wallSize, int* wallColSize){
    int i;
    int j;
    int wide = 0;
    int tmpWide;
    int minCutThrough = wallSize;
    int cutThrough;

    if (wallSize == 0 || *wallColSize == 0) return 0;
    //if (wallSize == 1 && *wallColSize == 1) return 1; /////////////////////[[100000000]]
    //if (wallSize == 1 && *wallColSize != 1) return 0; /////////////////////[[79, 12, 208, 1]]

    for (i=0; i<*wallColSize; i++) wide += wall[0][i];

    for (i=0; i<wallSize; i++) {
        tmpWide = 0;
        j = 0;
        while (tmpWide < wide) {
            tmpWide += wall[i][j++];
            if (tmpWide == wide) break;
            cutThrough = calcCutCnt(wall, wallSize, tmpWide, i, wide);
            if (cutThrough < minCutThrough) minCutThrough = cutThrough;
        }
    }

    return minCutThrough;
}
