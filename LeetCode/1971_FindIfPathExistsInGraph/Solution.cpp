class Solution {
public:
    int table[200050];
    int find(int x){
        while(table[x]!=x){
            x=table[x];
        }
        return x;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0;i<n;i++){
            table[i]=i;
        }
        for(auto it : edges){
            int x = find(it[0]);
            int y = find(it[1]);
            if(x!=y){
                table[x]=y;
            }
        }
        return find(source)==find(destination);
    }
};
