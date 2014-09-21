#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
// Uncomment to use TestCases
	int T;
	char a[100100];
	long long ans;
	scanf("%d", &T);
	while(T--)
	{
		ans = 1;
		scanf("%s", a);
		for(int i=0; a[i]; i++)
		{
			ans *= 2;
			if(i&1)
			{
				if(a[i]=='l')
					ans--;
				else
					ans++;
			}
			else
			{
				if(a[i] == 'r')
					ans+=2;
			}
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}

