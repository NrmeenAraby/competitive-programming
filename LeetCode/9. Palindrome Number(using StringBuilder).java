class Solution {
    public boolean isPalindrome(int x) {
        StringBuilder sb=new StringBuilder();
        sb.append(x);
        StringBuilder rev=new StringBuilder(sb).reverse();
        return sb.toString().equals(rev.toString());
    }
}
