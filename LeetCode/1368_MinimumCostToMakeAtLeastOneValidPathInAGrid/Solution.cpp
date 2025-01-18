class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        deque<pair<int, int>> dq;
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dq.push_front({0, 0});
        dist[0][0] = 0;
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int current_x = x + dx[i];
                int current_y = y + dy[i];
                if (current_x >= 0 && current_x < m && current_y >= 0 && current_y < n) {
                    bool isSameDirection = (i + 1 == grid[x][y]);
                    int cost = isSameDirection ? 0 : 1;

                    if (dist[x][y] + cost < dist[current_x][current_y]) {
                        dist[current_x][current_y] = dist[x][y] + cost;
                        if (isSameDirection) {
                            dq.push_front({current_x, current_y});
                        } else {
                            dq.push_back({current_x, current_y});
                        }
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};
