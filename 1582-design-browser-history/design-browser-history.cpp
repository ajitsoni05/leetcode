class BrowserHistory {
public:
    deque<string>dq;
    deque<string>::iterator latest = dq.end();
    BrowserHistory(string homepage) {
        dq.push_back(homepage);
        latest = dq.begin();
    }
    
    void visit(string url) {
        dq.erase(latest+1,dq.end());
        dq.push_back(url);
        latest = dq.end()-1;

        
    }
    
    string back(int steps) {
        
        while(latest != dq.begin() and steps > 0){
            latest--;
            steps--;
        }
        return *latest;
        
    }
    
    string forward(int steps) {
        while(latest !=dq.end() and steps >0){
            latest++;
            steps--;
        }
        if(latest == dq.end()){
            latest--;
        }
        return *latest;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */