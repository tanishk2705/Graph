#include<bits/stdc++.h>
using namespace std;

class Solution{
        public:
        bool isBipartite(int v,vector<int> adj[]){
              vector<int> color(v,-1);
              queue<pair<int,int>> q;
              q.push({1,0});
              color[0]=0;
              while (!q.empty())
              {
                       int node=q.front().first;
                       int rang=q.front().second;
                       q.pop();
                       for(auto it: adj[node]){
                                if(color[it]==-1 && color[node]!=color[it]){
                                    color[it]=~rang;
                                    q.push({it,~rang}); 
                                }
                                else if(color[node]==color[it]){
                                        return false;
                                }
                       }
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