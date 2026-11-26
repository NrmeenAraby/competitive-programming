class Solution {
    public boolean canAliceWin(int n) {
        int st=10;
        boolean flag=false;
        while(st>0){
            n-=st;
            if(n>=0){
                if(st%2==0)
                   flag=true;
                else
                   flag=false;
            }
            else{
                break;
            }
            st--;
        }
        return flag;
    }
}
