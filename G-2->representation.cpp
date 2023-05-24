#include<bits/stdc++.h>
using namespace std;

int main(){
        int n,m;
        cin>>n>>m;
        int adj[n+1][m+1]; //O(nxn)
        for (int i = 0; i < m; i++)
        {
                int u,v;
                cin>>u>>v;
                adj[u][v]=1;
                adj[v][u]=1;
        }


        vector<int> adj2[n+1];  //O(E)
        for (int i = 0; i < m; i++)
        {
                int u,v;
                cin>>u>>v;
                adj2[u].push_back(v);
                adj2[v].push_back(u);
        }
        
        
}