#include <bits/stdc++.h>
#define ll long long 
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pr pair<int,int>
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define mod 1e9+7
#define deb(x) cout<<#x<<" "<<x<<endl;
#define fo(i,n) for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
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
 /*Guyhjj ijhhnn*/
       solve();
}
 
void solve()
{
 
     ll INF = 1e17;
     ll NINF = INF*(-1); 
     int n,m;
     read(n,m);
     struct node{
         ll a,b,x;
         node(ll a ,ll b,ll c){
 
            this->a = a;this->b = b;
            this->x = c;
 
         }
     }; 
     vector<node>adj;
     ll i,a,b,x;
     fo(i,m)
     {
        read(a,b,x);
        adj.pb(node(a,b,-x));
     }
 
     vector<ll>dist(n+1,INF);
 
     dist[1] = 0;
 
     fo(i,n-1)
     {
        for(auto A : adj)
        {
 
            if(dist[A.a] == INF)
                continue;
            if(dist[A.a]+A.x < dist[A.b])
            {
                dist[A.b] = dist[A.a]+A.x;
 
                dist[A.b] = max(dist[A.b],NINF);
            }
        }
     }
     
     fo(i,n-1){
     for(auto A : adj)
     {
 
        if(dist[A.a] == INF)
                continue;
        if(dist[A.a]+A.x < dist[A.b])
            {
                dist[A.b] = NINF;
            }
     }
 }
 
     if(dist[n] == NINF)
     {
        cout<<-1<<endl;
     }
     else
     {
        cout<<dist[n]*(-1)<<endl;
     }                                                   
}
