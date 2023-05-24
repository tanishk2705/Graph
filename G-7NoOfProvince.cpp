#include <bits/stdc++.h>
using namespace std;


class Solution{
     private:
     void dfs(int node,vector<int> &vis,vector<int> gpp[]){
               vis[node]=1;
               for(auto it : gpp[node]){
                       if(!vis[it]){
                               dfs(it,vis,gpp);
                       }

               }
     }

     void addEdge(vector<int> gpp[],int v,int u){
             gpp[v].push_back(u);
             gpp[u].push_back(v);
     }

     public:
      int numProvinces(vector<vector<int>> &adj,int n){
              vector<int> gpp[n];
             for (int i = 0; i < adj.size(); i++)
             {
                     for (int j = 0; j <adj[i].size() ; j++)
                     {
                             if(adj[i][j]==1 && i!=j){
                                     addEdge(gpp,i,j);
                             }
                     }
                     
             }

             vector<int> vis(n,0);
             int cnt=0;
             for (int i = 0; i < vis.size(); i++)
             {
                     if(!vis[i]){
                             cnt+=1;
                             dfs(i,vis,gpp);
                     }
             }

             return cnt;
             
        }
};


int main() {
    
    vector<vector<int>> adj
    {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

        
    Solution ob;
    cout << ob.numProvinces(adj,3) << endl;
        
    return 0;
}