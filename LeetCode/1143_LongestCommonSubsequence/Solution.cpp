class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.length();
        int len2=text2.length();
        int arr[1000][1000];
        memset(arr, 0, sizeof(arr));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(text1[i-1]==text2[j-1]){
                    arr[i][j]=arr[i-1][j-1]+1;
                }
                else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return arr[len1][len2];
    }
};
