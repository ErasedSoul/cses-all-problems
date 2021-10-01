#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(void)
{
     int n,m,q;
     cin>>n>>m>>q;
 
     int dist[n+1][n+1];
 
     for(int i = 1;i <=n;i++)
     {
        for(int  j = 1;j <=n;j++)
        {
             dist[i][j] = 1000000000000000;
             dist[i][i] = 0;
        }
     }
 
     for(int i = 0;i < m;i++)
     {
         int a,b,c;
         cin>>a>>b>>c;
         dist[a][b] = min(c,dist[a][b]);
         dist[b][a] = dist[a][b];
     }
 
 
     // floyd warshall
     for(int k = 1;k <= n;k++)
     {
        for(int  i = 1;i <= n;i++)
        {
            for(int  j = 1;j <= n;j++)
            {
                if(dist[i][k] == LONG_MAX || dist[k][j] == LONG_MAX)
                    continue;
                 if(dist[i][j] > dist[i][k]+ dist[k][j])
                 {
                    dist[i][j] = dist[i][k]+ dist[k][j]; 
                 }
            }
        }
     }
 
 
     for(int  i = 0;i < q;i++)
     {
        int a,b;
        cin>>a>>b;
        if(dist[a][b] >= 1000000000000000)
        cout<<-1<<endl;
        else  
        cout<<dist[a][b]<<endl;  
        
     }   
 
}