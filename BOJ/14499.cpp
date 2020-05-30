#include <stdio.h>
    int map[20][20]={0};
    int dice[7]={0};
int main(){
    int n,m,x,y,k,temp;
    scanf("%d %d %d %d %d",&n,&m,&x,&y,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=0;i<k;i++){
        int dis;
        scanf("%d",&dis);
        if(dis==1){//east
            if(y+1>=m)continue;
            y++;
            temp=dice[4];
            dice[4]=dice[1];
            dice[1]=dice[3];
            dice[3]=dice[6];
            dice[6]=temp;
        }
        if(dis==2){//west
            if(y-1<0)continue;
            y--;
            temp=dice[3];
            dice[3]=dice[1];
            dice[1]=dice[4];
            dice[4]=dice[6];
            dice[6]=temp;
        }
        if(dis==3){//north
            if(x-1<0)continue;
            x--;
            temp=dice[2];
            dice[2]=dice[1];
            dice[1]=dice[5];
            dice[5]=dice[6];
            dice[6]=temp;
        }
        if(dis==4){//south
            if(x+1>=n)continue;
            x++;
            temp=dice[5];
            dice[5]=dice[1];
            dice[1]=dice[2];
            dice[2]=dice[6];
            dice[6]=temp;
        }
        if(map[x][y]==0){
            map[x][y]=dice[6];
        }
        else{
            dice[6]=map[x][y];
            map[x][y]=0;
        }
        printf("%d\n",dice[1]);
    }
    return 0;
}