#include <bits/stdc++.h>
using namespace std;
class Solution{
        private:
        bool dfs(int node, vector<int> &vis,vector<int> &pathVis,vector<int> adj[]){
                vis[node]=1;
                pathVis[node]=1;

                for(auto it:adj[node]){
                        if(!vis[it]){
                             if(dfs(it,vis,pathVis,adj)==true){
                                     return true;
                             } 
                             else if(vis[it]==1 && pathVis[it]==1){
                                     return true;
                             }
                        }
                       
                }
                pathVis[node]=0;
                return false;
        }

        public:
        bool isCyclic(int v,vector<int> adj[]){
                vector<int> vis(v,0);
                vector<int> pathVis(v,0);
                for (int i = 1; i < v; i++)
                {
                        if(!vis[i])
                        if(dfs(i,vis,pathVis,adj)==true){
                                return true;
                        }
                }
                return false;
                

        }
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
	int V = 6;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);
	if (ans) cout << "True";
	else cout << "Flase";
	cout << endl;
	return 0;
}