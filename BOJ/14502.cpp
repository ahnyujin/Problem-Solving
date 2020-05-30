#include <stdio.h>
int n,m;
int lab[10][10];
int temp[10][10];
int lx[5]={1,-1,0,0};
int ly[5]={0,0,1,-1};
void virus(int x,int y){
    for(int i=0;i<4;i++){
        if(x+lx[i]>=0 && x+lx[i]<n && y+ly[i]>=0 && y+ly[i]<m && lab[x+lx[i]][y+ly[i]]==0){
            lab[x+lx[i]][y+ly[i]]=2;
            virus(x+lx[i],y+ly[i]);
        }
    }
}
int main()
{
    int answer=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&lab[i][j]);
            temp[i][j]=lab[i][j]; //backup
        }
    }
    //make 3 walls

    for(int a=0;a<n*m;a++){
        for(int b=a+1;b<n*m;b++){
            for(int c=b+1;c<n*m;c++){
                if(lab[a/m][a%m]!=0 || lab[b/m][b%m]!=0 || lab[c/m][c%m]!=0) continue;
                lab[a/m][a%m]=1;
                lab[b/m][b%m]=1;
                lab[c/m][c%m]=1;
                    for(int i=0;i<n;i++){
                        for(int j=0;j<m;j++){
                            if(lab[i][j]==2){
                                virus(i,j);
                            }
                        }
                    }
                //reset
                int cnt=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(lab[i][j]==0) cnt++;
                        lab[i][j]=temp[i][j];
                    }
                }
                if(cnt>answer)answer=cnt;
            }
        }
    }
    printf("%d",answer);
    return 0;
}