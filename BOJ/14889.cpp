#include <stdio.h>
int str[20][20];
int n;
int answer=-1;
int check[20]={0};
void team(int cnt,int x){
    if(cnt==n/2){
        int sum[2];
        sum[0]=0;
        sum[1]=0;
        int temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check[i]==check[j]){
                    sum[check[i]]+=str[i][j];
                }
            }
        }
        if(sum[0]>sum[1]) temp=sum[0]-sum[1];
        else temp=sum[1]-sum[0];
        if(answer==-1 || answer>temp) answer=temp;
    }
    if(n/2-cnt+x < n){
        for(int i=x+1;i<n;i++){
            check[i]=1;
            team(cnt+1,i);
            check[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            scanf("%d",&str[i][j]);
        }
    }
    team(0,-1);
    printf("%d",answer);
    return 0;
}