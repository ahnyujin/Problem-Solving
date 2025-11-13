class Solution {
    public int maxOperations(String s) {
        int size = s.length();
        int answer =0;
        int count =0;
        boolean isZero = false;
        for(int i=0;i<size;i++){
            if(s.charAt(i)=='1'){
                count++;
                isZero=false;
            }
            else if(isZero==false) {
                answer+=count;
                isZero=true;
            }
        }
        return answer;
    }
}
