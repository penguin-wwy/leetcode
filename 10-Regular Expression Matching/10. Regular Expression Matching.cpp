class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.length() == 0 && p.length() == 0)
            return true;
        if(p.length() == 0)
            return false;
        vector< vector<bool> > res(s.length() + 1, vector<bool>(p.length() + 1));
        res[0][0] = true;
        for(int j = 0; j < p.length(); j++) {
            if(p.at(j) == '*') {
                if(j > 0 && res[0][j - 1])
                    res[0][j + 1] = true;
                if(j < 1)
                    continue;
                if(p.at(j - 1) != '.') {
                    for(int i = 0; i < s.length(); i++) {
                        if(res[i + 1][j] || (j > 0 && res[i + 1][j - 1])
                        || i > 0 && j > 0 && res[i][j + 1] && s[i] == s[i - 1] && s[i - 1] == p[j - 1])
                            res[i + 1][j + 1] == true;
                    }
                } else {
                    int i = 0;
                    while(j > 0 && i < s.length() && !res[i + 1][j - 1] && !res[i + 1][j])
                        i++;
                    for(; i < s.length(); i++)
                        res[i + 1][j + 1] = true;
                }
            } else {
                for(int i = 0; i < s.length(); i++) {
                    if(s[i] == p[j] || p[j] == '.')
                        res[i + 1][j + 1] = true;
                }
            }
        }
        return res[s.length()][p.length()];
    }
};