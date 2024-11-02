class MinStack {
public:
    // STL
    stack<int>st;
    stack<pair<int,int>>minstack;
    
    MinStack() {
        
    }
    
    void push(int val) {

        st.push(val);

        if(minstack.empty()||val<minstack.top().first){
            minstack.push({val,1});
        }else if(minstack.top().first==val){
            pair<int,int>p = minstack.top();
            minstack.pop();
            p.second++;
            minstack.push(p);
        }
        
    }
    
    void pop() {
        if(st.empty()){
            return ;
        }else{
            int val=st.top();
            st.pop();
            if(val==minstack.top().first){
                
                if(minstack.top().second>1){
                     pair<int,int>p = minstack.top();
                        minstack.pop();
                        p.second--;
                        minstack.push(p);
                }else{
                    minstack.pop();
                }

            }
        }
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        if(!minstack.empty())return minstack.top().first;
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */