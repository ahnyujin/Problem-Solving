class Solution {
public:
    int romanToInt(string s) {
        map<char, int> map;
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        int len = s.length();
        int last = map[s[len-1]];
        int ret = last;
        for(int i=len-2;i>=0;i--){
            int cur = map[s[i]];
            if(cur<last){
                ret-=cur;
            }
            else{
                ret+=cur;
            }
            last = cur;
        }
        return ret;
    }
};
