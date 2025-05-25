class Solution {
public:
    // kmp for string matching
    bool isMatch(string sub, string full){
        // kmp array for sub
        int sub_len = sub.size();
        vector<int>kmp(sub_len,0);

        int n = sub.size();
        // iterators
        int i = 1, j = 0;

        while(i < sub_len){
            if(sub[i] == sub[j]){
                kmp[i] = j+1;
                j++;
                i++;
            }else{
                if( j > 0){
                    j = kmp[j-1];
                }else{
                    kmp[i] = 0;
                    i++;
                }
            }
        }

        int sub_iter = 0;
        int full_iter = 0;

        int m = full.size();
        while(full_iter < m){
            if(sub[sub_iter] == full[full_iter]){
                if(sub_iter == n-1)return true;
                sub_iter++;
                full_iter++;
            }else{
                if(sub_iter > 0){
                    sub_iter = kmp[sub_iter-1];
                }else{
                    full_iter++;
                }
            }
        }

        return false;
    }
    int repeatedStringMatch(string a, string b) {
        
        string temp = a;
        int iter =0;


        int max_repeats = (b.size() / a.size()) + 2;
        while(iter < max_repeats){
           

            if(isMatch(b,a))return iter+1;
            a+=temp;
            iter++;



        }
        return -1;

    

    }
};