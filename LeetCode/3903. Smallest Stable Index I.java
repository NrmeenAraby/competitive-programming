class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int sz=nums.length;
        int []prfxMx=new int[sz];
        int []sufxMn=new int[sz];
        prfxMx[0]=nums[0];
        for(int i=1;i<sz;i++){
           prfxMx[i]=Math.max(prfxMx[i-1],nums[i]);
        }
        sufxMn[sz-1]=nums[sz-1];
        for(int i=sz-2;i>=0;i--){
            sufxMn[i]=Math.min(sufxMn[i+1],nums[i]);
        }
        int idx=-1;
        for(int i=0;i<sz;i++){
            if(idx==-1 &&prfxMx[i]-sufxMn[i]<=k){
                idx=i;
                break;
            }
        }
        return idx;
    }
}
