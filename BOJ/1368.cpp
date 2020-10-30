#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct PairComparer
{
    bool operator()(const pair<int, int> &x, const pair<int, int> &y)
    {
        return x.second > y.second;
    }
};
int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        adj[i].push_back(make_pair(0, x));
        adj[0].push_back(make_pair(i, x));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            scanf("%d", &x);
            if (i <= j)
                continue;
            adj[i].push_back(make_pair(j, x));
            adj[j].push_back(make_pair(i, x));
        }
    }
    int cur = 0;
    int check[n + 1];
    int answer = 0;
    for (int i = 0; i <= n; i++)
        check[i] = 0;
    check[0] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, PairComparer> pq;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < adj[cur].size(); j++)
            pq.push(adj[cur][j]);
        while (check[pq.top().first] != 0)
        {
            pq.pop();
        }
        cur = pq.top().first;
        answer += pq.top().second;
        check[cur] = 1;
        pq.pop();
    }
    printf("%d", answer);
    return 0;
}