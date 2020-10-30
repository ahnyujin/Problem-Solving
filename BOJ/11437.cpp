#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main(){
    int n,m;
    scanf("%d",&n);
    vector<int> adj[n+1];
    int parent[n+1];
    int level[n+1];
    for(int i=0;i<n-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<pair<int,int> > q;
    q.push(make_pair(1,0));
    for(int i=1;i<=n;i++){
        parent[i]=0;
    }
    level[1]=0;
    parent[1]=-1;
    while(!q.empty()){
        pair<int,int > cur = q.front();
        q.pop();
        for(int i=0;i<adj[cur.first].size();i++){
            int child = adj[cur.first][i];
            if(parent[child]==0){
                parent[child] = cur.first;
                level[child] = cur.second+1;
                q.push(make_pair(child,cur.second+1));
            }
        }
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        while(a!=b){
            if(level[a]==level[b]){
                a=parent[a];
                b=parent[b];
            }
            else if(level[a]>level[b]){
                a=parent[a];
            }
            else{
                b=parent[b];
            }
        }
        printf("%d\n",a);
    }
}