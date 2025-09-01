class Solution {
public:
    double delta(int pass,int total) {
        return (double)(pass+1)/(total+1)-(double)pass/total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int,int>>> pq;
        int size=classes.size();
        
        for(auto &c: classes) {
            int pass=c[0];
            int total=c[1];
            pq.push({delta(pass,total),{pass,total}});
        }
        
        while(extraStudents--) {
            auto [d,p]=pq.top();
            pq.pop();
            auto [pass,total] = p;
            pass+=1;
            total+=1;
            pq.push({delta(pass,total), {pass,total}});
        }
        
        double res = 0.0;
        while(!pq.empty()) {
            auto [d, p]=pq.top();
            pq.pop();
            auto [pass,total]=p;
            res+=(double)pass/total;
        }
        return res/size;
    }
};
