class Solution {
public:
    bool ispossible(int speed, vector<int>& dist, double hour){
        double sum=0;
        int size = dist.size();
        for(int i=0;i<size-1;i++){
            double takes=dist[i]*1.0/speed;
            sum=sum+ceil(takes);
            if(sum>hour){
                return false;
            }
        }
        sum+=dist[size-1]*1.0/speed;
       if(sum<=hour) {
           return true;
       }
       return false;
    } 
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s=1;
        int e=1000000000;
        int ret=-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(mid,dist,hour)){
                ret=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ret;
    }
};
