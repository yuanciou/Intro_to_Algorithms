#include <iostream>
#include <algorithm> 
using namespace std;

typedef struct item
{
    int index;
    int l;
    int r;
}item;

int compare(item a, item b)
{
    if(a.l!=b.l)
    {
        return a.l<b.l;
    }
    else
    {
        return a.r>b.r;
    }
}

/*
item* merge(item *a, int n, item *b, int m)
{
    item *merarr = new item[n+m];
    int i = 0, j = 0, k = 0;

    while(i<n || j<m)
    {
        if(i<n && j<m)
        {
            if(a[i].l<b[j].l)
            {
                merarr[k++] = a[i++];
            }
            else if(a[i].l>b[j].l)
            {
                merarr[k++] = a[j++];
            }
            else
            {
                if(a[i].r<b[j].r)
                {
                    merarr[k++] = a[i++];
                }
                else
                {
                    merarr[k++] = b[j++];
                }
            }
        }
        else
        {
            merarr[k++] = ((i<n)?a[i++]:b[j++]);
        }
    }
    return merarr;
}

void mergesort(item *a, int n)
{
    if(n==1) return;

    int k = n/2;
    mergesort(a,k);
    mergesort(a+k, n-k);

    item *r = merge(a, k, a+k, n-k);
    memcpy(a, r, sizeof(item)*n);
}
*/

item arr[200001];
int re1[200001] = {0};
int re2[200001] = {0};

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);               
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        arr[i].index = i;
        cin>>arr[i].l>>arr[i].r;
    }
    /*
    for(int k = 0;k<n;k++)
    {
        cout<<arr[k].index<<" "<<arr[k].l<<" "<<arr[k].r<<"\n";
    }
    */
    //mergesort(arr, n);
    //sort
    sort(arr, arr+n, compare);
    /*
    for(int k = 0;k<n;k++)
    {
        cout<<arr[k].index<<" "<<arr[k].l<<" "<<arr[k].r<<"\n";
    }
    */
    
    //包含別人
    int rmin = arr[n-1].r;
    for(int r = n-2;r>=0;r--)
    {
        //cout<<rmin<<"\n";
        if(arr[r].r<rmin)
        {
            rmin = arr[r].r;
            if((arr[r].l == arr[r-1].l)&&(arr[r].r == arr[r-1].r))
            {//下面的會跑到上面重複，但上面得不會跑到下面有重複的
                re2[arr[r].index] = 1;
            }
        }
        else
        {
            re2[arr[r].index] = 1;
        }
    }
        //第一個
    if((arr[n-1].l == arr[n-2].l)&&arr[n-1].r == arr[n-2].r)
    {
        re2[arr[n-1].index] = 1;
    }
    for(int z = 0;z<n;z++)
    {
        cout<<re2[z]<<" ";
    }
    cout<<"\n";


    //被包含
    int rmax = arr[0].r;
    for(int r = 1;r<n;r++)
    {
        if(arr[r].r>rmax)
        {
            rmax = arr[r].r;
            if((arr[r].l == arr[r+1].l)&&(arr[r].r == arr[r+1].r))
            {//下面的會跑到上面重複，但上面得不會跑到下面有重複的
                re1[arr[r].index] = 1;
            }
        }
        else
        {
            re1[arr[r].index] = 1;
        }
    }
        //第一個
    if((arr[0].l == arr[1].l)&&arr[0].r == arr[1].r)
    {
        re1[arr[0].index] = 1;
    }
    for(int z = 0;z<n;z++)
    {
        cout<<re1[z]<<" ";
    }
    cout<<"\n";

    return 0;
}