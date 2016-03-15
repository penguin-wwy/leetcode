class Solution {
public:
    bool isValid(string s) {
        if (0 == s.length())
    		return true;
    	stack<char> st;
    	int index = 0;
    	int len = s.length();
    
    	while (index < len)
    	{
    		char c = s[index];
    
    		if ('}' != c && ']' != c && ')' != c){
    			st.push(c);
    		}
    		else{
    			if (st.empty())
    				return false;
    			
    			char Cur = st.top();
    			switch (c)
    			{
    			case ')':
    				if ('(' == Cur)
    					st.pop();
    				else
    					return false;
    				break;
    			case '}':
    				if ('{' == Cur)
    					st.pop();
    				else
    					return false;
    				break;
    			case ']':
    				if ('[' == Cur)
    					st.pop();
    				else
    					return false;
    				break;
    			}
    		}
    		index++;
    	}
    
    	if (st.empty())
    		return true;
    	else
    		return false;
    }
};