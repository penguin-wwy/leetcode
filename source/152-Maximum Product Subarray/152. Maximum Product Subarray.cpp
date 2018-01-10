class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int len = nums.size();
        int s_pro = 1;
        int e_pro = 1;
        int ret = INT_MIN;
        for(int i = 0; i < len; i++) {
            s_pro *= nums[i];
            e_pro *= nums[len - 1 - i];
            ret = max(ret, max(s_pro, e_pro));
            s_pro = s_pro == 0 ? 1 : s_pro;
            e_pro = e_pro == 0 ? 1 : e_pro;
        }
        return ret;
    }
};