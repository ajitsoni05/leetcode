class Solution {
public:
    static bool comp(const int&a,const int&b){
        int bitCA=0,bitCB=0;
        for(int i=31;i>=0;i--){
            if((a>>i)&1)bitCA++;
            if((b>>i)&1)bitCB++;

        }
        if(bitCA == bitCB) return a<b;
        return bitCA < bitCB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};