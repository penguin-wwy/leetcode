class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.length();  
        if (length <= 1 || numRows <= 1 || numRows >= length) return s;  
        string result = "";  
          
        int current, next, nnext;  
          
        for (int i = 0; i < numRows; i++)  
        {  
            result += s[i]; 
            current = i; 
            while (true)  
            {  
                next = 2 * (numRows - i - 1); 
                nnext = 2 * i;
                  
                if (next != 0)  
                {  
                    current += next;  
                    if (current < length) result += s[current];  
                    else break;  
                }  
                  
                if (nnext != 0)  
                {  
                    current += nnext;  
                    if (current < length) result += s[current];  
                    else break;  
                }  
            }  
        }  
        return result;  
    }  
};