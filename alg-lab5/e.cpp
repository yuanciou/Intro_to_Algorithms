#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*TO DO
1. 如果有一個wire ui vi ci Node N1, N2
    ->if(ci<N1 or N2) 把她連起來
2. d = -1的一定要至少連到一個發電廠
3. 加一個新的點把她連到所有發電廠
4. MST
*/
struct Edge{
    long long u;
    long long v;
    long long c;
};

bool operator<(Edge a, Edge b){
    return a.c < b.c;
}
// disjoint set function
long long which_set[200005];
long long find(long long x)
{
    if(x == which_set[x])
    {
        return x;
    }
    else
    {
        return which_set[x] = find(which_set[x]);
    }
}
void merge(long long x, long long y)
{
    which_set[find(x)] = find(y);
}

vector<Edge> edge; 

int main(){
    long long n, m, sum;
    sum = 0;
    cin>>n>>m;
    for(long long i = 1; i<=n; i++)
    {
        long long d;
        cin>>d;
        if(d>(-1))
        {
            edge.push_back({0, i, d});
        }
    }
    for(long long i = 1; i<=m; i++)
    {
        Edge tmp;
        cin>>tmp.u>>tmp.v>>tmp.c;
        edge.push_back(tmp);
    }
    
    // use Kruskal find MST

    //initialize
    for(int i = 0; i<200005;i++)
    {
        which_set[i] = i;
    }

    sort(edge.begin(), edge.end());

    long long i, j;
    long long number_edge = edge.size();
    for(i = 0, j = 0; i<n && j < number_edge; i++)
    {
        while(find(edge[j].u) == find(edge[j].v))
        {
            j++;
        }
        sum = sum + edge[j].c;
        merge(edge[j].u, edge[j].v);
        j++;
    }
    cout<<sum<<"\n";
    return 0;
}