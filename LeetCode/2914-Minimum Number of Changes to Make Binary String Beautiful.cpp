class Solution {
    public int minChanges(String s) {
        int sz=s.length();
        char[]arr=s.toCharArray();
        int cntr=1;
        int ans=0;
        for(int i=1;i<sz;i++){
            if(arr[i]!=arr[i-1]){
                if(cntr%2==1){
                    ans++;
                    arr[i]=arr[i-1];
                    cntr++;
                }
                else{
                  cntr=1;
                }
            }
            else{
                cntr++;
            }
        }
        return ans;
    }
}
