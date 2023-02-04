class Solution {
public:
    int table[26] = {0,};
    bool checkInclusion(string s1, string s2) {
        for(auto x : s1){
            table[x-'a']--;
        }

        int len1 = s1.length();
        int len2 = s2.length();
        if(len1>len2) return false;
        for(int i=0;i<len1;i++){
            table[s2[i]-'a']++;
        }
        bool flag = true;
        for(int i=0;i<26;i++){
            if(table[i]!=0){
                flag=false;
                break;
            }
        }
        if(flag==true){
            return true;
        }
        for(int i=len1;i<len2;i++){
            table[s2[i-len1]-'a']--;
            table[s2[i]-'a']++;
            
            flag = true;
            for(int j=0;j<26;j++){
                cout<<table[j]<<" ";
                if(table[j]!=0){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                return true;
            }
        }
        return false;
    }
};