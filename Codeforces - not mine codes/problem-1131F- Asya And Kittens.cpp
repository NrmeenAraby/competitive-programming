#include <bits/stdc++.h>
using namespace std;
const int MOD=32768;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<int>par,nxt,lst;
vector<int>sz;
const int mod=1e9+7;

int find(int ch) {
    if (ch==par[ch]) return  ch;
    return  par[ch]=find(par[ch]);
}
bool uni(int u,int v) {
    u=find(u),v=find(v);
    if(u==v) return false;
    else {
        par[v]=u;
        nxt[lst[u]]=v;
        lst[u]=lst[v];
        return true;
    }
}
int main(){
    int n ;
    cin>>n;
    par.resize(n+1);
    lst.resize(n+1);
    nxt.assign(n+1,-1);
    iota(par.begin(),par.end(),0);
    iota(lst.begin(),lst.end(),0);
    int u,v;
    for(int i=0;i<n-1;i++) {
        cin>>u>>v;
        uni(u,v);
    }
    int node=find(1);
    while(node!=-1) {
        cout<<node<<" ";
        node=nxt[node];
    }
    return 0;
}
