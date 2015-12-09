class Solution {
public:
    inline void exchange(int &a, int &b)
    {
    	a ^= b;
    	b ^= a;
    	a ^= b;
    }

    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        int i = 0;
    	while (i < nums.size())
    	{
    		if (0 != nums[i])
    		{
    			if (0 == nums[zero]){
    				exchange(nums[i], nums[zero]);
    				zero++;
    			}
    			i++;
    		}
    		else if (0 == nums[i] && 0 != nums[zero])
    			zero = i;
    		else if (0 == nums[i] && 0 == nums[i])
    			i++;
    	}
    }
};