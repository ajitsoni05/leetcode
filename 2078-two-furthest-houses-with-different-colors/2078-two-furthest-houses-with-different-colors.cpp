class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int maxm=0;
        int c1=colors[0];
        int c2=colors[colors.size()-1];
        
        for(int i=0;i<colors.size();i++){
            if(colors[i]!=c2){
                maxm=max(maxm,(int)colors.size()-1-i);
                break;
            }
        }
         
        for(int i=colors.size()-1;i>=0;i--){
            if(colors[i]!=c1){
                maxm=max(maxm,i);
                break;
            }
        }
        return maxm;
    }
};