#include <bits/stdc++.h>
using namespace std;


class Solution{
     private:
     void dfs(int node,vector<int> &vis,vector<int> adj[]){
               vis[node]=1;
               for(auto it : adj[node]){
                       if(!vis[it]){
                               dfs(it,vis,adj);
                       }

               }
     }

     /* void addEdge(vector<int> gpp[],int v,int u){
             gpp[v].push_back(u);
             gpp[u].push_back(v);
     } */

     public:
      int numProvinces(vector<int> adj[],int n){
              /* vector<int> gpp[n];
             for (int i = 0; i < adj.size(); i++)
             {
                     for (int j = 0; j <adj[i].size() ; j++)
                     {
                             if(adj[i][j]==non 1 && i!=j){
                                     addEdge(gpp,i,j);
                             }
                     }
                     
             } */

             vector<int> vis(n+1,0);
             int cnt=0;
             for (int i = 1; i <= n; i++)
             {
                     if(!vis[i]){
                             cnt+=1;
                             dfs(i,vis,adj);
                     }
             }

             return cnt;
             
        }
};


void addEdge(vector<int> adj[],int v,int u){
        adj[v].push_back(u);
        adj[u].push_back(v);
}

int main() {
    int n=4;
    int m=2;
    vector<int> adj[n];
    addEdge(adj,1,2);
    addEdge(adj,3,4);

    Solution ob;
    cout << ob.numProvinces(adj,n) << endl;
    return 0;
}