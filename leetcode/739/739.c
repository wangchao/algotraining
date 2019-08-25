/**
 * Note: The returned array must be malloced, assume caller calls free().
  */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
	int i;
	int j;
	int stack[30000] = {0};
	int stackIdx = -1;
	int *days = (int*)malloc(sizeof(int) * TSize);
	if (!days) {
		*returnSize = 0;
		return NULL;
	}

	for (i = 0; i < TSize; i++) {
		if (stackIdx == -1) {
			stack[++stackIdx] = i;
		}
		else if (T[i] <= T[stack[stackIdx]]) {
			stack[++stackIdx] = i;
		}
		else {
			while (stackIdx != -1 && T[i] > T[stack[stackIdx]]) {
				days[stack[stackIdx]] = i - stack[stackIdx];
				stackIdx--;
			}
			stack[++stackIdx] = i;
		}
	}

	while (stackIdx != -1) {
		days[stack[stackIdx]] = 0;
		stackIdx--;
	}

	*returnSize = TSize;
	return days;
}
