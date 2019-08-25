int removeDuplicates(int* nums, int numsSize){
	int i, pilot, curVal;

	if (numsSize <= 1) return numsSize;

	for (i=0; i<numsSize; i++) {
		if (i == 0) {
			curVal = nums[0];
			pilot = 0;
		} else if (curVal == nums[i]) {
			continue;
		} else {
			curVal = nums[i];
			if (i != pilot) {
				nums[++pilot] = nums[i];
			}
		}
	}
	return pilot+1;
}

