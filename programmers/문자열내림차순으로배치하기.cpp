#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int sortf(char x, char y){
    if(x>y)return 1;
    return 0;
}
string solution(string s) {
    string answer = "";
    sort(s.begin(),s.end(),sortf);
    return s;
}