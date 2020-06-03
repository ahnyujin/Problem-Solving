#include <stdio.h>
int map[50][50]={0};
//east-1 north-0 west-3 south-2
int xl[4]={-1,0,1,0};
int yl[4]={0,1,0,-1};
int n,m;
int right(int x,int y){
    return (x<n && x>=0 && y<m && y>=0);
}
void move(int x,int y,int d){
    map[x][y]=2;
    int flag=0;
    for(int i=0;i<4;i++){
        if(right(x+xl[i],y+yl[i]) && map[x+xl[i]][y+yl[i]]==0){
            flag=1;
        }
    }
    if (flag==1){

        if (right(x+xl[(d+3)%4],y+yl[(d+3)%4]) && map[x+xl[(d+3)%4]][y+yl[(d+3)%4]]==0){
            move(x+xl[(d+3)%4],y+yl[(d+3)%4],(d+3)%4);
        }
        else{
            move(x,y,(d+3)%4);
        }

    }
    else
    {
        if( right(x+xl[(d+2)%4],y+yl[(d+2)%4]) && map[x+xl[(d+2)%4]][y+yl[(d+2)%4]]==2){
            move(x+xl[(d+2)%4],y+yl[(d+2)%4],d);
        }
    }
}
int main()
{
    int r,c,d;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&r,&c,&d);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    move(r,c,d);
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==2){
                answer++;
            }
        }
    }
    printf("%d",answer);
    return 0;
}