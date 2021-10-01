#pragma warning(push,1)
#include <bits/stdc++.h>
#pragma warning(pop)
#define ll long long 
#define vi vector<ll>
#define vii vector<vector<ll>>
#define vb vector<bool>
#define pr pair<ll,ll>
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define mod 1e9+7
#define deb(x) cout<<#x<<" "<<x<<endl;
#define fo(i,n) for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define INF 10000000000000000
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
 
struct node{
    int a,b,c;
    node(int a, int b,int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
void bellmanford(int n, vector<node>& edges)
{
       vi dist(n+1, INF);
       dist[1] = 0;
       vi par(n+1,-1);
 
       for(int i = 1;i < n;i++)
       {
            for(auto x : edges)
            {
                 if(dist[x.a]+x.c >= INF)
                    continue;
 
                 if(dist[x.a]+x.c < dist[x.b])
                 {
                    dist[x.b] = dist[x.a]+x.c;
                    par[x.b] = x.a;
                 }
            }
       }
       bool check = false;
       int p = -1;
       for(auto x : edges)
       {
          if(dist[x.a]+x.c >= INF)
            continue;
 
          if(dist[x.a]+x.c  < dist[x.b])
          {
                    dist[x.b] = dist[x.a]+x.c;
                    par[x.b] = x.a;
                    p = x.b;
                    check = true;
          }
       }
       if(!check){
          cout<<"NO"<<endl;
          return;
       }
       cout<<"YES"<<endl;
 
       for(int  i = 0;i < n;i++)
       {
           p = par[p];
       }
 
       map<int,int>mp;
        vi ans;
        while(1)
        {
            ans.pb(p);
 
            if(mp.find(p)!= mp.end())
              break;
 
            mp[p]=1;
            p = par[p];     
        }
        reverse(all(ans));
        for(auto x : ans)
            cout<<x<<" ";
        cout<<endl;
 
}
void solve()
{ 
    int n,m;
    cin>>n>>m;
 
     vector<node>edges;
 
     int  i;
     fo(i,m)
     {
          ll a,b,c;
          cin>>a>>b>>c;
 
          edges.pb(node(a,b,c));
     }
 
 
     bellmanford( n,edges);
}
int main(void)
{ 
 
       ios_base::sync_with_stdio(false);
       cin.tie(0);
       cout.tie(0);
 
       solve();
}
