#include <bits/stdc++.h>
using namespace std;
const int MOD=32768;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<int>par;
vector<int>sz;
const int mod=1e9+7;

int find(int ch) {
    if(ch==par[ch]) return ch;
    return par[ch]=find(par[ch]);
}
bool uni(int u,int v) {
    u=find(u),v=find(v);
    if(u==v) return false;
    return par[u]=v, true;
}
int main(){
    int t;
    long long n,m,k;
    cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        par.resize(n+1);
        iota(par.begin(),par.end(),0);
        long long u,v,w;
        priority_queue<tuple<long long,long long,long long>>pq;
        vector<long long>wd;
        for(int i=0;i<m;i++) {
            cin>>u>>v>>w;
           pq.emplace(-(w),u,v);
            wd.push_back(w);
        }
        bool flag=false;
        long long ans=0;
       while(!pq.empty()) {
           auto[w,u,v]=pq.top();
           w*=-1;
           pq.pop();
           if(find(u)==find(v))continue;
           uni(u,v);
           if(w>=k) {
               flag=true;
               ans+=(w-k);
           }
       }
        if(!flag) {
            ans=1e9+5;
            for(auto x:wd) {
                ans=min(ans,abs(k-x));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
