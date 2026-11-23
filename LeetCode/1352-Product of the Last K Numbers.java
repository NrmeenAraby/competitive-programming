class ProductOfNumbers {
    List<Integer>prfx;
    public ProductOfNumbers() {
        prfx = new ArrayList<>();
    }

    public void add(int num) {
        if(num==0)
            prfx.clear();
        else if(prfx.isEmpty())
            prfx.add(num);
        else
            prfx.add(num* prfx.get(prfx.size()-1));
    }

    public int getProduct(int k) {
        int sz=prfx.size();
        if(k<sz) {
            int ans =prfx.get(sz-1);
            int idx=sz-k-1;
            ans/=prfx.get(idx);
            return ans;
        }
        else if(k==sz){
            return prfx.get(sz-1);
        }
        else
            return 0;
    }
}
