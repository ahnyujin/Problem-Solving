class Solution {
public:
    int table[26]={0,};
    vector<int> findAnagrams(string s, string p) {
        int len1=p.length();
        int len2=s.length();
        if(len2<len1) return {};
        for(auto x : p) {
            table[x-'a']--;
        }
        vector<int> ret;
        bool flag=true;
        for(int i=0;i<len1;i++){
            table[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(table[i]!=0){
                flag=false;
                break;
            }
        }
        if(flag){
            ret.push_back(0);
        }
        for(int i=len1;i<len2;i++){
            table[s[i-len1]-'a']--;
            table[s[i]-'a']++;
            flag=true;
            for(int j=0;j<26;j++){
                cout<<table[j]<<" ";
                if(table[j]!=0){
                    flag=false;
                    break;
                }
            }
            cout<<endl;
            if(flag){
                ret.push_back(i-len1+1);
            }
        }
        return ret;
    }
};
