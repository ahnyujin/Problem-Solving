#include <cstdio>
#include <vector>
#define INF 1000000000;
using namespace std;
struct edge{
    edge(int _to, int _weight){
        to=_to;
        weight=_weight;
    }
    int to;
    int weight;
};
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,m,w;
        scanf("%d %d %d",&n,&m,&w);
        vector<edge> adj[n+1];
        int dist[n+1];
        for(int j=1;j<=n;j++){
            dist[j]=INF;
        }
        dist[1]=0;
        for(int j=0;j<m;j++){
            int s,e,t;
            scanf("%d %d %d",&s,&e,&t);
            adj[s].push_back(edge(e,t));
            adj[e].push_back(edge(s,t));
        }
        for(int j=0;j<w;j++){
            int s,e,t;
            scanf("%d %d %d",&s,&e,&t);
            adj[s].push_back(edge(e,-t));
        }
        for(int j=0;j<n-1;j++){
            for(int k=1;k<=n;k++){
                for(int l=0;l<adj[k].size();l++){
                    int to = adj[k][l].to;
                    int weight = adj[k][l].weight;
                    if(dist[to]>dist[k]+weight){
                        dist[to] = dist[k]+weight;
                    }
                }
            }
        }
        bool flag=false;
        for(int k=1;k<=n;k++){
            for(int l=0;l<adj[k].size();l++){
                int to = adj[k][l].to;
                int weight = adj[k][l].weight;
                if(dist[to]>dist[k]+weight){
                    dist[to] = dist[k]+weight;
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        if(flag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}