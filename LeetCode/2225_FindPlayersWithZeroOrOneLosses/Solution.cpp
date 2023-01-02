class Solution {
public:
    int m, n;
    bool ret;
    vector<vector<int>> check{ 7, vector<int>(7) };
    vector<vector<char>> table{ 7, vector<char>(7) };
    int lx[4] = { -1,1,0,0 };
    int ly[4] = { 0,0,-1,1 };
    void dfs(int x, int y, string word, int cnt) {
        if (word.size() == cnt) {
            ret = true;
        }
        else {
            for (int i = 0;i < 4;i++) {
                if (x + lx[i] >= 0 && x + lx[i] < m && y + ly[i] >= 0 && y + ly[i] < n) {
                    if (check[x + lx[i]][y + ly[i]] == 0 && word.at(cnt) == table[x + lx[i]][y + ly[i]]) {
                        check[x + lx[i]][y + ly[i]] = 1;
                        dfs(x + lx[i], y + ly[i], word, cnt + 1);
                        check[x + lx[i]][y + ly[i]] = 0;
                    }
                }
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                check[i][j] = 0;
                table[i][j] = board[i][j];
            }
        }
        ret = false;
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (board[i][j] == word.at(0)) {
                    check[i][j] = 1;
                    dfs(i, j, word, 1);
                    check[i][j] = 0;
                    if (ret) return true;
                }
            }
        }
        return false;
    }
};
