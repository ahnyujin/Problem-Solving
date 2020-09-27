#include <string>
#include <vector>

using namespace std;
vector<vector<int>> net;
int check[250]={0};
int answer=0;
int cnt;
void dfs(int x){
    check[x]=1;
    for(int i=0;i<cnt;i++){
        if(net[x][i]==1 && check[i]==0){
            dfs(i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    net=computers;
    cnt=n;
    for(int i=0;i<n;i++){
        if(check[i]!=1){
            answer++;
            dfs(i);
        }
    }
    return answer;
}