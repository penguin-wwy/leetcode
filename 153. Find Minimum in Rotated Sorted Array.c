int findMin(int* nums, int numsSize) {
    if (NULL == nums)
        return NULL;
    
    int head = 0;
    int end = numsSize - 1;
    int mid = head;
    
    while ( nums[head] >= nums[end] ) {
        if ( end - head <= 1) {
            mid = end;
            break;
        }
        
        mid = (head + end) / 2;
        if (nums[mid] >= nums[head])
            head = mid;
        else if (nums[mid] <= nums[end])
            end = mid;
    }
    
    return nums[mid];
}