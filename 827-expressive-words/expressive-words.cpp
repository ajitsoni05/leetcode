class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> keys;

        int count = 1;
        char c = s[0];

        int res = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == c) {
                count++;
            } else {
                keys.push_back({c, count});
                c = s[i];
                count = 1;
            }
        }
        keys.push_back({c, count}); // FIX: push last group of s



        for (auto word : words) {
            vector<pair<char, int>> wordKeys;

            int count = 1;
            char c = word[0];

            for (int i = 1; i < word.size(); i++) {
                if (word[i] == c) {
                    count++;
                } else {
                    wordKeys.push_back({c, count});
                    c = word[i];
                    count = 1;
                }
            }
            wordKeys.push_back({c, count}); // FIX: push last group of word

            // compare wordKeys and keys

            if(wordKeys.size() != keys.size()) continue;
            else{
                bool match = true; // FIX: use flag to control inner loop
                for(int i = 0; i < keys.size(); i++){
                    if(wordKeys[i].first == keys[i].first && wordKeys[i].second <= keys[i].second && (wordKeys[i].second == keys[i].second || keys[i].second >= 3)) // FIX: correct stretchy condition
                    {
                        continue;
                    }
                    else {
                        match = false;
                        break;
                    }

                    
                }
                if(match) res++; // FIX: increment only if all groups matched
            }
        }
        return res;
    }
};