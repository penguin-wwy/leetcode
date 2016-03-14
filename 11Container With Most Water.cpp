class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
    	int max_water = 0;
    	while (left != right)
    	{
    		const int water = min(height[left], height[right]) * (right - left);
    		if(water > max_water)
    		    max_water = water;
    		if(height[left] < height[right])
    		    left++;
    		else
    		    right--;
    	}
    	return max_water;
    }
};