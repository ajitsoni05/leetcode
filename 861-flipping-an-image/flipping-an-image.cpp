class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
       
       
        int r = image.size();

        // flip horizontally reverse()

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < r; j++)image[i][j] = !image[i][j];
            reverse(image[i].begin(), image[i].end());
        }

        // invert 1 -> 0, 0 -> 1
        return image;

        
    }
};