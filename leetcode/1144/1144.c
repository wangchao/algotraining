int movesToMakeZigzagByFirstDown(int* nums, int numsSize) {
	int step, lastVal, i;
	int lastDown = 1;

	if (nums[0] <= nums[1]) {
		step = nums[1] - nums[0] + 1;
		lastVal = nums[0] - 1;
	} else {
		step = 0;
		lastVal = nums[1];
	}

	for (i = 2; i < numsSize; i++, lastDown = !lastDown) {
		if ((lastDown  && nums[i] > lastVal) ||
		    (!lastDown && nums[i] < lastVal)) {
			lastVal = nums[i];
		} else if (lastDown && nums[i] <= lastVal) {
			step += lastVal - nums[i] + 1;
			lastVal = nums[i];
		} else if (!lastDown && nums[i] >= lastVal) {
			step += nums[i] - lastVal + 1;
			lastVal--;
		}
	}
	return step;
}

int movesToMakeZigzagByFirstUp(int* nums, int numsSize) {
	int step, lastVal, i;
	int lastUp = 1;

	if (nums[0] < nums[1]) {
		step = 0;
		lastVal = nums[1];
	} else {
		step = nums[0] - nums[1] + 1;
		lastVal = nums[1];
	}

	for (i = 2; i < numsSize; i++, lastUp = !lastUp) {
		if ((lastUp  && nums[i] < lastVal) ||
		    (!lastUp && nums[i] > lastVal)) {
			lastVal = nums[i];
		} else if (lastUp && nums[i] >= lastVal) {
			step += nums[i] - lastVal + 1;
			lastVal--;
		} else if (!lastUp && nums[i] <= lastVal) {
			step += lastVal - nums[i] + 1;
			lastVal = nums[i];
		}
	}
	return step;
}


int movesToMakeZigzag(int* nums, int numsSize){
	int step1, step2;

	if (numsSize == 1) return 0;

	step1 = movesToMakeZigzagByFirstDown(nums, numsSize);
	step2 = movesToMakeZigzagByFirstUp(nums, numsSize);

	return (step1 < step2) ? step1 : step2;
}

