#include <bits/stdc++.h>
#define ll long long 
#define vi vector<ll>
#define vii vector<vector<ll>>
#define vb vector<bool>
#define pr pair<ll,ll>
#define pb push_back
#define all(x) x.begin(),x.end()
#define mod 1e9+7
#define deb(x) cout<<#x<<" "<<x<<endl;
#define fo(i,n) for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define INF 100000000000000000
#define NINF INF*(-1)
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
 
       #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
       #endif
       ios_base::sync_with_stdio(false);
       cin.tie(0);
       cout.tie(0);
 
       solve();
}
 
 
void sssp(int n,int k, vector<vector<pair<int,int>>>& adj)
{
    
       vector< vector<ll> >dist(n+1,vector<ll>(k,INF));
 
       dist[1][0] = 0;
       
       priority_queue<pair<ll,ll> , vector<pair<ll,ll>>,greater<pair<ll,ll>> >pq;
 
       pq.push({0,1});
 
       while(!pq.empty())
       {
          auto temp = pq.top();
          pq.pop();
 
 
          ll a = temp.second; // u 
          ll d = temp.first; //dist[u]
 
          if(dist[a][k-1] < d) 
            continue;
 
          for(auto x : adj[a])
          {
              ll b = x.first; // v
              ll D = x.second; // dist[u][v]
 
              if(d+D < dist[b][k-1])
              {
                dist[b][k-1] = d+D;
                pq.push({dist[b][k-1],b});
                sort(all(dist[b]));
              } 
          }           
       }
 
    for(int  i = 0;i < k;i++)
    {
        cout<<dist[n][i]<<" ";
    }
    cout<<endl;
 
}
 
void solve()
{ 
     ll n,m,k;
    cin>>n>>m>>k;
    
    vector<vector<pair<int,int>>>adj(n+1,vector<pair<int,int>>());
 
    for(int i=0;i < m;i++){
 
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb(make_pair(b,c));
    }
    // running  the single source shortest path
    sssp(n,k,adj);
 
}
