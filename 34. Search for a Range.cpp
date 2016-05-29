class Solution {
public:

    int find_pos(vector<int>& nums, int beg, int end, int value, bool findleft)
    {
    	int mid = 0;
    	if (findleft == true){
    		while (beg <= end){
    			mid = (beg + end) / 2;
    			if (nums[mid] < value){
    				beg = mid + 1;
    			}
    			else {
    				end = mid - 1;
    			}
    		}
    		if (nums[beg] != value)
    			return -1;
    		return beg;
    	}
    	else{
    		while (beg <= end){
    			mid = (beg + end) / 2;
    			if (nums[mid] > value){
    				end = mid - 1;
    			}
    			else{
    				beg = mid + 1;
    			}
    		}
    		if (nums[end] != value)
    			return -1;
    		return end;
    	}
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size() - 1;
        int left = find_pos(nums, 0, len, target, true);
        //if(left != -1)
        //    left += 1;
        int right = find_pos(nums, 0, len, target, false);
        //if(right != -1)
        //    right += 1;
        
        vector<int> arr;
        arr.push_back(left);
        arr.push_back(right);
        return arr;
    }
};