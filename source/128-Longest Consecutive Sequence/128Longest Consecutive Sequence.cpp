class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(1 == nums.size() || 0 == nums.size())
            return nums.size();
        unordered_map<int, bool> used;
        for (auto i : nums) used[i] = false;
        int longest = 0;
        for (auto i : nums) 
        {
            if (used[i]) continue;
            int length = 1;
            used[i] = true;
            for (int j = i + 1; used.find(j) != used.end(); ++j) 
            {
                used[j] = true;
                ++length;
            }
            for (int j = i - 1; used.find(j) != used.end(); --j) 
            {
                used[j] = true;
                ++length;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};