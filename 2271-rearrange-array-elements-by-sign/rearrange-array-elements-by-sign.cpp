class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;

        vector<int>pos;
        vector<int>neg;

        static int n;
        for(auto it:nums){
            if(it<0){
                n=0;
                neg.push_back(it);
            }
            else{
                n=1;
            pos.push_back(it);

            }
        }

        if(n==0){
            reverse(neg.begin(),neg.end());
            reverse(pos.begin(),pos.end());

            while(neg.size() || pos.size()){
              

                if(pos.size()){
                    ans.push_back(pos.back());
                    pos.pop_back();
                }
                  if(neg.size()){
                    ans.push_back(neg.back());
                    neg.pop_back();
                }
            }
        }else{
        reverse(neg.begin(),neg.end());
        reverse(pos.begin(),pos.end());

            while(neg.size() || pos.size()){
               

                if(pos.size()){
                    ans.push_back(pos.back());
                    pos.pop_back();
                }
                 if(neg.size()){
                    ans.push_back(neg.back());
                    neg.pop_back();
                }
            }
        }
        return ans;
        
    }
};