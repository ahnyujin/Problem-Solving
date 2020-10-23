#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 100001000
struct Edge{
    Edge(int _e, int _c){
        e = _e;
        c = _c;
    }
    int e;//end
    int c;//cost
};
bool operator<(Edge a, Edge b){
    return a.c > b.c;
}
int main(){
    int n;
    int m;
    int start;
    int end;
    scanf("%d",&n);
    scanf("%d",&m);
    vector<Edge> adj[n+1];
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        adj[x].push_back(Edge(y,z));
    }
    scanf("%d %d",&start,&end);
    int dist[n+1];
    for(int i=1;i<=n;i++){
        dist[i]=INF;
    }
    priority_queue<Edge> pq;
    pq.push(Edge(start,0));
    dist[start]=0;
    while(!pq.empty()){
        int cur = pq.top().e;
        int cst = pq.top().c;
        pq.pop();
        if(dist[cur]<cst)continue;
        printf("%d %d\n",cur,cst);
        for(int i=0;i<adj[cur].size();i++){
            int idx = adj[cur][i].e;
            if((cst+adj[cur][i].c) < dist[idx]){
                dist[idx] = cst + adj[cur][i].c;
                pq.push(Edge(idx,dist[idx]));
            }
        }
    }
    printf("%d",dist[end]);
    return 0;
}