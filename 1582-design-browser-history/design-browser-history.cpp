class BrowserHistory {
public:
    vector<string> history;
    int currentIndex;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currentIndex = 0;
    }

    void visit(string url) {
        // Drop all forward history
        history.resize(currentIndex + 1);
        history.push_back(url);
        currentIndex++;
    }

    string back(int steps) {
        currentIndex = max(0, currentIndex - steps);
        return history[currentIndex];
    }

    string forward(int steps) {
        currentIndex = min((int)history.size() - 1, currentIndex + steps);
        return history[currentIndex];
    }
};
