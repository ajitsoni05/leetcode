class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        /*
        
            2 1 2 4 2 2 

            5 2 6 2 3 2 

            find indexes of differences

            find majority number which is present atleast 50 percent then check if it is present on every index of either tops or bottoms
        
        */ 

        int n = tops.size();

        int cand1 = tops[0];
        int cand2 = bottoms[0];

        for(int i = 1; i < n; i++){
            if(tops[i] == cand1 || bottoms[i] == cand1)continue;
            else{
                cand1 = 0;
                break;
            }
        }

        for(int i = 1; i < n; i++){
            if(tops[i] == cand2 || bottoms[i] == cand2)continue;
            else{
                cand2 = 0;
                break;
            }
        }

        int rotationT = 0;
        int rotationB = 0;

        if(cand1 == 0){
            for(int i = 0; i < n; i++){
                if(tops[i] == cand2 and bottoms[i] == cand2){}// do nothing
                else if(tops[i] == cand2)rotationB++;
                else rotationT++;
            }

        }else if(cand2 == 0){
             for(int i = 0; i < n; i++){
                if(tops[i] == cand1 and bottoms[i] == cand1){}// do nothing
                else if(tops[i] == cand1)rotationB++;
                else rotationT++;
            }

        }else{
              for(int i = 0; i < n; i++){
                if(tops[i] == cand2 and bottoms[i] == cand2){}// do nothing
                else if(tops[i] == cand2)rotationB++;
                else rotationT++;
            }

        }

        return cand1 == 0 && cand2 == 0 ? -1 : min(rotationT,rotationB);

    }
};