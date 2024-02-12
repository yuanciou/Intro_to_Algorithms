#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*TO DO
1.用stack紀錄目前走道的點判定四個方向
*/
int maze[4005][4005]; //1->障礙  0->可以走
pair<int, int> direction[8] = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0},{-1, -1}, {0, -1}, {1, -1}};


int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);              
    int t;
    cin>>t;
    int flag = 0;
    while(t--)
    {   
        flag = 0;
        int n, m, k;
        cin>>n>>m>>k;
        //initialize
        for(int i = 0;i<n + 2;i++)
        {
            for(int j = 0;j<m+1;j++)
            {
                maze[i][j] = 0;
            }
        }
        /*
        for(int i = 0; i < n + 2; i++)
        {
            maze[i][0] = 1;
            maze[i][m + 1] = 1;
        }
        for(int i = 0; i < m + 1; i++)
        {
            maze[0][i] = 1;
            maze[n + 1][i] = 1;
        }*/
       /* for(int i = 0;i<n + 2;i++)
        {
            for(int j = 0;j<m+2;j++)
            {
                cout<< maze[i][j] <<" ";
            }
            cout<<"\n";
        }*/
        stack <pair<int, int>> visited_obs;
        for(int i = 0;i<k;i++)
        {
            int x, y;
            cin>>x>>y;
            maze[x][y] = 1;
            if(x == 1 || y == m)
            {
                visited_obs.push({x, y});
            }
        }
        /*for(int i = 0;i<n + 2;i++)
        {
            for(int j = 0;j<m+2;j++)
            {
                cout<< maze[i][j] <<" ";
            }
            cout<<"\n";
        }*/
        if(maze[1][1] == 1)
        {
            cout<<"NO\n";
            flag = 1;
            continue;
        }
        else
        {
            //走到上面或是右邊
            /*
            for(int i = 1; i<=n; i++)
            {
                if(maze[i][1] == 1)
                {
                    visited_obs.push({i, 1});
                }
            }
            for(int i = 2; i<=m; i++)
            {
                if(maze[n][i] == 1)
                {
                    visited_obs.push({n, i});
                }
            }
            */
            pair<int, int> current;
            //cout<<"\n";
            while(!visited_obs.empty())
            {
                current = visited_obs.top(); 
                //cout<<current.first<<" "<<current.second<<"\n";
                visited_obs.pop();
                if(maze[current.first][current.second] == 1)
                {
                    maze[current.first][current.second] = 2;
                }
                
                for(int i = 0; i<8; i++)
                {//&& maze[current.first + direction[i].first][current.second + direction[i].second] == 1
                    if((current.first + direction[i].first == n || current.second + direction[i].second == 1) && maze[current.first + direction[i].first][current.second + direction[i].second] == 1)
                    {
                        if(flag == 0)
                        {
                            cout<<"NO\n";
                            flag = 1;
                            break;
                        }
                    }
                    if(maze[current.first + direction[i].first][current.second + direction[i].second] == 1)
                    {
                        visited_obs.push({current.first + direction[i].first, current.second + direction[i].second});
                        
                    }
                }
                /*if(back == 1)
                {
                    visited_obs.pop();
                }*/
                if(flag == 1)
                {
                    break;
                }
            }
           /*for(int i = 0;i<n + 2;i++)
            {
                for(int j = 0;j<m+2;j++)
                {
                    cout<< maze[i][j] <<" ";
                }
                cout<<"\n";
            }*/
            if(flag == 0)
            {
                cout<<"YES\n";
            }
        }

    }
    return 0;
}