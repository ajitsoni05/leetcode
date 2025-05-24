class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long curmass = mass;
        for(auto m:asteroids){
            if(curmass>=m){
                curmass+=m;
            }else{
                return false;
            }
        }
        return true;
    }
};