class Solution {
public:
    int minJumps(vector<int>& arr) {
        int size = arr.size();
        vector<int> vt(size, -1);

        unordered_map<int,vector<int>> jump;
        for(int i=0;i<size;i++){
            jump[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        vt[0]=0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur-1>0 && vt[cur-1]==-1){
                vt[cur-1]=vt[cur]+1;
                q.push(cur-1);
            }
            if(cur+1<size && vt[cur+1]==-1){
                vt[cur+1]=vt[cur]+1;
                q.push(cur+1);
            }
            for(int i=0;i<jump[arr[cur]].size();i++){
                int next=jump[arr[cur]][i];
                if(vt[next]==-1){
                    vt[next]=vt[cur]+1;
                    q.push(next);
                }
            }
            jump[arr[cur]].clear();
        }
        return vt[size-1];
    }
};
