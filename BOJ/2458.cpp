#include <cstdio>
int main(){
    int n,m;
    int adj[600][600];
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x][y]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j||(adj[i][k]&&adj[k][j])){
                   adj[i][j]=1; 
                }
            }
        }
    }
    int answer=0;
    for(int i=1;i<=n;i++){
        bool flag=false;
        for(int j=1;j<=n;j++){
            if(adj[i][j]==0&&adj[j][i]==0){
                flag=true;
                break;
            }
        }
        if(flag==false)answer++;
    }
    printf("%d",answer);
    return 0;
}