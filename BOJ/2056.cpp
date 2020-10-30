#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
    int weight[10010];
    int indegree[10010];
    int check[10010];
    int min_time[10010];
int main(){
    int N;
    scanf("%d",&N);
    vector<int> adj[N+1];
    for(int i=1;i<=N;i++) indegree[i]=0;
    for(int i=1;i<=N;i++){
        scanf("%d",&weight[i]);
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            adj[x].push_back(i);
        }
        indegree[i]=m;
    }
    queue<int> q;
    int answer=0;
    for(int i=1;i<=N;i++){
        if(indegree[i]==0){
            q.push(i);
            check[i]=1;
            min_time[i]=weight[i];
        } 
        else{
            check[i]=0;
            min_time[i]=0;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(answer<min_time[cur])answer=min_time[cur];
        for(int i=0;i<adj[cur].size();i++){
            indegree[adj[cur][i]]--;
            if(min_time[adj[cur][i]]<min_time[cur]+weight[adj[cur][i]]){
                min_time[adj[cur][i]]=min_time[cur]+weight[adj[cur][i]];
            }
            if(indegree[adj[cur][i]]==0){
                q.push(adj[cur][i]);
            }
        }
    }
    printf("%d",answer);
    return 0;
}