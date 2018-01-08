bool canJump(int* nums, int numsSize) {
    if(NULL == nums || 0 == numsSize)
		return 0;
	int max_step = nums[0];
	for(int i = 1; i < numsSize; i++){
	    if(0 == max_step)
	        return 0;
	    max_step--;
	    if(max_step < nums[i])
	        max_step = nums[i];
	    if(max_step + i >= numsSize)
	        return true;
	}
}