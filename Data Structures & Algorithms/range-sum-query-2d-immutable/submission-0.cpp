class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = matrix[0].size();
        vector<vector<int>> sumMat(nrows, vector<int>(ncols, 0));
        sumMat[0][0] = matrix[0][0];
        for(int i = 1; i < ncols; i++) sumMat[0][i] = sumMat[0][i-1] + matrix[0][i];
        for(int i = 1; i < nrows; i++) sumMat[i][0] = sumMat[i-1][0] + matrix[i][0];
        for(int i = 1; i < nrows; i++){
            for(int j = 1; j < ncols; j++){
                sumMat[i][j] = sumMat[i-1][j] - sumMat[i-1][j-1] + sumMat[i][j-1] + matrix[i][j];
            }
        }
        preSum = sumMat;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = preSum[row2][col2];
        if(col1 - 1 >= 0) ans -= preSum[row2][col1-1];
        if(row1 - 1 >= 0) ans -= preSum[row1-1][col2];
        if(row1 -1 >= 0 && col1 -1 >= 0) ans += preSum[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */