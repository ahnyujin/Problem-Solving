#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int sortf(const vector<string>&lhs, const vector<string>&rhs){
    return (lhs[0]<rhs[0] || (lhs[0]==rhs[0] && lhs[1]<rhs[1]));
}
vector<vector<string>> tic;
vector<string> answer;
vector<string> temp;
vector<int> check;
int flag=0;
void dfs(string cur,int cnt){
    if(flag==0&& cnt==tic.size()){
        flag=1;
        answer=temp;
    }
    if(flag==0){
    for(int i=0;i<tic.size();i++){
        if(check[i]==0 && cur==tic[i][0]){
            check[i]=1;
            cout<<tic[i][1]<<endl;
            temp.push_back(tic[i][1]);
            dfs(tic[i][1],cnt+1);
            temp.pop_back();
            check[i]=0;
        }
    }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    for(int i=0;i<tickets.size();i++){
        check.push_back(0);
    }
    sort(tickets.begin(),tickets.end(),sortf);
    tic=tickets;
    temp.push_back("ICN");
    dfs("ICN",0);
    return answer;
}