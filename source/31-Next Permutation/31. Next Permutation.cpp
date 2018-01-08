class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	unsigned int index = nums.size() - 1;
    	while (index != 0 && nums[index - 1] >= nums[index]){
    		index--;
    	}
    	if (0 == index){
    		reverse(nums.begin(), nums.end());
    		return;
    	}
    
    	unsigned int i = nums.size() - 1;
    	while (nums[i] <= nums[index - 1])
    		i--;
    	swap(nums[i], nums[index - 1]);
    	sort(nums.begin() + index, nums.end());
    }
};