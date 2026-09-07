class Solution {
    public int romanToInt(String s) {
        int[] val = new int[128];
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        int ans=0;
        int sz=s.length();
        for(int i=0;i<sz;i++){
            int curr=val[s.charAt(i)];
            if(i+1<sz && curr<val[s.charAt(i+1)]) {
                ans-=curr;
            }
            else{
                ans+=curr;
            }
        }
        return ans;
    }
}
