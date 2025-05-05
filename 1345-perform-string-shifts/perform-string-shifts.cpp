class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        
        int n = shift.size();
        int m = s.size();
        // let's check the net shift first;
        int lft = 0;
        int rft = 0;
        for(int i=0;i<n;i++){
            if(shift[i][0]==1){
                rft+= shift[i][1];
            }else{
                lft += shift[i][1];
            }
        }

        int net = abs(rft - lft);
        int dir = rft > lft ? 1 : 0;
        net = net % m;
        if(net == 0) return s;
        if(dir){
            reverse(s.begin(),s.end());
            reverse(s.begin(),s.begin()+net);
            reverse(s.begin()+net,s.end());
        }else{
            reverse(s.begin(),s.end());
            reverse(s.begin(),s.begin()+m-net);
            reverse(s.begin()+m-net,s.end());

        }
        // abc -> cba 
        // bca 



      return s;
    }
};