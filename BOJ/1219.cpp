#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 20000000000
struct Edge{
    Edge(int _y, int _c){
        y=_y;
        c=_c;
    }
    int y;
    int c;
};
int main(){
    int n,s,e,m;
    scanf("%d %d %d %d",&n,&s,&e,&m);
    vector<Edge> adj[n];
    long long int city_w[n];
    long long int dist[n];
    for(int i=0;i<m;i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        adj[x].push_back(Edge(y,c));
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&city_w[i]);
        dist[i]=INF;
    }
    dist[s]=-city_w[s];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<adj[j].size();k++){
                if(dist[j]==INF)continue;
                if(dist[adj[j][k].y]>dist[j]+adj[j][k].c-city_w[adj[j][k].y]){
                    dist[adj[j][k].y]=dist[j]+adj[j][k].c-city_w[adj[j][k].y];
                }
            }
        }
    }
    if(dist[e]==INF){
        printf("gg");
        return 0;
    }
    int check[n];
    for(int i=0;i<n;i++){
        check[i]=0;
    }
    bool flag=false;
    queue<int> q;
    for(int j=0;j<n;j++){
        for(int k=0;k<adj[j].size();k++){
            if(dist[j]==INF)continue;
            if(dist[adj[j][k].y]>dist[j]+adj[j][k].c-city_w[adj[j][k].y]){
                dist[adj[j][k].y]=dist[j]+adj[j][k].c-city_w[adj[j][k].y];
                q.push(adj[j][k].y);
                check[adj[j][k].y]=1;
            }
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur==e){
            flag=true;
            break;
        }
        for(int i=0;i<adj[cur].size();i++){
            if(check[adj[cur][i].y]==0){
                check[adj[cur][i].y]=1;
                q.push(adj[cur][i].y);
            }
        }
    }
    if(flag){
        printf("Gee");
    }
    else{
        printf("%lld",-dist[e]);
    }
    return 0;
}