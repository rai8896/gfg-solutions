class Solution {
public:

    int orangesRot(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int,int>, int>> q;

        int vis[n][m];
        memset(vis, 0, sizeof(vis));

        int fresh = 0;

        // Step 1: Put all rotten oranges into queue
        // and count fresh oranges
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 2) {

                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else {

                    vis[i][j] = 0;
                }

                if(mat[i][j] == 1) {

                    fresh++;
                }
            }
        }

        int tm = 0;
        int cnt = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Step 2: BFS
        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;

            q.pop();

            tm = max(tm, t);

            for(int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] != 2 &&
                   mat[nrow][ncol] == 1) {

                    q.push({{nrow, ncol}, t + 1});

                    vis[nrow][ncol] = 2;

                    cnt++;
                }
            }
        }

        // If some fresh oranges cannot become rotten
        if(cnt != fresh) {

            return -1;
        }

        return tm;
    }
};