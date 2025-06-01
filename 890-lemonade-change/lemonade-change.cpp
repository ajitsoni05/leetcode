class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>bill(21,0);

        for(int i =0;i <bills.size();i++){
            bill[bills[i]]++;
            if(bills[i]==20){
                if(bill[10] and bill[5]){
                    bill[10]--;
                    bill[5]--;
                }else if(bill[5] and bill[5]>=3){
                    bill[5]-=3;
                }else{
                    return false;
                }
            }else if(bills[i]==10){
                 if(bill[5]){
                    bill[5]--;
                }else{
                    return false;
                }
            }


        }
        return true;
    }
};