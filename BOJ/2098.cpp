#include <stdio.h>
#include <algorithm>
#define INF 20000000
using namespace std;
int n;
int adj[20][20];
int T[20][100000];
int traveling(int cur, int state){
    if(state==(1<<n)-1) return adj[cur][0]==0? INF : adj[cur][0];
    if(T[cur][state]!=INF) return T[cur][state];
    for(int i=0;i<n;i++){
        if((state&(1<<i))==0 && adj[cur][i]!=0){
            T[cur][state]=min(T[cur][state], traveling(i,state|(1<<i))+adj[cur][i]);
        }
    }
    return T[cur][state];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d ",&adj[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            T[i][j]=INF;
        }
    }
    printf("%d",traveling(0,1));
    return 0;
}