
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int s, c, k;
		SI(s); SI(c); SI(k);
		LL ans = 0;
		if(s==0 && c==0)
			ans = 0;
		else if(k==1)
		{
			if(s!=0)
				ans = (1LL<<s) + 1;
			for(int i=max(s, 1); i<=c; i++)
				ans += 1LL<<i;
		}
		else
		{
			int cnt = 1;
			for(int i=s; i>0; i--, cnt++)
			{
				if((cnt + (i!=1 && c>=i-1)) >= k)
				{
					ans = (1LL<<i) + 1;
					break;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
