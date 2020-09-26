#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> table;
    for(int i=2;i<=n;i++){
        table.push_back(i);
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<table.size();){
            if(table[j]!=i&&table[j]%i==0){
                table.erase(table.begin()+j);
            }
            else{
                j++;
            }
        }
    }
    return table.size();
}