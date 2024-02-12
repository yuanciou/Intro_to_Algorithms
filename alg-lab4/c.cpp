#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[1005];
int b[1005];
int dp_for_len[1005][1005];
int dp_for_charrter[1005][1005];
int b_notlcs[1005];

#define LEFT_UP 1
#define LEFT 2
#define UP 3

void output(int t, int i, int index)
{
	if (t == 0 || i == 0) 
    {
        return;
    }
	switch (dp_for_charrter[t][i])
    {
        case LEFT_UP:
            b_notlcs[index] = b[i];
            output(t-1, i-1, ++index);
            cout << a[t] <<" ";
            break;
        case LEFT:
            output(t, i-1, index);
            break;    
        case UP:
            output(t-1, i, index);
            break;    
        default:
            break;
    }
}


int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    
    int t, n;
    cin>>t;

    while(t--)
    {
        cin>>n;
        for(int k = 1; k<= n; k++)
        {
            cin>>a[k];
        }
        for(int k = 1; k<= n; k++)
        {
            cin>>b[k];
        }

        //initialize the array of dp
        for (int k=0; k<=n; k++)
        {
            dp_for_len[k][0] = 0;
        }
	    for (int k=0; k<=n; k++)
        {
            dp_for_len[0][k] = 0;
        }

        //dp
        for (int k=1; k<=n; k++)
        {
            for (int i = 1; i<= n; i++)
            {
                if (a[k] != b[i])
                {
                    dp_for_len[k][i] = dp_for_len[k-1][i-1] + 1;
                    dp_for_charrter[k][i] = LEFT_UP;
                }
                else if(dp_for_len[k-1][i] < dp_for_len[k][i-1])
                {
                    dp_for_len[k][i] = dp_for_len[k][i-1];
                    dp_for_charrter[k][i] = LEFT;
                }
                else
                {
                    dp_for_len[k][i] = dp_for_len[k-1][i];
                    dp_for_charrter[k][i] = UP;
                }
            }
        }
        cout<<dp_for_len[n][n]<<"\n";
		output(n, n, 0);
        cout<<"\n";
        for(int k = dp_for_len[n][n] - 1; k >= 0; k--)
        {
            cout<<b_notlcs[k]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

