class Solution {
    public int minChanges(String s) {
        int sz=s.length();
        int ans=0;
        for(int i=1;i<sz;i+=2){
           if(s.charAt(i)!=s.charAt(i-1)){
               ans++;
           }
        }
        return ans;
    }
}
