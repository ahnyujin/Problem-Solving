#include <stdio.h>
int main()
{
    int paper[500][500];
    int tx[5][4]={{0,0,0,0},{0,0,1,1},{0,1,2,2},{0,1,1,2},{0,0,0,1}};
    int ty[5][4]={{0,1,2,3},{0,1,0,1},{0,0,0,1},{0,0,1,1},{0,1,2,1}};
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&paper[i][j]);
        }
    }
    int answer=0;
    for(int turn=0;turn<4;turn++){
        int max=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<)
            }
        }
        if(sum>answer)answer=sum;
        //sym
    }
    printf("%d",answer);
    return 0;
}