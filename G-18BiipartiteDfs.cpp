#include<bits/stdc++.h>
using namespace std;

class Solution{
        private:
        bool dfs(int node,int rang,vector<int> adj[],vector<int> &color){
                color[node]=rang;
                for(auto it: adj[node]){
                        if(color[it]==-1){
                                if(dfs(it,!rang,adj,color)==false){
                                        return false;
                                }
                        }
                        else if(color[it]==color[node]){
                                return false;
                        }
                }
                return true;
        }
        public:
        bool isBipartite(int v,vector<int> adj[]){
              vector<int> color(v,-1);
              if(dfs(1,0,adj,color)==false){
                      return false; 
              }
              return true;

        }
}; 


void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
        vector<int>adj[9];
	
	addEdge(adj, 1, 2);
   	addEdge(adj, 2, 3);
	addEdge(adj, 2, 6);
	addEdge(adj, 3, 2);
        addEdge(adj, 3, 4);
        addEdge(adj, 4, 3);
        addEdge(adj, 4, 5);
        addEdge(adj, 4, 7);
        addEdge(adj, 5, 4);
        addEdge(adj, 5, 6);
        addEdge(adj, 6, 2);
        addEdge(adj, 6, 5);
        addEdge(adj, 7, 4);
        addEdge(adj, 7, 8);
        addEdge(adj, 8, 7);

	Solution obj;
	bool ans = obj.isBipartite(9, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n"; 

        
	
	return 0;
}