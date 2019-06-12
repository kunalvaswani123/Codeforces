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
 	string t;
 	cin>>t;
 	ll p1=0,p2=t.size()-1;
 	ll check;
 	if(t.size()%2==0)
 		check=p2;
 	else
 		check=p1;
	vector<char>news;
	ll count=0;
	while(p1<=p2)
	{
		if(check==p2)
		{
			news.pb(t[check]);
			p2--,check=p1;
		}
		else
		{
			news.pb(t[check]);
			p1++,check=p2;	
		}
	}
	ll i;
	reverse(news.begin(),news.end());
	for(i=0;i<news.size();i++)
		cout<<news[i];
	cout<<endl;
	return 0;
}