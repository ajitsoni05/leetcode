class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;

        for(int i =0;i <bills.size();i++){
            cout<<bills[i]<<" ";
            if(bills[i]==20){
                mp[20]++;
                if(mp.count(10) and mp.count(5)){
                    mp[10]--;
                    mp[5]--;
                    if(mp[10]==0)mp.erase(10);
                    if(mp[5]==0)mp.erase(5);
                }else if(mp.count(5) and mp[5]>=3){
                    mp[5]-=3;
                    if(mp[5]==0)mp.erase(5);
                }else{
                    return false;
                }
            }else if(bills[i]==10){
                 mp[10]++;
                 if(mp.count(5)){
                    mp[5]--;
                    if(mp[5]==0)mp.erase(5);
                }else{
                    return false;
                }
            }else{
                mp[5]++;
            }


        }
        return true;
    }
};