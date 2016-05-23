int minInArr(int *nums, int a, int b) {
    for(int i = a + 1; i <= b; i++) {
        if (nums[a] > nums[i])
            return i;
    }
    return (a + b) / 2;
}

int findMin(int* nums, int numsSize) {

    
    int index1 = 0;
    int index2 = numsSize - 1;
    int midindex = index1;
    
    while(nums[index1] >= nums[index2]) {
        if (index2 - index1 <= 1) {
            midindex = index2;
            break;
        }
        
        midindex = (index1 + index2) / 2;
        
        if(nums[index2] == nums[index1] && nums[index1] == nums[midindex]) {
            midindex = minInArr(nums, index1, index2);
            break;
        }
        
        if(nums[midindex] >= nums[index1])
            index1 = midindex;
        else if(nums[midindex] <= nums[index2])
            index2 = midindex;
    }
    
    return nums[midindex];
}