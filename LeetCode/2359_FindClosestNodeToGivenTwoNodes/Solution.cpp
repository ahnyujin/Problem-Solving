class Solution {
public:
    void dfs(int cur, vector<int>& edge, vector<int>& check){
        if(edge[cur]!=-1&&check[edge[cur]]==0){
            check[edge[cur]]=check[cur]+1;
            dfs(edge[cur], edge, check);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> check1(n,0);
        vector<int> check2(n,0);
        check1[node1]=1;
        check2[node2]=1;
        dfs(node1, edges, check1);
        dfs(node2, edges, check2);
        int distance = INT_MAX;
        int answer=-1;
        for(int i=0;i<n;i++){
            if(check1[i]!=0&&check2[i]!=0){
                int maxDistance=max(check1[i]-1,check2[i]-1);
                if(distance>maxDistance){
                    distance=maxDistance;
                    answer=i;
                }
            }
        }
        return answer;
    }
};
