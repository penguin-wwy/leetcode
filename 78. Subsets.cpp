class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return vector<vector<int>>();
        vector<vector<int>> result;
        vector<int> path;
        result.push_back(path);
        dfs(nums, 0, path, result);
        return result;
    }
    
    void dfs(vector<int>& nums, int pos, vector<int>& path, vector<vector<int>>& result)
    {
        if(pos == nums.size())
            return ;
        for(int i = pos; i < nums.size(); i++){
            path.push_back(nums[i]);
            result.push_back(path);
            dfs(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};