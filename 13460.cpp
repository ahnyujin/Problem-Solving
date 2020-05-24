#include <stdio.h>
#include <utility>
using namespace std;
char A[100][100];
int n,m;
int xl[4]={1,-1,0,0};
int yl[4]={0,0,1,-1};
int min=-1;
void dfs(int cnt,pair<int,int> R, pair<int,int> B){
    if(cnt!=11){
        for(int i=0;i<4;i++){
            int rx=R.first;
            int ry=R.second;
            int bx=B.first;
            int by=B.second;

            int temprx=rx;
            int tempry=ry;
            int tempbx=bx;
            int tempby=by;
            //red
            int flag=0;
            int wrong=0;
            while( (A[rx+xl[i]][ry+yl[i]]!='#') && (rx+xl[i]!=bx || ry+yl[i]!=by)){
                rx+=xl[i];
                ry+=yl[i];
                if(A[rx][ry]=='O'){
                    flag=1;
                }
            }
            //blue
            while( (A[bx+xl[i]][by+yl[i]]!='#') && ((bx+xl[i]!=rx || by+yl[i]!=ry) || flag==1)){
                bx+=xl[i];
                by+=yl[i];
                if(A[bx][by]=='O'){
                    flag=1;
                    wrong=1;
                }
            }
            //red
            while( (A[rx+xl[i]][ry+yl[i]]!='#') && (rx+xl[i]!=bx || ry+yl[i]!=by)){
                rx+=xl[i];
                ry+=yl[i];
                if(A[rx][ry]=='0'){
                    flag=1;
                }
            }
            if(flag!=1 && (temprx!=rx||tempry!=ry||tempbx!=bx||tempby!=by)){
                dfs(cnt+1,make_pair(rx,ry),make_pair(bx,by));
            }
            else if(flag==1&&wrong!=1)
            {
                if(min==-1||min>cnt){
                    min=cnt;
                }
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    int rx,ry,bx,by;
    for(int i=0;i<n;i++)
    {
        scanf("%s",A[i]);
        for(int j=0;j<m;j++){
            if(A[i][j]=='R'){
                rx=i;
                ry=j;
                A[i][j]='.';
            }
            if(A[i][j]=='B'){
                bx=i;
                by=j;
                A[i][j]='.';
            }
        }
    }
    dfs(1,make_pair(rx,ry),make_pair(bx,by));
    printf("%d",min);
    return 0;
}