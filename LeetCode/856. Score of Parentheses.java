class Solution {
    public int scoreOfParentheses(String s) {
        int depth=0;
        int ans=0;
        boolean before=false;
        for(char c:s.toCharArray()){
            if(c=='('){
                depth++;
                before=true;
            }
            else{
                depth--;
                if(before){
                    ans += (Math.pow(2,depth));
                    before=false;
                }

            }
        }
        return ans;
    }
}
