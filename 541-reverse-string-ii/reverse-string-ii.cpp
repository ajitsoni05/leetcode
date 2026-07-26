class Solution {
public:
    int k;
    int n;
    bool checkCondition(string& s, int& ptr){
        int numChars = n - ptr;
        if(ptr < n and numChars < 2*k and numChars >= k ) return true;
        return false;
    }
    string reverseStr(string s, int k) {
        this->k=k;
        this->n = n;
        int ptr = 0;
        int n = s.size();
        while(ptr < n){
            int numChars = n - ptr;
            if(checkCondition(s,ptr)){
                reverse(s.begin(),s.begin() + k);
                break;
            }else if(numChars < k){
                reverse(s.begin() + ptr ,s.end());
                break;
            }else{
                reverse(s.begin()+ptr, s.begin() + ptr +k);
            }
            ptr+=2*k;
        }
        return s;
    }
};