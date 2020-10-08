#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        int k;
        int x,y;
        int d;
        int time[1050];
        scanf("%d %d",&n,&k);
        vector<vector<int> > adj(n+1,vector<int>(0,0));
        vector<int> indegree(n+1,0); // 진입차수
        vector<int> minimum(n+1,-1);
        queue<int> q;
        for(int j=1;j<=n;j++){
            scanf("%d",&time[j]);
        }
        for(int j=0;j<k;j++){
            scanf("%d %d",&x,&y);
            adj[x].push_back(y);
            indegree[y]++;
        }
        scanf("%d",&d);
        for(int j=1;j<=n;j++){
            if(indegree[j]==0){
                q.push(j);
                minimum[j]=time[j];
            }
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur==d)break;
            for(int j=0;j<adj[cur].size();j++){
                int to=adj[cur][j];
                indegree[to]--;
                if(minimum[to]==-1 || minimum[to]<minimum[cur]+time[to]){
                    minimum[to]=minimum[cur]+time[to];
                }
                if(indegree[to]==0) q.push(to);
            }
        }
        printf("%d\n",minimum[d]);
    }

    return 0;
}