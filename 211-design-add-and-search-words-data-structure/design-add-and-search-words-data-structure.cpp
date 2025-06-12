class Tn {
public:
    vector<Tn*> children;
    bool isTerm;

    Tn() : isTerm(false) {
        children.resize(26, nullptr);
    }
};

class WordDictionary {
public:
    Tn* t;

    WordDictionary() {
        t = new Tn();
    }

    void addWord(string word) {
        Tn* temp = t;
        for (char ch : word) {
            int c = ch - 'a';
            if (!temp->children[c]) {
                temp->children[c] = new Tn();
            }
            temp = temp->children[c];
        }
        temp->isTerm = true;
    }

    bool search(string word) {
        return dfs(word, t, 0);
    }

private:
    bool dfs(const string& word, Tn* node, int depth) {
        if (!node) return false;
        if (depth == word.size()) return node->isTerm;

        char ch = word[depth];
        if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                if (dfs(word, node->children[i], depth + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int c = ch - 'a';
            return dfs(word, node->children[c], depth + 1);
        }
    }
};
