#include<bits/stdc++.h>
using namespace std;

class solution{
        private:
        void dfs(vector<int> adj[],int node,vector<int> &ls, vector<int> &vis){
                 vis[node]=1;
                 ls.push_back(node);
                 for (auto it : adj[node])
                 {
                        if(!vis[it]){
                                dfs(adj,it,ls,vis);
                        }
                 }

                 
                 
        }
        public:
        vector<int> dfsOfGraph(vector<int> adj[],int x){
                vector<int> vis(x,0);
                int start=1;
                vector<int> ls;
                dfs(adj,start,ls,vis);
                return ls;
        }
};

void addEdge(vector<int> adj[],int v,int u){
        adj[v].push_back(u);
        adj[u].push_back(v);
}

void print(vector<int> &ans){
        for (int i = 0; i < ans.size(); i++)
        {
                cout<<ans[i]<<" ";
        }
        cout<<endl;
        
}

int main(){
        vector<int> adj[9];
        addEdge(adj,1,2);
        addEdge(adj,1,3);
        addEdge(adj,2,5);
        addEdge(adj,2,6);
        addEdge(adj,3,4);
        addEdge(adj,3,7);
        addEdge(adj,4,8);
        addEdge(adj,7,8);

        solution obj;
        vector<int> ans=obj.dfsOfGraph(adj,9);
        print(ans);
       
}