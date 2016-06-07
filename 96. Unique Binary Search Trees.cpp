/*
f(i) = f(0) + f(i-1) + f(1) * f(i-2) + ... + f(i-1) * f(0)
*/

class Solution {
public:
    int numTrees(int n) {
        if(0 == n)
            return 0;
        vector<int> num(n + 1, 0);
        num[0] = 1;
        num[1] = 1;
        if(1 == n)
            return num[1];
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                num[i] += num[j - 1] * num[i - j];
            }
        }
        return num[n];
    }
};