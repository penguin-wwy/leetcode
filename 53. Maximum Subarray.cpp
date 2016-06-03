class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int cur = 0;
        int max = 0x80000000;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || cur <= 0)
                cur = nums[i];
            else
                cur += nums[i];
            if(max <= cur)
                max = cur;
        }
        return max;
    }
};