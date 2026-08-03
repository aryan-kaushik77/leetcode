class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = '#';       
                }
            }
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};


        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};