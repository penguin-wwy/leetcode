class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carryFlag = 1;
        for(vector<int>::iterator iter = digits.end() - 1; ; iter--) {
            int a = *iter + carryFlag;
            *iter = a % 10;
            carryFlag = a / 10;
            if(!carryFlag)
                return digits;
            if(iter == digits.begin())
                break;
        }
    
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};