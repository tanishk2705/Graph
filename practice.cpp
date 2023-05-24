#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
      bool bfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathvis){
           vis[node]=1;
           pathvis[node]=1;

           for(auto it : adj[node]){
               if(!vis[it] && !pathvis[it]){
                  if( bfs(it,adj,vis,pathvis)==true){
                          return true;
                  }
                       
                   
               }
               else if(vis[it] && pathvis[it]){
                   return true;
               }
           }
           pathvis[node]=0;
           return false;

      }
    
    public: 
    bool isCyclic(int v,vector<int> adj[]){
        vector<int> vis(v,0);
        vector<int> pathvis(v,0);
        for (int i = 0; i < v; i++)
        {
            if(!vis[i]){
                 if(bfs(i,adj,vis,pathvis)==true){
                     return true;

                 }
            }
           
        }
        return false;
        
    }
    
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
   vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
	int V = 6;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);
	if (ans) cout << "True";
	else cout << "Flase";
	cout << endl;
	return 0;
}
