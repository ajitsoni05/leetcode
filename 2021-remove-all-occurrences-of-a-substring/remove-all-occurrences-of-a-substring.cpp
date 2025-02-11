class Solution {
public:
    string removeOccurrences(string s, string part) {
        if(part.size()>s.size())return s;
        else if(part.size()==s.size() and part !=s)return s;

        string ans=s;

        for(int i=0;i<s.size();i++){
            int matched=0;
            for(int j=0;j<part.size();j++){
                if(s[i+j]==part[j])
                {
                    matched++;
                    cout<<matched<<endl;
                    if(matched==part.size()){
                        string newString= s.substr(0,i)+s.substr(i+part.size());
                        cout<<newString<<endl;
                        ans = newString;
                        return removeOccurrences(newString,part);
                    }
                    continue;
                }
                else break;
            }

        }
        return ans;
    }
};