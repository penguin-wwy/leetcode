class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
    		return 0;
    	vector<int>::iterator abc = nums.end() - 1;
    	while (*abc == val){
    		if (abc == nums.begin()){
    			nums.clear();
    			return 0;
    		}
    		abc--;
    	}
    	for (vector<int>::iterator elem = nums.begin(); elem != abc && elem != nums.end(); ++elem){
    		if (*elem == val){
    		    swap(*elem, *abc);
    		    abc--;
    		}
    		while (*abc == val)
    			abc--;
    		if(elem == abc)
    		    break;
    	}
    	vector<int> nums_cpy(nums.begin(), abc + 1);
    	nums_cpy.swap(nums);
    	return nums.size();
    }
};