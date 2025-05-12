class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        // get the unique chars
        unordered_map<char,int>chars;

        //adj
        unordered_map<char,vector<char>>adj;

        for(auto& word:words){
            for(auto& c:word){
                chars[c] = 0;
                adj[c] = vector<char>();

            }
        }

        for(int i=0;i<words.size()-1;i++){
            string word1= words[i];
            string word2= words[i+1];

            // check if word2 is small and prefix
            if(word2.size()<word1.size() and word1.substr(0,word2.size())==word2){
                return "";
            }

            for(int j=0;j<min(word1.size(),word2.size());j++){
                if(word1[j]!=word2[j]){
                    adj[word1[j]].push_back(word2[j]);
                    chars[word2[j]]++;
                    break;
                }
            }

        }

        // store the sequence
        string seq="";

        // get a queue 
        queue<char>q;

        // check chars with incoming edge 0;
       for(auto c:chars){
        if(c.second == 0){
            q.push(c.first);
        }
       }

       // lets do the traversal

       while(!q.empty()){
       
        char node = q.front();
        q.pop();
        seq+=node;

        for(auto nbC:adj[node]){
            if(--chars[nbC]==0)q.push(nbC);
        }
       }
    
      cout<<seq<<endl;
      return seq.size() != chars.size() ? "" : seq;
    }
};