class Solution {
    public int sumCounts(List<Integer> nums) {
        int sz=nums.size();
        int ans=0;
        Set<Integer>st=new HashSet<>();
        for(int i=0;i<sz;i++){
            for(int j=i;j<sz;j++){
                st.add(nums.get(j));
                int stSz=st.size();
                ans+=(stSz*stSz);
            }
            st.clear();
        }
        return ans;
    }
}
