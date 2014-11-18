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

int ps[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};

LL fastPow(LL a, LL b, LL m=(1<<30))
{
	LL ans = 1;
	while(b)
	{
		if(b&1)
			ans = (ans*a)%m;
		a = (a*a)%m;
		b >>= 1;
	}
	return ans;
}

LL totient(LL m)
{
	LL result = m;
	for(LL i=2; i*i <= m; i++)
	{
		if(m%i == 0)
			result -= result/i;
		while(m%i == 0)
			m /= i;
	}
	if(m > 1)
		result -= result/m;
	return result;
}

int main()
{	
	int T;
	int psize = sizeof(ps)/sizeof(ps[0]);
	scanf("%d", &T);
	LL ans[100100];
	LL nr[10];
	nr[1] = 1;
	for(int i=2; i<=7; i++)
		nr[i] = nr[i-1]*fastPow(i, i);
	int factors[510][100] = {0};
	for(int i=2; i<510; i++)
	{
		int tmp = i;
		for(int j=0; j<psize; j++)
		{
			factors[i][j] = factors[i-1][j];
			while(tmp%ps[j] == 0)
			{
				tmp /= ps[j];
				factors[i][j] += i;
			}
		}
	}
	while(T--)
	{
		LL n, m, q, r;
		scanf("%lld %lld %lld", &n, &m, &q);
		if(n <= 7)
		{
			for(int i=0; i<q; i++)
			{
				scanf("%lld", &r);
				r = min(r, n-r);
				printf("%lld\n", ((nr[n]/nr[n-r])/nr[r])%m);
			}
			continue;
		}
		if(n <= 500)
		{
			for(int i=0; i<q; i++)
			{
				scanf("%lld", &r);
				LL ans = 1;
				for(int i=0; i<psize; i++)
				{
					int times = factors[n][i] - factors[n-r][i] - factors[r][i];
//					printf("%d ", times);
					if(times>0)
					{
						ans *= fastPow(ps[i], times, m);
						ans %= m;
					}
				}
				printf("%lld\n", ans);
			}
			continue;
		}
		LL tot = totient(m)-1;
		vector<int> rs(q);
		LL mxr=0;
		for(int i=0; i<q; i++)
		{
			scanf("%lld", &r);
			r = min(r, n-r);
			rs[i] = r;
			mxr = max(mxr, r);
		}
		ans[1] = fastPow(n, n, m);
		for(int i=2; i<=mxr; i++)
			ans[i] = (((ans[i-1]*fastPow(n+1-i, n+1-i, m))%m) * fastPow(fastPow(i, tot, m), i, m))%m;
		for(int i=0; i<q; i++)
			printf("%lld\n", ans[rs[i]]);
	}
	return 0;
}

