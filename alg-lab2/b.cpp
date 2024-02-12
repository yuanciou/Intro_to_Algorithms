#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//int siz;

struct node
{
    long long val, pre, suf, sum;
};

struct segt{
    vector <node> nodes;
    int size;
    void decide_size(int n){
        size = 1;
        while(size < n)
        {
            size = size * 2;
        }
        //siz = size;
        nodes.resize(2*size);
    }

    node single_node(int v)
    {
        if(v >= 0)
        {
            return{v, v, v, v};
        }
        else
        {
            return{0, 0, 0, v};
        }
    }

    void update(int k, int x, int p, int l, int r)
    {
        if(r - l == 1)// int the right position
        {
            nodes[p] = single_node(x);
            return;
        }
        int mid = (l + r) / 2;
        if(k < mid)
        {
            update(k, x, 2*p+1, l, mid);
        }
        else
        {
            update(k, x, 2*p+2, mid, r);
        }
        nodes[p] = merge(nodes[2*p+1] , nodes[2*p+2]);
    }
    void update(int k, int x) // 因為main裡面不會知道size
    {
        update(k, x, 0, 0, size);
    }

    node merge(node a, node b)
    {
        return
        {
            max(a.val, max(b.val, (a.suf+b.pre))),
            max(a.pre, (a.sum + b.pre)),
            max(b.suf, (b.sum + a.suf)),
            a.sum + b.sum
        };
    }

    node oper(int l, int r, int p, int lnode, int rnode)
    {
        if(lnode >= r || rnode <= l)
        {
            return{0, 0, 0, 0};
        }
        else if(lnode >= l && rnode <= r)
        {
            return nodes[p];
        }
        else
        {
            int mid = (lnode + rnode) / 2;
            node s1 = oper(l, r, 2*p+1, lnode, mid);
            node s2 = oper(l, r, 2*p+2, mid, rnode);
            return merge(s1, s2);
        }
    }

    node oper(int l, int r)
    {
        return oper(l-1, r, 0, 0, size);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout<<"HH";
    int n;
    int q;
    cin>>n>>q;
    //cout<<"HH";
    struct segt st;
    st.decide_size(n);
    //cout<<"HH";
    for(int k = 0;k<n;k++)
    {
        int x;
        cin>>x;
        st.update(k, x);
    }
    for(int k = 0;k<q;k++)
    {
        int operation;
        cin>>operation;
        if(operation == 1)
        {
            int x, y;
            cin>>x>>y;
            st.update(x-1, y);
        }
        else
        {
            int l, r;
            cin>>l>>r;
            if(operation == 2)
            {
                cout<<st.oper(l, r).sum<<"\n";
            }
            else if(operation == 3)
            {
                cout<<st.oper(l, r).pre<<"\n";
            }
            else
            {
                cout<<st.oper(l, r).suf<<"\n";
            }
        }
    }
    return 0;
}