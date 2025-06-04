class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;

        for(int i =0 ; i < operations.size();i++){

            if(operations[i]=="C"){
                if(!s.empty())s.pop();
            }else if(operations[i]=="D"){
                if(!s.empty()){
                    int top = s.top();
                    s.push(2*top);
                }
            }else if(operations[i]=="+"){
                if(s.size()>=2){
                    int a = s.top();
                    s.pop();
                    int b = s.top();s.pop();
                    s.push(b);
                    s.push(a);
                    s.push(a+b);
                    
                }
            }else{
                s.push(stoi(operations[i]));
            }
        }
        int sum = 0;
        while(!s.empty()){
            sum += s.top();s.pop();
        }
        return sum;
    }
};