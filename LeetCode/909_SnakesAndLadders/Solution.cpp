class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int endPoint = n * n;
        int check[endPoint + 1];
        memset(check, 0, sizeof(check));
        stack<int> st;
        st.push(1);
        check[1] = 1;
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            for (int i = 1;i <= 6;i++) {
                int next = cur + i;
                if (next > endPoint) break;

                int x = (next - 1) / n;
                int y;
                if (x % 2 == 0) {
                    y = (next - 1) % n;
                }
                else {
                    y = n - 1 - (next - 1) % n;
                }
                x = n - 1 - x;
                if (board[x][y] != -1) {
                    next = board[x][y];
                }

                if (check[next] == 0 || check[next] > check[cur] + 1) {
                    check[next] = check[cur] + 1;
                    st.push(next);
                }
            }
        }
        return check[endPoint] - 1;
    }
};
