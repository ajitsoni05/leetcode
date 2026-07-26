class Solution {
public:
    void recurse(int itr, vector<string>& words, vector<int>& scores,
                 vector<int>& charFreq, int curr, int& maxScore) {
        if (itr == words.size()) {
            maxScore = max(maxScore, curr);
            return;
        }

        string currentWord = words[itr];

        bool allowed = true;

        for (char c : currentWord) {
            if (--charFreq[c - 'a'] < 0) {
                allowed = false;
            }
        }

        if (allowed)
            recurse(itr + 1, words, scores, charFreq, curr + scores[itr],
                    maxScore);

        // dont use path
        for (int i = 0; i < currentWord.size(); i++) {
            int ltr = currentWord[i] - 'a';
            charFreq[ltr]++;
        }
        recurse(itr + 1, words, scores, charFreq, curr, maxScore);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {

        // words
        // single letters
        // score
        /*
        words [ abc, dbs, asd ,a]
        scores [ 3, 4,  1,  2]

        // pick or not pick word , recursion
        // let's make scores
        */

        int n = words.size();

        vector<int> scores(n, 0);

        for (int i = 0; i < n; i++) {

            string word = words[i];
            int l = word.size();

            for (int j = 0; j < l; j++) {
                scores[i] += score[word[j] - 'a'];
            }
        }

        // charmap
        vector<int> charFreq(26, 0);

        for (int i = 0; i < letters.size(); i++) {
            charFreq[letters[i] - 'a']++;
        }

        // recurse
        int maxScore = 0;
        recurse(0, words, scores, charFreq, 0, maxScore);

        return maxScore;
    }
};