// 733. Flood Fill 
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) {
            return image;
        }
        dfs(image, sr, sc, color, originalColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int originalColor){

        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()){
            return;
        }
        if (image[sr][sc] != originalColor) return;
        image[sr][sc] = color;
        dfs(image, sr+1, sc, color, originalColor);
        dfs(image, sr-1, sc, color, originalColor);
        dfs(image, sr, sc+1, color, originalColor);
        dfs(image, sr, sc-1, color, originalColor);

    }
};