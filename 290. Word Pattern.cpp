class Solution {
public:
    bool wordPattern(string pattern, string str) {
	unordered_map<char, string> map1;
	unordered_map<string, char> map2;
	vector<string> res;
	int j = 0;
	for (int i = 0; ; i++){
		if (str[i] == ' '){
			string tmp = str.substr(j, i - j);
			j = i + 1;
			res.push_back(tmp);
		}

		if (i == str.size() - 1){
			string tmp = str.substr(j, i - j + 1);
			res.push_back(tmp);
			break;
		}
	}

	if (pattern.size() != res.size())
		return false;
	for (int i = 0; i < res.size(); i++){
		if (map1.find(pattern[i]) == map1.end() && map2.find(res[i]) == map2.end()){
			map1.insert(pair<char, string>(pattern[i], res[i]));
			map2.insert(pair<string, char>(res[i], pattern[i]));
		}
		else if (map1[pattern[i]] != res[i] || map2[res[i]] != pattern[i])
			return false;
	}
	return true;
    }
};