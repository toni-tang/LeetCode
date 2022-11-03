class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int target = image[sr][sc];
        if(image[sr][sc] == color) return image;
        dfs(image, sr, sc, color, target);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int target)
    {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != target ) 
        {
            return;
        }
        
        image[sr][sc] = color;
             
        dfs(image, sr+1, sc, color, target);
        dfs(image, sr-1, sc, color, target);
        dfs(image, sr, sc+1, color, target);
        dfs(image, sr, sc-1, color, target);
    }
};

// class Solution {
// public:
    
//     void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
//     {
//         if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
//         {
//             return;
//         }

//         image[i][j] = newColor;
//         dfs(image,i-1,j,val,newColor);
//         dfs(image,i+1,j,val,newColor);
//         dfs(image,i,j-1,val,newColor);
//         dfs(image,i,j+1,val,newColor);
//     }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
//     {
//         int val = image[sr][sc];
//         dfs(image,sr,sc,val,newColor);
//         return image;
//     }
// };