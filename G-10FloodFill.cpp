#include <bits/stdc++.h>
using namespace std;
class Solution{
        public:
        vector<vector<int>> floodfill(vector<vector<int>>& image, int sr, int sc, int color){
                vector<vector<int>> ans;
                ans=image;
                int n=image.size();
                int m=image[0].size();

                vector<vector<int>> vis(n,vector<int>(m,0));
                queue<pair<int,int>> q;
                q.push({sr,sc});
                vis[sr][sc]=1;
                ans[sr][sc]=color;

                while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();

                        int delrow[]={-1,0,1,0};
                        int delcol[]={0,1,0,-1};
                        for (int i = 0; i < 4; i++)
                        {
                                int nrow=row+delrow[i];
                                int ncol=col+delcol[i];

                                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && ans[nrow][ncol]==1){
                                        ans[nrow][ncol]=color;
                                        vis[nrow][ncol]=1;
                                        q.push({nrow,ncol});

                                }
                        }
                        


                }

                return ans;
        }
};

int main(){
     vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
     int sr=1;
     int sc=1;
     int colour=2;
     Solution obj;
     vector<vector<int>> ans=obj.floodfill(image,sr,sc,colour);
     for (int i = 0; i < image.size(); i++)
     {
             for (int j = 0; j < image[0].size(); j++)
             {
                     cout<<ans[i][j]<<" ";
             }
             cout<<endl;
             
     }
     
}