class Solution {
public:
    int findRoot(int x, vector<int>& charMap){
        while(charMap[x]!=x){
            x=charMap[x];
        }
        return x;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> charMap(26);
        for(int i=0;i<26;i++){
            charMap[i]=i;
        }
        int len = s1.length();
        for(int i=0;i<len;i++){
            int root1=findRoot(s1[i]-'a',charMap);
            int root2=findRoot(s2[i]-'a',charMap);
            if(root1!=root2){
                if(root1<root2){
                    charMap[root2]=root1;
                }
                else{
                    charMap[root1]=root2;
                }
            }
        }
        for(auto& x : baseStr){
            x = findRoot(x-'a',charMap)+'a';
        }
        return baseStr;
    }
};
