class Tn {
public:
    vector<Tn*> children;
    bool isTerm;

    Tn() : isTerm(false) { children.resize(26, nullptr); }
};
class Solution {
public:
    Tn* t;
    void insert(string word) {
        Tn* temp = t;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i] - 'a';
            if (!temp->children[c]) {
                temp->children[c] = new Tn();
            }
            temp = temp->children[c];
        }
        temp->isTerm = true;
    }
    string search(string word) {
        Tn* temp = t;
        string tmp = "";
        for (int i = 0; i < word.size(); i++) {
            char c = word[i] - 'a';
            if (!temp->children[c])
                return word;
            temp = temp->children[c];
            tmp += word[i];
            if (temp->isTerm)
                return tmp;
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        t = new Tn();

        for (int i = 0; i < dictionary.size(); i++) {
            string word = dictionary[i];
            insert(word);
        }

        stringstream ss(sentence);

        string ans = "";

        string temp = "";

        while (ss >> temp) {
            string str = search(temp);
            ans += str + " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
};