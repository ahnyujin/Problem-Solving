#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int,int> > v;
int n,m;
int cctv_num=0;
int answer;
int office[10][10];
int xi[5]={0,-1,0,1};
int yi[5]={1,0,-1,0};
void one_sight(int px,int py, int dir){//0:right,1:up,2:left,3:down
    int x=px;
    int y=py;
    while( x>=0 && x<m && y>=0 && y<n){
        if(office[x][y]==0) {
            office[x][y]= 7;
        } else if(office[x][y]==6) break;
        x+=xi[dir];
        y+=yi[dir];
    }
}
void reset(int temp[10][10]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            office[i][j]=temp[i][j];
        }
    }
}
void cctv(int cnt){
    int temp[10][10];
    if(cnt==cctv_num){
        int zero=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(office[i][j]==0){
                    zero++;
                }
            }
        }
        if(zero<answer)answer=zero;
    } else
    {
        //back-up
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=office[i][j];
            }
        }
        int px=v[cnt].first;
        int py=v[cnt].second;
        if(office[px][py]==1){
            for(int i=0;i<4;i++){
                one_sight(px,py,i);
                cctv(cnt+1);
                reset(temp);
            }
        } else if(office[px][py]==2){
            for(int i=0;i<2;i++){
                one_sight(px,py,i);
                one_sight(px,py,i+2);
                cctv(cnt+1);
                reset(temp);
            }
        } else if(office[px][py]==3){
            for(int i=0;i<4;i++){
                one_sight(px,py,i);
                one_sight(px,py,(i+1)%4);
                cctv(cnt+1);
                reset(temp);
            }
        } else if(office[px][py]==4){
            for(int i=0;i<4;i++){
                one_sight(px,py,i);
                one_sight(px,py,(i+1)%4);
                one_sight(px,py,(i+2)%4);
                cctv(cnt+1);
                reset(temp);
            }
        } else if(office[px][py]==5){
                one_sight(px,py,0);
                one_sight(px,py,1);
                one_sight(px,py,2);
                one_sight(px,py,3);
                cctv(cnt+1);
                reset(temp);
        }
    }
}
int main(){
    scanf("%d %d",&m,&n);
    int zero=0;
    answer=m*n;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++){
            scanf("%d",&office[i][j]);
            if(office[i][j]>=1 && office[i][j]<=5) {
                cctv_num++;
                v.push_back(make_pair(i,j));
            }
        }
    }
    cctv(0);
    printf("%d",answer);
    return 0;
}