class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n+1);
        stack<int> st;
        st.push(0);
        visited[0]=true;
        int i;
        for(i=0;i<n;i++){
            if(st.empty())break;
            int cur = st.top();
            st.pop();
            for(auto key : rooms[cur]){
                if(!visited[key]){
                    visited[key]=true;
                    st.push(key);
                }
            }
        }
        cout<<i;
        return i==n;
    }
};
