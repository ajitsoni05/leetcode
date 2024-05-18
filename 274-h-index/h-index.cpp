class Solution {
public:
    int hIndex(vector<int>& citations) {
       
        if(citations.size()==1){
            return citations[0]==0?0:1;
        }
        sort(citations.begin(),citations.end(),greater<int>());

        int hindex=0;

        for(int i=0;i<citations.size();i++){
            if(citations[i]>=i+1)hindex=max(hindex,i+1);
        }
        return hindex;
    }
};