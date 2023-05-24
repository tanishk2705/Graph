#include<bits/stdc++.h>
using namespace std;

class Solution {
        private:
        void dfs(int node,vector<int> adj[], vector<int> &vis,stack<int> &st){
                 vis[node]=1;
                 for(auto it : adj[node]){
                         if(!vis[it]){
                                 dfs(it,adj,vis,st);
                         }
                 }
                 st.push(node);

        }
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int v, vector<int> adj[])
	{
                vector<int> ans;
                vector<int> vis(v,0);
                stack<int> st;
                for (int i = 0; i < v; i++)
                {
                        if(!vis[i]){
                            dfs(i,adj,vis,st);
                        }
                        
                }

                while(!st.empty()){
                        ans.push_back(st.top());
                        st.pop();
                }
                return ans;
                
        }
};

int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}