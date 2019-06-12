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
const ll L=1e3+5;
ll dp[L][L];
ll n;
ll arr[L];
void rec(ll i,ll j)
{
	if(dp[i][j]!=0)
		return;
	if(n%2==1&&j==n+1)
	{
		dp[i][j]=arr[i];
		return;
	}
	else if(n%2==0&&j==n)
	{
		dp[i][j]=max(arr[i],arr[j]);
		return;
	}
	ll ch=INT_MAX;
	rec(j+1,j+2);
	if(max(arr[i],arr[j])+dp[j+1][j+2] < ch)
		ch=max(arr[i],arr[j])+dp[j+1][j+2];
	rec(j,j+2);
	if(max(arr[i],arr[j+1])+dp[j][j+2] < ch)
		ch=max(arr[i],arr[j+1])+dp[j][j+2];
	rec(i,j+2);
	if(max(arr[j],arr[j+1])+dp[i][j+2] < ch)
		ch=max(arr[j],arr[j+1])+dp[i][j+2];
	dp[i][j]=ch;
}
void printans(ll i,ll j)
{
	if(n%2==1&&j==n+1)
	{
		cout<<i<<endl;
		return;
	}
	else if(n%2==0&&j==n)
	{
		cout<<i<<' '<<j<<endl;
		return;
	}
	ll ch=INT_MAX;
	ll v1,v2;
	ll c1,c2;
	if(max(arr[i],arr[j])+dp[j+1][j+2] < ch)
	{
		ch=max(arr[i],arr[j])+dp[j+1][j+2];
		v1=i,v2=j;
		c1=j+1,c2=j+2;
	}
	if(max(arr[i],arr[j+1])+dp[j][j+2] < ch)
	{
		ch=max(arr[i],arr[j+1])+dp[j][j+2];
		v1=i,v2=j+1;
		c1=j,c2=j+2;
	}
	if(max(arr[j],arr[j+1])+dp[i][j+2] < ch)
	{
		ch=max(arr[j],arr[j+1])+dp[i][j+2];
		v1=j,v2=j+1;
		c1=i,c2=j+2;
	}
	cout<<v1<<' '<<v2<<endl;	
	printans(c1,c2);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	rec(1,2);
	cout<<dp[1][2]<<endl;
	printans(1,2);
	return 0;
}