class Solution {
    public static int minInsertions(String s) {
        int opn=0,cls=0,ans=0;
        int i=0;
        char [] arr=s.toCharArray();
        int n=s.length();
        while(i<n){
            if(arr[i]=='('){
                opn++;
            }
            else{
                if(i+1<n && arr[i+1]==')'){
                    i++;
                }
                else{
                    ans++; // )
                }

                if(opn>0) {
                    opn--;
                }
                else{
                    ans++; // (
                }
            }
            i++;
        }
        ans+=(opn*2);
        return ans;
    }
}
