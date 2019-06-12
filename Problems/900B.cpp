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
 	ll a,b,c;
 	cin>>a>>b>>c;
 	ll temp1=a;
 	ll temp2;
 	ll count=0;
 	ll ch=1e5+5;
 	while(ch--)
 	{
 		count++;
 		temp1=a*10;
 		a=temp1%b;
 		if(temp1/b==c)
 		{
 			cout<<count<<endl;
 			return 0;
 		}
 	}   
 	cout<<-1<<endl;
	return 0;
}
