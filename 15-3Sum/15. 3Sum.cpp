class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
    	vector<vector<int>> res;
        if(len < 3)
            return res;
        
        sort(nums.begin(), nums.end());

    	for (int i = 0; i < len; i++){
    		if (i > 0 && nums[i] == nums[i - 1])
    			continue;
    		int target = 0 - nums[i];
    		twoSum(nums, i + 1, target, res);
    	}
    	return res;
    }
    
    void twoSum(vector<int> &sortedNum, int start, int target, vector<vector<int> >&res){
    	int head = start, tail = sortedNum.size() - 1;
    	while (head < tail){
    		int tmp = sortedNum[head] + sortedNum[tail];
    		if (tmp < target)
    			head++;
    		else if (tmp > target)
    			tail--;
    		else{
    			res.push_back(vector<int>{sortedNum[start - 1], sortedNum[head], sortedNum[tail]});
    
    			int k = head + 1;
    			while (k < tail && sortedNum[k] == sortedNum[head])
    				k++;
    			head = k;
    
    			k = tail - 1;
    			while (k > head && sortedNum[k] == sortedNum[tail])
    				k--;
    			tail = k;
    		}
    	}
    }
};