
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
	char s[100100];
	int last[100100];
	LL pre[100100];
	while(T--)
	{
		int n, k, q;
		SI(n); SI(k); SI(q);
		scanf("%s", s);
		int cnt[2] = {0};
		int end = 0;
		pre[0] = 0;
		for(int i=0; i<n; i++)
		{
			while(end < n && cnt[s[end] - '0'] < k)
				cnt[s[end++] - '0']++;
			last[i] = end;
			pre[i+1] = pre[i] + end-i;
			cnt[s[i] - '0']--;
		}
		//print_array(last, n);
		//print_array(pre, n+1);
		while(q--)
		{
			int l, r;
			SI(l); SI(r);
			l--;
			int ind = lower_bound(last+l, last+r, r) - last;
			LL ans = pre[ind] - pre[l];
			r -= ind;
			ans += (LL(r+1)*r)/2;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
