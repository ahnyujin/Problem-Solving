#include <stdio.h>
char chain[4][9];
int state[4]={0};
int temp[4]={0};
int check[4]={0};
void move(int cur_c,int d)
{
    if(d==1){
        temp[cur_c]=(temp[cur_c]+7)%8;
    }
    else{
        temp[cur_c]=(temp[cur_c]+1)%8;
    }
    if(cur_c!=0 && check[cur_c-1]==0 && (chain[cur_c][(state[cur_c]+6)%8] != chain[cur_c-1][(state[cur_c-1]+2)%8])){//left
        check[cur_c-1]=1;
        move(cur_c-1, d*(-1));
    }
    if(cur_c!=3 && check[cur_c+1]==0 && (chain[cur_c][(state[cur_c]+2)%8] != chain[cur_c+1][(state[cur_c+1]+6)%8])){//right
        check[cur_c+1]=1;
        move(cur_c+1, d*(-1));
    }
}
int main()
{
    for(int i=0;i<4;i++){
        scanf("%s",chain[i]);
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int x,d;
        scanf("%d %d",&x,&d);
        for(int j=0;j<4;j++)check[j]=0;
        check[x-1]=1;
        move(x-1,d);
        for(int j=0;j<4;j++){
             state[j]=temp[j];
        }
    }
    int answer=0;
    int cnt=1;
    for(int i=0;i<4;i++){
        if(chain[i][state[i]]=='1') answer+=cnt;
        cnt*=2;
    }
    printf("%d",answer);
    return 0;
}