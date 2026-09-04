class Solution {
 public String convert(String s, int numRows) {
         if (numRows == 1 || numRows >= s.length())
        return s;
        StringBuilder[]rows=new StringBuilder[numRows];
        for(int i=0;i<numRows;i++)
            rows[i]=new StringBuilder();
        int idx=0;
        boolean flag=true;
        for(Character ch:s.toCharArray()){
            rows[idx].append(ch);

            if(idx==numRows-1)
                flag=false;
            else if(idx==0)
                flag = true;

            idx+= flag? 1:-1;
        }
        StringBuilder ans=new StringBuilder();
        for(int i=0;i<numRows;i++){
            ans.append(rows[i]);
        }
        return ans.toString();
    }
}
