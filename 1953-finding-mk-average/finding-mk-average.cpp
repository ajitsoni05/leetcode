class MKAverage {
public:
    queue<int>q;
    map<int,int>mp;
    map<int,int,greater<int>>rmp;
    long long tot;
    int K;
    int M;

    MKAverage(int m, int k) {
        tot = 0;
        M = m;
        K = k;
    }
    
    void addElement(int num) {
        if(q.size()<M){
            q.push(num);
            mp[num]++;
            rmp[num]++;
            tot+= num;
        }else{
            int r = q.front();
            tot-=r;
            q.pop();
            mp[r]--;
            rmp[r]--;
            q.push(num);
            mp[num]++;
            rmp[num]++;
            tot+=num;
        }
    }
    
    int calculateMKAverage() {
        // subtract from tot
        if(q.size()<M) return -1;
        int iter = K;
        int total = tot;
        for(auto it:mp){
            int temp = it.second;
            while(iter and temp){
                total -= it.first;
                iter--;
                temp--;
            }

        }
        iter = K;
        for(auto it:rmp){
            int temp = it.second;
            while(iter and temp){
                total -= it.first;
                iter--;
                temp--;
            }

        }
        return total/(M-2*K);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */