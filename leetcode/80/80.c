int removeDuplicates(int* nums, int numsSize){
	int i, pilot, occurCnt, curVal;

	if (numsSize <= 2) return numsSize;

	for (i = 0; i < numsSize; i++) {
		if (i == 0) {
			curVal = nums[0];
			occurCnt = 1;
			pilot = 0;
		} else if (nums[i] == curVal) {
			if (++occurCnt > 2) {
			    continue;
			}
 			pilot++;
            		if (i != pilot) { //////
                		nums[pilot] = nums[i];
            		}
		} else {
			curVal = nums[i];
			occurCnt = 1;
			if (i != pilot) {
				nums[++pilot] = nums[i];
			}
		}
	}
	return pilot+1;
}
