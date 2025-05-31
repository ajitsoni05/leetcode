class Solution {
public:
    string reverseVowels(string s) {
        string vow = "";
        if(s==""||s==" ")return s;

        unordered_map<char,int>vowMap;
        vowMap['a']++;
        vowMap['e']++;
        vowMap['i']++;
        vowMap['o']++;
        vowMap['u']++;
        vowMap['A']++;
        vowMap['E']++;
        vowMap['I']++;
        vowMap['O']++;
        vowMap['U']++;

        for(int i = 0; i <s.size();i++){
            if(vowMap.count(s[i])){
                vow += s[i];
            }else{
          
            }
        }

        reverse(vow.begin(),vow.end());


        int iter = 0;
        for(int i = 0; i <s.size();i++){
          if(vowMap.count(s[i]))s[i]=vow[iter++];

        }
        return s;
    }
};