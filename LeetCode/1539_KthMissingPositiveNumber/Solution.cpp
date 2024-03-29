class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid]-mid-1>=k){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s+k;
    }
};
