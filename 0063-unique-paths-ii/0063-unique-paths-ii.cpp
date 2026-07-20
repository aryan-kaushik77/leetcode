class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> arr(n, vector<int>(m, 0));

        // First column
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[i][0] == 1)
                break;
            arr[i][0] = 1;
        }

        // First row
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[0][j] == 1)
                break;
            arr[0][j] = 1;
        }

        // Fill remaining cells
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 1)
                    arr[i][j] = 0;
                else
                    arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
            }
        }

        return arr[n - 1][m - 1];
    }
};