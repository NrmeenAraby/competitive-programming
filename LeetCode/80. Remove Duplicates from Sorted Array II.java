class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0)
            return 0;
        int idx=0,freq=0;
        for(int i=1;i< nums.length;i++){
            if(nums[i]!=nums[idx]){
                nums[++idx]=nums[i];
                freq=1;
            }
            else if(freq<2){
                nums[++idx]=nums[i];
                freq=2;
            }
        }

        return idx+1;
    }
}
