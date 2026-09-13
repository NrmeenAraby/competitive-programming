class Solution {
      public String longestCommonPrefix(String[] strs) {
        StringBuilder ans=new StringBuilder();
        for(int i=0;i<strs[0].length();i++){
            char curr=strs[0].charAt(i);
            for(int idx=1;idx<strs.length;idx++){
                if(i>=strs[idx].length() || strs[idx].charAt(i)!=curr)
                    return ans.toString();
            }
            ans.append(curr);
        }
        return ans.toString();
    }
}
