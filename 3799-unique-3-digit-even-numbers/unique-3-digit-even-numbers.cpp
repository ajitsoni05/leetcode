class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int>numSet;
        for(int i = 0; i < digits.size(); i++){
            for(int j = 0; j < digits.size(); j++){
                for(int k = 0; k < digits.size(); k++){
                    if(i == j || j == k || k == i)continue;

                    int num = digits[i]*100 + digits[j]*10 + digits[k];

                    if(digits[i]!=0 and num%2 == 0)numSet.insert(num);
                }

            }
        }
        return numSet.size();
    }
};