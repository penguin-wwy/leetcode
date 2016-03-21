class Solution {
public:
    vector<string> res;
    void solve(int dep, int maxDep, int leftNum, int leftNumTotal, string s){
        if(leftNumTotal * 2 > maxDep)
            return ;
        if(dep == maxDep){
            res.push_back(s);
            return ;
        }
        
        for(int i = 0; i < 2; i++){
            if(0 == i){
                solve(dep + 1, maxDep, leftNum + 1, leftNumTotal + 1, s + '(');
            }
            else{
                    if(leftNum > 0){
                        solve(dep + 1, maxDep, leftNum - 1, leftNumTotal, s + ')');
                }
            }
            
        }
    }

    vector<string> generateParenthesis(int n) {
        res.clear();
        solve(0, 2 * n, 0, 0, "");
        return res;
    }
};