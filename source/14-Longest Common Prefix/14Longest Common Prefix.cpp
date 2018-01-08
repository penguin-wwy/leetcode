class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        	int len = strs.size();
    	if (0 == len)
    		return "";
    	if (1 == len)
    		return strs[0];
    	char s = strs[0][0];
    	for (int i = 1; i < len; i++){
    		if (s != strs[i][0] || '\0' == s)
    			return "";
    	}
    	int temp = strs[0].size();
    	if (temp > strs[1].size())
    		temp = strs[1].size();
    	int index = 0;
    	string res = "";
    	while (index < temp){
		if (strs[0][index] == strs[1][index]){
			index++;
		}
		else
			break;
    	}
	    res = strs[0].substr(0, index);
    
    	index = 0;
    	int finall = res.size() - 1;
    	for (int i = 2; i < len; i++){
    		index = finall;
    		while (index > strs[i].size() || res[index] != strs[i][index]){
    			index--;
    		}
    		if (index != finall){
    			res = res.substr(0, index + 1);
    			finall = res.size();
    		}
    	}
    
    	return res;
    }
};