class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(),s.end());

        int r = 0;
        int l = 0;
        int n = s.size();

        while(r != n){

            while(r<n and s[r] != ' '){
                r++;
            }
            if(r>n)break;
            reverse(s.begin()+l,s.begin()+r);
            l = r+1;
            r ++;
        }

    }
};