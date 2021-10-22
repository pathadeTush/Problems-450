class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        while(row < m){
            if(matrix[row][0] == target or matrix[row][n-1] == target) return true;
            if(matrix[row][0] > target) return false;
            
            
            if(matrix[row][n-1] > target){
                for(int j = 1; j < n-1; j++){
                    if(matrix[row][j] == target) return true;
                }
                return false;
            }
            else
                row++;
            
        }
        return false;
    }
};