#include <bits/stdc++.h>
#define ll long long 
#define vi vector<ll>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pr pair<ll,ll>
#define pb push_back
#define all(x) x.begin(),x.end()
#define mod 1e9+7
#define deb(x) cout<<#x<<" "<<x<<endl;
#define fo(i,n) for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define INF 100000000000000000
using namespace std;
template<typename... T>
void read(T&... args)
{
    ((cin>>args),...);
}
 
template<typename... T>
void write(T&&... args)
{
    ((cout<<args<<" "),...);
}
 
void solve();
int main(void)
{ 
       ios_base::sync_with_stdio(false);
       cin.tie(0);
       cout.tie(0);
 
       solve();
}
 
ll dijstra(int n ,vector<vector<pr>>& adj)
{
      vi dist(n+1,INF);
      vector<pr> par(n+1,{-1LL,0LL});
      vi vis(n+1,0);
 
      priority_queue<pair<pr,ll>,vector<pair<pr,ll>>,greater<pair<pr,ll>>> pq;
 
      pq.push({{0LL,1LL},0LL});
      dist[1] = 0LL;
      par[1] = {-1LL,0LL};
 
      while(!pq.empty())
      {
           auto temp = pq.top();
           pq.pop();
           ll a = temp.first.second;
           ll d = temp.second;
           ll ds = temp.first.first; 
           if(a == n)
           {
              dist[n] = min(dist[n],ds-d+d/2);
              continue;
           }
 
           if(vis[a])
              continue;
 
           vis[a] = 1;
           for(auto x : adj[a])
           {
              ll b = x.first;
              ll w = x.second;
 
              if(b == n)
              {
                pq.push({{dist[a]+w,b},max(d,w)});
                continue;
              }
 
              if(!vis[b])
              {
                   if(dist[b] > dist[a]+w)
                   {
                       dist[b] = dist[a]+w;
                       par[b] = {a,w};
                       pq.push({{dist[b],b},max(d,w)});
                   }
              }  
           }
      }
 
      return dist[n];
}
 
 
void solve()
{ 
    int n,m;
    cin>>n>>m;
 
    vector<vector<pr>>adj(n+1,vector<pr>());
    int i;
    fo(i,m)
    {
        ll a,b,c;
        read(a,b,c);
 
        adj[a].pb({b,c});
    }
 
    ll ans = dijstra(n,adj);
 
    cout<<ans<<endl;
}
