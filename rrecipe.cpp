#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second
#define mod 10000009

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

char a[1000100];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", a);
		int len = strlen(a);
		LL ans = 1;
		for(int i=0; i<len/2; i++)
		{
			int c1 = a[i] == '?';
			int c2 = a[len-i-1] == '?';
			if(c1 && c2)
				ans *= 26;
			else if(!c1 && !c2 && a[i] != a[len-i-1])
			{
				ans = 0;
				break;
			}
			ans %= mod;
		}
		if(len%2 == 1 && a[len/2] == '?')
			ans = (ans*26) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}

