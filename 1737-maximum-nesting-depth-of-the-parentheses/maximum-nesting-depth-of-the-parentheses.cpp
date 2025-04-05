class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;

        int maxmSize=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                maxmSize = max(maxmSize,(int)st.size());
            }else if(s[i]==')'){
                st.pop();
            }
        }
        return maxmSize;
    }
};