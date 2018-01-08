class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (0 == n)
            return false;
        int i = 1;
    	int res = 0;
    	while(0 == (res = n & i))
    		n = n >> 1;
    	if(1 == n)
    		return true;
    	else
    		return false;
    }
};