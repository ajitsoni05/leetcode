class Solution {
public:
    bool isSubsequence(string s, string word){
        if(word.size() > s.size()) return false;

        int wordIter = 0;
        int wordLen = word.size();


        for(int i = 0; i < s.size(); i++){
            if(wordIter < wordLen){
                if(word[wordIter] == s[i])wordIter++;
            }else return true;
        }
        if(wordIter >= wordLen)return true;

        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        

        /*
        
        check if the word of the dictionary is a subsequence of the string
        if yes store it as candidate ans

        iterate in the loop and check for other words of greater length, then compare
        
        */

        int dLen = dictionary.size();
        int maxLen = 0;
        string cand = "";
        for(int i = 0; i < dLen; i++){
            string word = dictionary[i];
            if(word.size() >= maxLen) {
                string word = dictionary[i];
                if(isSubsequence(s,word)) {
                
                if(cand == "" || word.size() > cand.size() || lexicographical_compare(word.begin(),word.end(),cand.begin(),cand.end())) {
                cand = word;
                maxLen = max(maxLen,(int)word.size());
                }
                }
            }
        }
        return cand;
    }
};