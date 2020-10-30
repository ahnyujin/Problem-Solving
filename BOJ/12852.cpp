#include <cstdio>
#define INF 2000000
    int table[1000050];
    int from[1000050];
    int temp[1000050];
int main(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        table[i]=INF;
    }
    table[N]=0;
    for(int i=N;i>1;i--){
        if(table[i]==INF)continue;
        if(i%3==0 && table[i/3]>table[i]+1){
            table[i/3]=table[i]+1;
            from[i/3]=i;
        }
        if(i%2==0 && table[i/2]>table[i]+1){
            table[i/2]=table[i]+1;
            from[i/2]=i;
        }
        if(table[i-1]>table[i]+1){
            table[i-1]=table[i]+1;
            from[i-1]=i;
        }
    }
    printf("%d\n",table[1]);
    int x=1;
    int cnt=0;
    while(true){
        temp[cnt]=x;
        cnt++;
        if(x==N)break;
        x=from[x];
    }
    for(int i=cnt-1;i>=0;i--){
        printf("%d ",temp[i]);
    }
    return 0;
}