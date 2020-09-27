#include <string>
#include <vector>

using namespace std;
vector<int> num;
int tar;
int answer=0;
void dfs(int cnt,int sum){
    if(cnt==num.size()){
         if(sum==tar) answer++;
    }
    else{
        dfs(cnt+1,sum+num[cnt]);
        dfs(cnt+1,sum-num[cnt]);
    }
}
int solution(vector<int> numbers, int target) {
    num.assign(numbers.begin(),numbers.end());
    tar=target;
    dfs(0,0);
    return answer;
}