class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // let's map the order into order map
        unordered_map<char,int>chMap;


        for(int i =0; i <order.size();i++){
            chMap[order[i]]=i;
        }

        for(int i = 0; i<words.size()-1;i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int iter1 = 0;
            int iter2 = 0;
            int m = word1.size();
            int n = word2.size();

            bool allEqual = true;
            while(iter1 < m and iter2 < n){
                if(chMap[word1[iter1]] > chMap[word2[iter2]])return false;
                else if(chMap[word1[iter1]]<chMap[word2[iter2]]){
                    allEqual = false;
                    break;
                }

                iter1++;
                iter2++;
            }

            if(allEqual and iter1<m)return false;
        }

        return true;
    }
};