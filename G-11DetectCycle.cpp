#include<bits/stdc++.h>
using namespace std;

class Solution{
        private:
        bool detect(vector<int> &vis,vector<int> adj[],int node){
            vis[node]=1;
            queue<pair<int,int>> q;
            q.push({node,-1});

            while (!q.empty())
            {
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();

                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it]=1;   
                         q.push({it,node});
                    }
                    else if(parent!=it){
                          return true;
                    }
                }
            }

            return false;
            


        }
        public:
        bool isCycle(int v,vector<int> adj[]){
              vector<int> vis(v,0);
              for (int i = 0; i < v; i++)
              {
                     if(!vis[i]){
                        if(detect(vis,adj,i)==true){
                            return true;
                        }

                     } 
              }
              return false;
              
        }
};

int main(){
        // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
     Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}