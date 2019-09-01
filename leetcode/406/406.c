
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int i;
    int j;
    int k;
    int maxHeightIdx;
    int tmpHeight;
    int tmpBefore;
    int insertIdx;
    int currentHeight;
    int currentBefore;
    int *tmpColumnSizes;

    if (peopleSize == 0 || people == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int **sortedPeople = (int**)malloc(sizeof(int*)*peopleSize);
    tmpColumnSizes = (int*)malloc(sizeof(int)*peopleSize);
    if (!sortedPeople || !*returnColumnSizes) return NULL;

    for (i=0; i<peopleSize; i++) {
        sortedPeople[i] = (int*)malloc(sizeof(int)*(*peopleColSize));
        if (!sortedPeople[i]) return NULL;

        (void)memset(sortedPeople[i], 0, sizeof(int)*(*peopleColSize));
        tmpColumnSizes[i] = *peopleColSize;
    }

    *returnColumnSizes = tmpColumnSizes;
    *returnSize = peopleSize;

    for (i=0; i<peopleSize; i++) {
        maxHeightIdx = i;
        for (j=i+1; j<peopleSize; j++) {
            if (people[j][0] > people[maxHeightIdx][0]) {
                maxHeightIdx = j;
            } else if (people[j][0] == people[maxHeightIdx][0] && 
                       people[j][1] < people[maxHeightIdx][1]) {
                maxHeightIdx = j;
            }
        }
        if (maxHeightIdx != i) {
            tmpHeight = people[i][0];
            tmpBefore = people[i][1];
            people[i][0] = people[maxHeightIdx][0];
            people[i][1] = people[maxHeightIdx][1];
            people[maxHeightIdx][0] = tmpHeight;
            people[maxHeightIdx][1] = tmpBefore;
        }
    }

    for (i=0; i<peopleSize; i++) {
        insertIdx = i;
        currentHeight = people[i][0];
        currentBefore = people[i][1];
        for (tmpBefore=0, j=0; j<i; j++) {
            if (people[j][0] >= currentHeight) tmpBefore++;
            if (tmpBefore > currentBefore) {
                insertIdx = j;
                break;
            }
            if (tmpBefore == currentBefore) {
                insertIdx = j+1;
                break;
            }
        }
        for (k=i; k>insertIdx; k--) {
            sortedPeople[k][0] = sortedPeople[k-1][0];
            sortedPeople[k][1] = sortedPeople[k-1][1];
        }
        sortedPeople[insertIdx][0] = currentHeight;
        sortedPeople[insertIdx][1] = currentBefore;
    }

    return sortedPeople;
}
