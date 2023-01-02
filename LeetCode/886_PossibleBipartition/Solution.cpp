class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> vt(n+1);
        vector<int> group(n+1,-1);
        for(auto dislike:dislikes){
            vt[dislike[0]].push_back(dislike[1]);
            vt[dislike[1]].push_back(dislike[0]);
        }
        for(int i=1;i<=n;i++){
            if(group[i]==-1){
                stack<int> st;
                st.push(i);
                while(!st.empty()){
                    int cur = st.top();
                    st.pop();
                    for(auto x:vt[cur]){
                        if(group[x]==-1){
                            group[x]=1-group[cur];
                            st.push(x);
                        }
                        else if(group[x]!=1-group[cur]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
