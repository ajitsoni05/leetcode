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
    q.push(num);
    mp[num]++;
    rmp[num]++;
    tot += num;

    if (q.size() > M) {
        int r = q.front(); q.pop();
        mp[r]--;
        if (mp[r] == 0) mp.erase(r);

        rmp[r]--;
        if (rmp[r] == 0) rmp.erase(r);

        tot -= r;
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