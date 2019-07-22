#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,h,a,b,k;
	cin>>n>>h>>a>>b>>k;
	while(k--)
	{
		ll ta,fa,tb,fb;
		cin>>ta>>fa>>tb>>fb;
		ll ans=0;
		if(fa<a&&fb<a&&ta!=tb)
			ans=abs(ta-tb)+abs(fa-a)+abs(fb-a);
		else if(fa>b&&fb>b&&ta!=tb)
			ans=abs(ta-tb)+abs(fa-b)+abs(fb-b);
		else
			ans=abs(ta-tb)+abs(fa-fb);
		cout<<ans<<endl;
	}
	return 0;
}