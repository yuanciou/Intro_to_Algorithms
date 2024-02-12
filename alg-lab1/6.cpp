#include <bits/stdc++.h>

using namespace std;

typedef struct value
{
    int damage;
    int endurance;
    int property;
}value;

/*
血量 = 血量-max(s攻擊-護燉)
護燉--

*/

/*int cha(value w, value *s, int k)
{
    int righta = 1000000000;
    int lefta = 0;
    for(int z = 0;z<k;z++)
    {
        s[z].damage = s[z].damage + gcd(w.property, s[z].property);
        s[z].endurance = s[z].endurance + gcd(w.property, s[z].property);
        int times = floor(s[z].endurance/w.damage)
        int round = 
    }
}*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    value w[100005];
    value s[505];
    for(int r = 0;r<n;r++)
    {
        cin>>w[r].damage;
    }
    for(int r = 0;r<n;r++)
    {
        cin>>w[r].endurance;
    }
    for(int r = 0;r<n;r++)
    {
        cin>>w[r].property;
    }
    for(int r = 0;r<k;r++)
    {
        cin>>s[r].damage;
    }
    for(int r = 0;r<k;r++)
    {
        cin>>s[r].endurance;
    }
    for(int r = 0;r<k;r++)
    {
        cin>>s[r].property;
    }
    int a[100005] = {0};
    int mina = 1000000000;
    if(k == 1)
    {
        for(int r = 0;r<n;r++)
        {
            int times = floor(s[0].endurance/w[r].damage);
            //a[r] = ceil(s[0].damage+((times-1)*times/2-(w[r].endurance-1))/times);
            
            if(mina>ceil(s[0].damage+((times-1)*times/2-(w[r].endurance-1))/times))
            {
                mina = ceil(s[0].damage+((times-1)*times/2-(w[r].endurance-1))/times);
            }
            //mina = min(mina, ceil(s[0].damage+((times-1)*times/2-(w[r].endurance-1))/times));
        }
        cout<<mina<<"\n";
        return 0;
    }
    if(n == 1)
    {
        for(int r = 0;r<k;r++)
        {
            int times = floor(s[0].endurance/w[r].damage);
            //a[r] = ceil(s[0].damage+((times-1)*times/2-(w[r].endurance-1))/times);
            
            
            a[r] = ceil(s[0].damage+((times-1)*times/2-(w[r].endurance-1))/times);
            
            //mina = min(mina, ceil(s[0].damage+((times-1)*times/2-(w[r].endurance-1))/times));
        }
        int adda = 0;
        for(int r = 0;r<k;r++)
        {
            adda += a[r]; 
        }
        cout<<adda<<"\n";
        return 0;
    }
    //for(int )
    return 0;
}