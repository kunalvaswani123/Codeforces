#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define qq queue
#define pqq priority_queue
ll power(ll x,ll y,ll p) 
{ 
    ll res=1;  
    x=x%p;
    while (y > 0) 
    { 
        if(y&1) 
            res=(res*x)%p; 
        y=y>>1;
        x=(x*x)%p;   
    } 
    return res; 
}
ll dp[1000][1000];
ll x=500,y=500;
ll f1=0,f2=0,f3=0,f4=0;
ll check()
{
    if(dp[x][y]==1)
        return 1;
    else if(dp[x+1][y]==1&&f2==0)
        return 1;
    else if(dp[x-1][y]==1&&f1==0)
        return 1;
    else if(dp[x][y+1]==1&&f3==0)
        return 1;
    else if(dp[x][y-1]==1&&f4==0)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    ll i;
    dp[x][y]=1;
    for(i=0;i<s.size();i++)
    {
    	if(s[i]=='L')
        {
    		x--;
            f2=1;
        }
        else if(s[i]=='R')
        {
            x++;
            f1=1;
        }
        else if(s[i]=='U')
        {
            y++;
            f4=1;
        }
        else if(s[i]=='D')
        {
            y--;
            f3=1;
        }
        if(check()==1)
        {
            cout<<"BUG"<<endl;
            return 0;
        }
        dp[x][y]=1;
        f1=0,f2=0,f3=0,f4=0;
    }
    cout<<"OK"<<endl;
	return 0;
}