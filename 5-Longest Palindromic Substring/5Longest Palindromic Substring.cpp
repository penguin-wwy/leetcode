class Solution {//时间复杂度O(n^2) 空间复杂度O(n^2)
public:
    string longestPalindrome(string s) {
        if (0 == s.length())
    		return "";
    	int len = s.length(), maxlen = 0;
    	int palin[1000][1000] = { 0 };
    	string res = "";
    	for (int i = len - 1; i >= 0; i--){
    		for (int j = i; j < len; j++){
    			if (s[i] == s[j] && (j - i <= 2 || palin[i + 1][j - 1])){
    				palin[i][j] = 1;
    				if (maxlen < j - i + 1){
    					maxlen = j - i + 1;
    					res = s.substr(i, maxlen);
    				}
    			}
    		}
    	}
    	return res;
    }
};

//时间复杂度O(n^2)空间复杂度O(1)
string expandAroundCenter(string s, int c1, int c2) {
 2   int l = c1, r = c2;
 3   int n = s.length();
 4   while (l >= 0 && r <= n-1 && s[l] == s[r]) {
 5     l--;
 6     r++;
 7   }
 8   return s.substr(l+1, r-l-1);
 9 }
10  
11 string longestPalindromeSimple(string s) {
12   int n = s.length();
13   if (n == 0) return "";
14   string longest = s.substr(0, 1);  
15   for (int i = 0; i < n-1; i++) {
16     string p1 = expandAroundCenter(s, i, i);
17     if (p1.length() > longest.length())
18       longest = p1;
19  
20     string p2 = expandAroundCenter(s, i, i+1);
21     if (p2.length() > longest.length())
22       longest = p2;
23   }
24   return longest;
25 }

public class Solution {//http://www.cnblogs.com/bitzhuwei/p/Longest-Palindromic-Substring-Part-II.html
 2     // 时间空间复杂度都是O(n)
 5     String preProcess(String s) {
 6         int n = s.length();
 7         if (n == 0) return "^$";
 8 
 9         String ret = "^";
10         for (int i = 0; i < n; i++)
11         {
12             ret += "#" + s.substring(i, i + 1);
13         }
14         
15         ret += "#$";
16         return ret;
17     }
18     public String longestPalindrome(String s) {
19         String T = preProcess(s);
20         int length = T.length();
21         int[] p = new int[length];
22         int C = 0, R = 0;
23         
24         for (int i = 1; i < length - 1; i++)
25         {
26             int i_mirror = C - (i - C);
27             int diff = R - i;
28             if (diff >= 0)//当前i在C和R之间，可以利用回文的对称属性
29             {
30                 if (p[i_mirror] < diff)//i的对称点的回文长度在C的大回文范围内部
31                 { p[i] = p[i_mirror]; }
32                 else
33                 {
34                     p[i] = diff;
35                     //i处的回文可能超出C的大回文范围了
36                     while (T.charAt(i + p[i] + 1) == T.charAt(i - p[i] - 1))
37                     { p[i]++; }
38                     C = i;
39                     R = i + p[i];
40                 }
41             }
42             else
43             {
44                 p[i] = 0;
45                 while (T.charAt(i + p[i] + 1) == T.charAt(i - p[i] - 1))
46                 { p[i]++; }
47                 C = i;
48                 R = i + p[i];
49             }
50         }
51 
52         int maxLen = 0;
53         int centerIndex = 0;
54         for (int i = 1; i < length - 1; i++) {
55             if (p[i] > maxLen) {
56               maxLen = p[i];
57               centerIndex = i;
58             }
59         }
60         return s.substring((centerIndex - 1 - maxLen) / 2, (centerIndex - 1 - maxLen) / 2 + maxLen);        
61     }
62 }