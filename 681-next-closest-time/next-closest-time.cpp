class Solution {
public:
    bool isValid(vector<int>&digitalTime,unordered_map<int,int>&digiMap){
        for(int i = 0; i < 4;i++){
            if(!digiMap.count(digitalTime[i]))return false;
        }
        return true;
    }
    string nextClosestTime(string time) {
        vector<int>digitalTime = {0,0,0,0};

        string numTime = time.substr(0,2)+ time.substr(3);

        for(int i = 0; i < numTime.size(); i++){
            digitalTime[i] = numTime[i]-'0';
        }

        // digiMap
        unordered_map<int,int>digiMap;

        for(int i = 0; i < numTime.size(); i++){
            digiMap[numTime[i]-'0']++;
        }
        int iter = 1000;
        while(iter < 50000){
            iter++;
            int carry = 0;
            digitalTime[3] = (digitalTime[3] + 1 )%10;

            if(digitalTime[3] == 0)carry = 1;

            digitalTime[2] = digitalTime[2] + carry;

            if(digitalTime[2]==6){
                digitalTime[2] = 0;
                carry = 1;
            }else carry = 0;

            if(carry == 1){
               if(digitalTime[0] <= 1){
                digitalTime[1] = (digitalTime[1] + 1)%10;
                if(digitalTime[1] == 0)digitalTime[0]++;
               }else if(digitalTime[0] == 2){
                digitalTime[1] = (digitalTime[1] + 1)%4;
                if(digitalTime[1] == 0){
                    digitalTime[0] = 0;
                    digitalTime[1] = 0;
                    digitalTime[2] = 0;
                    digitalTime[3] = 0;

                }
               }
            }
            if(isValid(digitalTime,digiMap)){
                string ans = "";
                ans += to_string(digitalTime[0]);
                ans += to_string(digitalTime[1]);
                ans += ":";
                ans += to_string(digitalTime[2]);
                ans += to_string(digitalTime[3]);
                return ans;
            }
        }
        return "";
    }
};