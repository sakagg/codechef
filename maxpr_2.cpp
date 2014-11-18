#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

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

LL expo(LL a, LL b)
{
	LL ans = 1;
	while(b)
	{
		if(b&1)
			ans = (ans*a)%mod;
		b>>=1;
		a = (a*a)%mod;
	}
	return ans;
}

int main()
{
	int T;
	int a[200200];
	LL sum;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		sum = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", a+i);
		for(int d=-100; d<=100; d++)	//TODO: fix this to -100 -> 100
		{
			vector<LL> count(110, 0);
			for(int i=0; i<n; i++)
			{
				if(a[i]-d>=1 && a[i]+d<=100)
				{
					count[a[i]] += count[a[i]-d];
					count[a[i]] %= mod;
				}
				count[a[i]]++;
//				printf("%d %d %d\n", d, a[i], count[a[i]]);
			}
			for(int i=1; i<=100; i++)
				sum = (sum + count[i])%mod;
			sum = (sum-n)%mod;
//			print_array_v(count);
		}
		sum += n;
		LL ans = (expo(2, n) - 1 - sum) % mod;
		if(ans < 0)
			ans += mod;
		printf("%lld\n", ans);
	}
	return 0;
}

