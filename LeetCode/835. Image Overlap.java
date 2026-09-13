class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        record Pair(int x, int y) {}
        Map<Pair,Integer>mp=new HashMap<>();
        int len=img1.length;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(img1[i][j]==0)
                    continue;
                for(int m=0;m<len;m++){
                    for(int n=0;n<len;n++){
                        if(img2[m][n]==0)
                            continue;

                        int dx=i-m;
                        int dy=j-n;
                        Pair p=new Pair(dx,dy);
                        mp.put(p,mp.getOrDefault(p,0)+1);
                    }
                }
            }
        }
        int mx=0;
        for(var m:mp.entrySet()){
            mx=Math.max(mx,m.getValue());
        }
        return mx;
    }
}
