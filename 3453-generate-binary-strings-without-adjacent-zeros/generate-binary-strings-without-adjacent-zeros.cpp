class Solution {
public:
    vector<string> validStrings(int n) {
      string temp="";
      long long maxNum=pow(2,n);
      vector<string>ans;
      for(int i=0;i<n;i++)temp+="0";
      
      for(int i=1;i<=maxNum;i++){
        string temp1=temp;
        int cnt=0;
        bool exceed=false;
        // i = 3 , 101
        for(int j=0;j<=n;j++){
            // 3 
            // 0 , 1 , 2,3 
            if(cnt==2)exceed=true;
            if((1<<j)&i){temp1[j]='1';cnt=0;}
            else{cnt++;}
        }
        reverse(temp1.begin(),temp1.end());
        if(!exceed)
        ans.push_back(temp1);
      }
      return ans;
    }
};