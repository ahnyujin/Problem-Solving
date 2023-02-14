class Solution {
public:
    string addBinary(string a, string b) {
        bool carry=false;
        string ret;
        while(!a.empty()||!b.empty()){
            int sum =0;
            if(carry){
                sum++;
            }
            if(!a.empty()){
                if(a.back()=='1'){
                    sum++;
                }
                a.pop_back();
            }
            if(!b.empty()){
                if(b.back()=='1'){
                    sum++;
                }
                b.pop_back();
            }
            ret.push_back('0'+sum%2);
            if(sum>=2) carry=true;
            else carry=false;
        }
        if(carry){
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
