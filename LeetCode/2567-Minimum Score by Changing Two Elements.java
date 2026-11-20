class Solution {
    public  int minimizeSum(int[] nums) {
        int sz=nums.length;
        Arrays.sort(nums);

        int score1=nums[sz-1]-nums[2];
        int score2=nums[sz-3]-nums[0];
        int score3 =nums[sz-2]-nums[1]; //change one from min elements and one from max elements

        int ans=Math.min(score1,score2);
        ans=Math.min(ans,score3);

        return ans;
    }
}
