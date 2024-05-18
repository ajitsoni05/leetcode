class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cost_s=0;
        int gas_s=0;
        int n=cost.size();
        for(int i=0;i<n;i++){
            cost_s+=cost[i];
            gas_s+=gas[i];
        }
        if(cost_s>gas_s)return -1;

        int idx=-1;
        int tot=0;
        for(int i=0;i<gas.size();i++){
            tot+=(gas[i]-cost[i]);
            if(tot<0){
                tot=0;
                idx=-1;
                continue;
            }else if(idx==-1){
                idx=i;
            }
        }
        return idx;
    }
};