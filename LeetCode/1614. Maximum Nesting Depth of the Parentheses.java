class Solution {
    public int maxDepth(String s) {
        int mx=0, cntr=0;
        for (char c:s.toCharArray()){
            if(c=='('){
                cntr++;
            }
            if( c ==')'){
                mx=Math.max(mx,cntr);
                cntr--;
            }
        }
        return mx;
    }
}
