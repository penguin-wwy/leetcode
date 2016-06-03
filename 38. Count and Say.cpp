class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return string("1");
        }
        string prev = countAndSay(n-1);
    
        int before = 0;
        int count = 0;
        string curr;
        for (int i = 0; i < prev.length(); ++i) {
            if (prev[i]-'0' == before) {
                count++;
                continue;
            } else if (before != 0) {
                curr.append(1, '0' + count);
                curr.append(1, '0' + before);
            }
            before = prev[i]-'0';
            count = 1;
        }
        if (before != 0 && count != 0) {
            curr.append(1, '0' + count);
            curr.append(1, '0' + before);
        }
        return curr;
    }
};