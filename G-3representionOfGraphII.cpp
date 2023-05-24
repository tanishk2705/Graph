#include<bits/stdc++.h>
using namespace std;

class Solution{
        public:
        vector<int> bfsOfGraph(vector<int> adj[],int x){
              vector<int> vis(x,0);
              vis[1]=1;
              queue<int> q;
              q.push(1);

              vector<int> bfs;
              while(!q.empty()){
                      int node=q.front();
                      q.pop();
                      bfs.push_back(node);
                      for(auto it: adj[node]){
                              if(!vis[it]){
                                      vis[it]=1;
                                      q.push(it);
                              }
                      }
                      

                      
              }
              return bfs;
        }

};


void addEdge(vector<int> adj[],int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
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
             

        Solution obj;
        vector<int> ans=obj.bfsOfGraph(adj,9);
        print(ans);

}