class Solution {
public:
    vector<int> grayCode(int n) {
        if(0 == n)
            return vector<int>(1, 0);
        vector<int> pre_vec = grayCode(n - 1);
        vector<int> result(pre_vec);
        for(int i = pre_vec.size() - 1; i >= 0; i--){
            result.push_back((1 << (n - 1)) + pre_vec[i]);
        }
        return result;
    }
};