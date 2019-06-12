#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll L=1e6;
ll arr[L];
int main()
{
	ll n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	ll curcount=1;
	ll maxcount=1;
	for(i=0;i<n-1;i++)
	{
		if(arr[i+1]<=2*arr[i])
			curcount++;
		else
			curcount=1;
		if(curcount>maxcount)
			maxcount=curcount;
	}
	cout<<maxcount<<endl;
	return 0;
}