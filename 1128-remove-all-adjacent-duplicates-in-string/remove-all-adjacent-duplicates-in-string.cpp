class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<int>letters;


        for(int i = 0; i < s.size(); i++){
            if(letters.size()==0){
                letters.push(s[i]);
            }else{
                char c = s[i];

                if(!letters.empty() and c == letters.top())letters.pop();
                else{
                    letters.push(c);
                }
            }
        }
        
        string ans="";

        while(!letters.empty()){
            ans+=letters.top();
            letters.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
        

    }
};