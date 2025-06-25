class Solution {
public:
    int sum;
    vector<double>prob;
    Solution(vector<int>& w) {
        srand(time(NULL)); 
        sum = 0;
        for(int i = 0; i < w.size(); i++){
            sum += w[i];
        }

        double running_prob = 0;
        for(int i = 0; i < w.size(); i++){
            running_prob += (w[i]/(sum+0.0))*100.0;

            prob.push_back(running_prob);
        }
    }
    
    int pickIndex() {
        double random = ((double) rand() / RAND_MAX) * 100.0;
        auto it = lower_bound(prob.begin(),prob.end(),random);
        return it-prob.begin();
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */