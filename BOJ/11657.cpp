#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 100000000
int main(){
    int n,m;
    vector<pair<int,int> > adj[510];
    long long int dist[510];
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,c;
        scanf("%d %d %d",&u,&v,&c);
        adj[u].push_back(make_pair(v,c));
    }
    fill(dist+1,dist+n+1,INF);
    dist[1]=0;
    bool cycle_flag=false;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<adj[j].size();k++){
                int v = adj[j][k].first;
                int c = adj[j][k].second;
                if(dist[j]!=INF && dist[v]>dist[j]+c){
                    dist[v]=dist[j]+c;
                }
            }
        }
    }
    for(int j=1;j<=n;j++){
        for(int k=0;k<adj[j].size();k++){
            int end = adj[j][k].first;
            int time = adj[j][k].second;
            if(dist[j]!=INF && dist[end]>dist[j]+time){
                dist[end]=dist[j]+time;
                cycle_flag=true;
                break;
            }
        }
        if(cycle_flag)break;
    }
    if(cycle_flag){
        printf("-1");
    }
    else{
        for(int i=2;i<=n;i++){
            printf("%lld\n",dist[i]!=INF?dist[i]:-1);
        }
    }
}