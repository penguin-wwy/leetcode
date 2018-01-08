class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty())
            return "";
            
        std::stack<string> st;
        int i = 0;
        while(i < path.size()){
            while(i < path.size() && path[i] == '/')
                i++;
            string s = "";
            while(i < path.size() && path[i] != '/')
                s += path[i++];
            if(s == ".." && !st.empty())
                st.pop();
            else if(s != ".." && s != "." && s != "")
                st.push(s);
        }
        
        if(st.empty())
            return "/";
        
        string s = "";
        while(!st.empty()){
            s = "/" + st.top() + s;
            st.pop();
        }
        return s;
    }
};