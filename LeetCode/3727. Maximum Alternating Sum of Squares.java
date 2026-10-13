class Solution {
    public long maxAlternatingSum(int[] nums) {
        int sz=nums.length;
        for(int i=0;i<sz;i++){
            nums[i]*=nums[i];
        }
        Arrays.sort(nums);
        int idx=0;
        int half=sz/2;
        long ans=0;
        for(int i=sz-1;i>=half;i--){
            ans+=nums[i];
        }
        for(int i=0;i<half;i++)
            ans-=nums[i];
        return ans;
    }
}
