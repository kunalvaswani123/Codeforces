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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll x;
 	cin>>x;
 	ll i=1,j=1;
 	for(i=1;i<=x;i++)
 	{
 		for(j=1;j<=x;j++)
 		{
 			if(i*j>x&&i%j==0&&i/j<x)
 			{
 				cout<<i<<' '<<j<<endl;
 				return 0;
 			}

 		}
 	}   
 	cout<<-1<<endl;
	return 0;
}