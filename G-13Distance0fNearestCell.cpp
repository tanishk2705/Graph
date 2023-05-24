#include<bits/stdc++.h>
using namespace std;

class Solution{
        public:
        vector<vector<int>> nearest(vector<vector<int>>&grid){
             vector<vector<int>> ans( grid.size(),vector<int>(grid[0].size(),0));
             queue<pair<pair<int,int>,int>> q;
             vector<vector<int>> vis( grid.size(),vector<int>(grid[0].size(),0));
             for (int i = 0; i < grid.size(); i++)
             {
                     for (int j = 0; j < grid[0].size(); j++)
                     {
                             if(grid[i][j]==1){
                                  vis[i][j]=1;
                                  q.push({{i,j},0});
                             }
                     }
                     
             }


             
             while (!q.empty())
             {
                     int row=q.front().first.first;
                     int col=q.front().first.second;
                     int step=q.front().second;
                     q.pop();
                     ans[row][col]=step;

                     int delrow[]={-1,0,1,0};
                     int delcol[]={0,1,0,-1};
                     
                     for (int i = 0; i < 4; i++)
                     {
                             int nrow=row+delrow[i];
                             int ncol=col+delcol[i];
                     
                     if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol]){
                                   vis[nrow][ncol]=1;
                                   q.push({{nrow,ncol},step+1});
                     }
                     }
                     
             }
             return ans;
        }
};

int main(){
        vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	Solution obj;
	vector<vector<int>> ans = obj.nearest(grid);
		
        for (int  i = 0; i < grid.size(); i++)
        {
               for (int j = 0; j < grid[0].size(); j++)
               {
                       cout<<ans[i][j]<<" ";
               }
               cout<<endl;
               
        }
        
}
        
	