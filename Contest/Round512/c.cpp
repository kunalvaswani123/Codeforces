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
ll dp[103][103];
ll ans=0;
ll sum[1000];
ll arr[1000];
ll checkdp(ll i,ll j,ll whs)
{
	if(i==j)
	{
		dp[i][i]=arr[i];
		return arr[i];
	}
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll k;
	ll sum=0;
	for(k=i;k<j;k++)
	{
		sum+=arr[k];
		dp[i][k]=sum;
		dp[k+1][j]=checkdp(k+1,j,sum);
		if(whs!=-1)
		{
			if(sum==whs&&whs==dp[k+1][j])
			{
				ans=1;
			}
		}
		else
		{
			if(sum==dp[k+1][j])
			{
				ans=1;	
			}
		}
		if(dp[i][j]!=-1)
			dp[i][j]+=dp[k+1][j]+dp[i][k];
		else
			dp[i][j]=dp[k+1][j]+dp[i][k];
	}
	return dp[i][j];
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,i,j;
 	cin>>n;
 	string s;
 	cin>>s;
 	for(i=0;i<n;i++)
 	{
 		arr[i]=s[i]-'0';
 	}
 	for(i=0;i<100;i++)
 	{
 		for(j=0;j<100;j++)
 			dp[i][j]=-1;
 	}
 	checkdp(0,n-1,-1);
	if(ans==1)
		cout<<"YES"<<endl;
	else
	 	cout<<"NO"<<endl;
	return 0;
}