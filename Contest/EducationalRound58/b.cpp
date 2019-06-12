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
 	ll i,j;
 	ll len=0;
 	vector<char>as;
 	for(i=0;i<s.size();i++)
 	{
 		if(s[i]=='['||s[i]==']'||s[i]==':'||s[i]=='|')
 			as.pb(s[i]);
 	}
 	ll p1=0,p2=0;
 	for(i=0;i<as.size();i++)
 	{
 		if(as[i]=='[')
 		{
 			for(j=i+1;j<s.size();j++)
 			{
 				if(as[j]==':')
 				{
 					p1=j;
		 			break;
 				}
 			}
	 		break;
 		}
 	}   
 	for(i=as.size()-1;i>=0;i--)
 	{
 		if(as[i]==']')
 		{
 			for(j=i-1;j>=0;j--)
 			{
 				if(as[j]==':')
 				{
 					p2=j;
 					break;
 				}
 			}
 			break;
 		}
 	}
 	if(p1>=p2)
 	{
 		cout<<-1<<endl;
 		return 0;
 	}
 	ll count=0;
 	for(i=p1+1;i<p2;i++)
 	{
 		if(as[i]=='|')
 			count++;
 	}
 	cout<<4+count<<endl;
	return 0;
}