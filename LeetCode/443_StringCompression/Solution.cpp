class Solution {
public:
    int writer(int x, int val, vector<char>& chars) {
        stack<char> stack;
        while(val!=0){
            stack.push(val%10+'0');
            val/=10;
        }
        int ret = stack.size();
        while(!stack.empty()){
            chars[x]=stack.top();
            x++;
            stack.pop();
        }
        return ret;
    }
    int compress(vector<char>& chars) {
        int s=0;
        int size = chars.size();
        int answer=0;
        for(int i=1;i<size;i++){
            if(chars[i]!=chars[i-1]){
                chars[answer++]=chars[i-1];
                if(i-s>1){
                    answer+=writer(answer, i-s, chars);
                }
                s=i;
            }
        }
        chars[answer++]=chars[size-1];
        if(size-s>1){
            answer+=writer(answer, size-s, chars);
        }
        return answer;
    }
};
