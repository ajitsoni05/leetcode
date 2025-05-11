class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

       // get the supplies set
       unordered_set<string>availSupplies;
       
       // add supply into set
       for(auto& supply:supplies){
        availSupplies.insert(supply);
       }

       // rec to index
       unordered_map<string,int>rToI;
       for(int i=0;i<recipes.size();i++){
        rToI[recipes[i]]=i;
       }

       // create inDegree array for recipes
       vector<int>inDegree(recipes.size(),0);

        // adjacencyList for ingredient
        unordered_map<string,vector<string>>depG;

       for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(!availSupplies.count(ingredients[i][j])){inDegree[i]++;
                depG[ingredients[i][j]].push_back(recipes[i]);}
            }
       }    

       queue<string>queue;



       for(int i=0;i<inDegree.size();i++){
        if(inDegree[i]==0){
            queue.push(recipes[i]);
        }
       }

       vector<string>createdRec;

       while(!queue.empty()){
        string current = queue.front();
        queue.pop();
        createdRec.push_back(current);
        if(!depG.count(current))continue;

        for(auto it:depG[current]){
            inDegree[rToI[it]]--;
            if( inDegree[rToI[it]] == 0)queue.push(it);
        }

       }

       return createdRec;


       

    }
};