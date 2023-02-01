class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1=str1.length();
        int l2=str2.length();
        for(int i=l1;i>=1;i--){
            if(l1%i==0 && l2%i==0){
                string x = str1.substr(0,i);
                bool flag = true;
                for(int j=0;j<l1/i;j++){
                    string token = str1.substr(i*j, i);
                    if(token.compare(x)!=0){
                        flag=false;
                        break;
                    }
                }
                if(flag==false) continue;
                for(int j=0;j<l2/i;j++){
                    string token = str2.substr(i*j, i);
                    if(token.compare(x)!=0){
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                    return x;
                }
            }
        }
        return "";
    }
};
