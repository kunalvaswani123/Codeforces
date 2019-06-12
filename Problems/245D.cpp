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
const ll L=1e2+5;
ll b[L][L]; 
ll arr[L];
vector<ll> bit2(ll x)
{
	vector<ll>send;
	while(x>0)
	{
		send.pb(x%2);
		x/=2;
	}
	return send;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,k,n;
 	cin>>n;
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 			cin>>b[i][j];
 	}
 	for(i=0;i<n;i++)
 	{
 		set<ll>s;
 		for(j=0;j<n;j++)
 		{
	 		if(i!=j)
	 		{
		 		vector<ll>ch=bit2(b[i][j]);
		 		for(k=0;k<ch.size();k++)
		 		{
		 			if(ch[k]==1)
		 				s.insert(k);			
		 		}
	 		}
 		}
 		set<ll>::iterator it;
 		for(it=s.begin();it!=s.end();it++)
 		{
 			arr[i]+=pow(2,*it);
 		}
 	}
 	for(i=0;i<n;i++)
 		cout<<arr[i]<<' ';
 	cout<<endl;
	return 0;
}