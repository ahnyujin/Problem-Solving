#include <string>
#include <vector>

using namespace std;
int check[55]={0};
int answer=-1;
string tar;
vector<string> str;
void dfs(string cur,int cnt){
    if(cur==tar){
        if(answer==-1||answer>cnt)answer=cnt;
    }
    else{
        for(int i;i<str.size();i++){
            if(check[i]==1) continue;
            int flag=0;
            for(int j=0;j<str[i].size();j++){
                if(str[i][j]!=cur[j])
                {
                    flag++;
                }
            }
            if(flag==1){
                check[i]=1;
                dfs(str[i],cnt+1);
                check[i]=0;
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    str=words;
    tar=target;
    dfs(begin,0);
    if(answer==-1) answer=0;
    return answer;
}