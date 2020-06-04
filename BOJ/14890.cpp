#include <stdio.h>
int main()
{
    int n,l;
    int map[150][150];
    scanf("%d %d",&n,&l);
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        int rc=0;
        int rr=0;
        int col_temp=-1;
        int row_temp=-1;
        for(int j=0;j<n-1;j++){
            int col_flag=0;
            int row_flag=0;
            if(map[i][j]!=map[i][j+1]){//row
                if(map[i][j]+1==map[i][j+1] && row_temp<=j-l){//12
                    int flag=0;
                    for(int k=0;k<l;k++){
                        if(map[i][j-k]!=map[i][j]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        row_temp=j;
                        row_flag=1;
                    }
                }
                if( j+l<n && map[i][j]==map[i][j+1]+1){//21
                    int flag=0;
                    for(int k=0;k<l;k++){
                        if(map[i][j+1+k]!=map[i][j+1]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        row_temp=j+l;
                        row_flag=1;
                    } 
                }
            }
            else row_flag=1;
            if(map[j][i]!=map[j+1][i]){//col
                if(map[j][i]+1==map[j+1][i] && col_temp<=j-l){//12
                    int flag=0;
                    for(int k=0;k<l;k++){
                        if(map[j-k][i]!=map[j][i]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        col_temp=j;
                        col_flag=1;
                    }
                }
                if( j+l<n && map[j][i]==map[j+1][i]+1){//21
                    int flag=0;
                    for(int k=0;k<l;k++){
                        if(map[j+1+k][i]!=map[j+1][i]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        col_temp=j+l;
                         col_flag=1;
                    }
                }
            }
            else col_flag=1;
            if(col_flag!=1) rc=1;
            if(row_flag!=1) rr=1;
        }
        if(rc==0) answer++;
        if(rr==0) answer++;
    }
    printf("%d",answer);
    return 0;
}