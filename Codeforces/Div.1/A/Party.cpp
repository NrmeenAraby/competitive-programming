#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
//vector<int>vis;
vector<int>topo_order;
int cntr=1,mx=0;
void dfs(int s) {
 // vis[s]=1;
  for(auto neig:adj[s]) {
   // if(!vis[neig]) {
      cntr++;
      dfs(neig);
      cntr--;
   // }
  }
  mx=max(mx,cntr);
}
int main(){
    int n;
    cin>>n;
 // vis.assign(n+1,0);
  adj.resize(n+1);
  int p;
  for(int i=1;i<=n;i++) {
    cin>>p;
    if(p!=-1) {
      adj[p].push_back(i);
    }
  }
  for(int i=1;i<=n;i++) {
  // if(!vis[i])
      dfs(i);
  }
  cout<<mx;
  return 0;
}
