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
 	string s;
 	cin>>s;
 	ll i,k;
 	cin>>k;
 	ll n=s.size();
 	ll c1=0,c2=0;
 	for(i=0;i<n;i++)
 	{
 		if(s[i]=='?')
 			c1++;
 		else if(s[i]=='*')
 			c2++;
 	}
 	ll minl=n-2*(c1+c2);
 	if(k<minl)
 	{
 		cout<<"Impossible"<<endl;
 		return 0;
 	}
 	ll maxl=n-(c1+c2);
 	if(k>maxl&&c2==0)
 	{
 		cout<<"Impossible"<<endl;
 		return 0;
 	}
 	ll count=k-minl;
 	for(i=0;i<n;i++)
 	{
 		if(s[i]=='?'||s[i]=='*')
 			continue;
 		if(s[i+1]!='?'&&s[i+1]!='*')
 			cout<<s[i];
 		else if(s[i+1]=='?')
 		{
 			if(count>0)
 			{
	 			cout<<s[i];
	 			count--;
 			}
 		}
 		else if(s[i+1]=='*')
 		{
 			while(count>0)
 			{
 				cout<<s[i];
 				count--;
 			}
 		}
 	}
 	cout<<endl;
	return 0;
}