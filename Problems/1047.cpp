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
const int L=20000000;
int lp[L];
int c[L];
int ans=0;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,j,n;
    for(i=1;i<L;i++)
    	lp[i]=i;	
    for(i=2;i<L;i++)
    {
    	if(lp[i]==i)
    	{
    		for(j=i;j<L;j+=i)
    			lp[j]=i;
    	}
    }
    cin>>n;
    int arr[n+2];
    for(i=0;i<n;i++)
    	cin>>arr[i];
 //    int f=0;
	// for(i=1;i<n;i++)
	// {
	// 	if(arr[i]!=arr[i-1])	
	// 		f=1;
	// }    
	// if(f==0)
	// {
	// 	cout<<-1<<endl;
	// 	return 0;
	// }
	int gcd=arr[0];
	for(i=1;i<n;i++)
		gcd=__gcd(gcd,arr[i]);
	for(i=0;i<n;i++)
		arr[i]/=gcd;
	for(i=0;i<n;i++)
	{
		int temp=arr[i];
		while(temp!=1)
		{
			int lpp=lp[temp];
			c[lpp]++;
			ans=max(c[lpp],ans);
			while(temp%lpp==0)
				temp/=lpp;
		}
	}
	if(ans==0)
		cout<<-1<<endl;
	else
		cout<<n-ans<<endl;
	return 0;
}