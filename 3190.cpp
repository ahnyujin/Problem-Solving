#include <stdio.h>
#include <utility>
#include <queue>
using namespace std;
int table[105][105]={0};
pair<int,char> change[105];
int xl[4]={0,-1,0,1};
int yl[4]={1,0,-1,0};
int main()
{
    int n;
    int k;
    int l;
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int x;
        int y;
        scanf("%d %d",&x,&y);
        table[x][y]=1;
    }
    scanf("%d",&l);
    for(int i=0;i<l;i++){
        int x;
        char c;
        scanf("%d %c",&x,&c);
        change[i]=make_pair(x,c);
    }
    queue<pair<int,int> > q;
    q.push(make_pair(1,1));
    int dis=0;
    int cnt=0;
    table[1][1]=2;
    for(int i=1; ;i++){

        pair<int,int> cur = q.back();
        cur.first+=xl[dis];
        cur.second+=yl[dis];
        if(cur.first>n || cur.first<=0 || cur.second>n || cur.second<=0 || table[cur.first][cur.second]==2)//wall||self
        {
            printf("%d",i);
            break;
        }
        if(table[cur.first][cur.second]==1){ //apple
            table[cur.first][cur.second]=2;
            q.push(make_pair(cur.first,cur.second));
        }
        else
        {
            table[cur.first][cur.second]=2;
            q.push(make_pair(cur.first,cur.second));
            table[q.front().first][q.front().second]=0;
            q.pop();
        }
        
        if(cnt!=l && change[cnt].first==i){
            if(change[cnt].second=='L'){
                dis=(dis+1)%4;
            }
            else //"D"
            {
                dis=(dis+3)%4;
            }
            cnt++;
        }
    }
    return 0;
}