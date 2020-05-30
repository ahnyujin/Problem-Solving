#include <stdio.h>
int n;
int max=0;
int board[25][25];
void game(int total) {
    int temp[25][25];
    //backup
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            temp[i][j]=board[i][j];
        }
    }
    if(total!=5) {
        //up
            for(int i=0;i<n;i++){
                int row=-1;
                bool overlap=1;
                for(int j=0;j<n;j++){
                    int x=board[j][i];
                    if(x != 0){
                        board[j][i]=0;
                        if(overlap==0 && board[row][i]==x) {
                            overlap=1;
                            board[row][i]*=2;
                            if(board[row][i]>max) max=board[row][i];
                        } else {
                            overlap=0;
                            row++;
                            board[row][i]=x;
                        }
                    }
                }
            }
            game(total+1);
        //reset
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                board[i][j]=temp[i][j];
            }
        }
        //down
            for(int i=0;i<n;i++){
                int row=n;
                bool overlap=1;
                for(int j=n-1;j>=0;j--){
                    int x=board[j][i];
                    if(x != 0){
                        board[j][i]=0;
                        if(overlap==0 && board[row][i]==x) {
                            overlap=1;
                            board[row][i]*=2;
                            if(board[row][i]>max) max=board[row][i];
                        } else {
                            overlap=0;
                            row--;
                            board[row][i]=x;
                        }
                    }
                }
            }
            game(total+1);
        //reset
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                board[i][j]=temp[i][j];
            }
        }
        //left
            for(int i=0;i<n;i++){
                int column=-1;
                bool overlap=1;
                for(int j=0;j<n;j++){
                    int x=board[i][j];
                    if(x != 0){
                        board[i][j]=0;
                        if(overlap==0 && board[i][column]==x) {
                            overlap=1;
                            board[i][column]*=2;
                            if(board[i][column]>max) max=board[i][column];
                        } else {
                            overlap=0;
                            column++;
                            board[i][column]=x;
                        }
                    }
                }
            }
            game(total+1);
        //reset
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                board[i][j]=temp[i][j];
            }
        }
        //right
            for(int i=0;i<n;i++){
                int column=n;
                bool overlap=1;
                for(int j=n-1;j>=0;j--){
                    int x=board[i][j];
                    if(x != 0){
                        board[i][j]=0;
                        if(overlap==0 && board[i][column]==x) {
                            overlap=1;
                            board[i][column]*=2;
                            if(board[i][column]>max) max=board[i][column];
                        } else {
                            overlap=0;
                            column--;
                            board[i][column]=x;
                        }
                    }
                }
            }
            game(total+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&board[i][j]);
            if(board[i][j] > max) max=board[i][j];
        }
    }
    game(0);
    printf("%d",max);
    return 0;
}