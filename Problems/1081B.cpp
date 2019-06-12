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
const ll L=1e5+5;
ll fans[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll i,j,n,x;
	cin>>n;
	vector<pll>arr;
	for(i=0;i<n;i++)
	{
		cin>>x;
		arr.pb(mp(x,i));
	}
	sort(arr.begin(),arr.end());
	ll st=1;
	ll flag=0;
	ll temp;
	for(i=0;i<n;i++)
	{
		temp=n-arr[i].fi;
		if(i+temp>n)
		{
			flag=1;
			break;
		}
		for(j=i;j<temp+i;j++)
		{
			fans[arr[j].se]=st;
			if(arr[j].fi!=arr[i].fi)
				flag=1;
		}
		st++;
		i+=(temp-1);
	}
	if(flag==1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	cout<<"Possible"<<endl;
	for(i=0;i<n;i++)
		cout<<fans[i]<<' ';
	cout<<endl;
	return 0;
}