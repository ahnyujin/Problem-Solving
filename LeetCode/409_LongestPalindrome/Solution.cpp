class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.length();
        int check[52];
        memset(check, 0, sizeof check);
        for(int i=0;i<len;i++) {
            if(s[i]>='a'){
                check[s[i]-'a'+26]++;
            }
            else{
                check[s[i]-'A']++;
            }
        }
        int answer=0;
        for(int i=0;i<52;i++){
            if(check[i]!=0){
                answer+=(check[i]-check[i]%2);
            }
        }
        if(len>answer) return answer+1;
        return answer;
    }
};
