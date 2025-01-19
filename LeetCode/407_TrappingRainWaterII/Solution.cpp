class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        
        const int m = heightMap.size();
        const int n = heightMap[0].size();
        
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<bool>> table(m, vector<bool>(n, false));
        for(int i = 1; i < m-1;i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            table[i][0] = true;
            table[i][n-1] = true;
        }
        for(int i = 0; i < n; i++) {
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[m-1][i], {m-1, i}});
            table[0][i] = true;
            table[m-1][i] = true;
        }
        
        int ret = 0;
        while(!pq.empty()) {
            auto [height, pair] = pq.top();
            auto [cur_x, cur_y] = pair;
            pq.pop();
            
            for (int k = 0; k < 4; k++) {
                int x = cur_x + dx[k];
                int y = cur_y + dy[k];
                
                if(x >= 0 && x < m && y >=0 && y < n && table[x][y] == false){
                    if(heightMap[x][y] < height ) {
                        ret += height - heightMap[x][y];
                        pq.push({height, {x, y}});
                    } else {
                        pq.push({heightMap[x][y], {x, y}});
                    }
                    table[x][y] = true;
                }
            }
        }
        return ret;
    }
};
