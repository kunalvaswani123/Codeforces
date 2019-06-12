#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll L=1e6;

int main()
{
	string t;
	ll n,k,i,j;
	cin>>n>>k;
	cin>>t;
	ll len=t.size();
	ll maxcount=0;
	for(i=len-1;i>0;i--)
	{
		ll temp=i;
		ll count=0;
		for(j=0;j<len;j++)
		{
			if(temp==len)
				break;
			if(t[temp]==t[j])
			{
				temp++;
				count++;
			}
			else
			{
				count=0;
				break;
			}
		}
		if(count>maxcount)
			maxcount=count;
	}
	for(i=0;i<k-1;i++)
	{
		for(j=0;j<len-maxcount;j++)
			cout<<t[j];
	}
	cout<<t<<endl;
	return 0;
}