
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

int p[40000] = {0};
vector<int> ps;

int main()
{
	p[0] = p[1] = 1;
	for(int i=2; i<40000; i++)
		if(!p[i])
		{
			ps.pb(i);
			for(int j=i; j<40000; j+=i)
				p[j] = 1;
		}
	int T;
	scanf("%d", &T);
	while(T--)
	{
		LL n;
		cin>>n;
		vector<pair<int, int> > a;
		int last = sqrt(n);
		for(int i=0; ps[i]<=last && n!=1; i++)
			if(n%ps[i]==0)
			{
				int cnt = 0;
				while(n%ps[i]==0)
				{
					cnt++;
					n /= ps[i];
				}
				a.pb(mp(ps[i], cnt));
			}
		if(n!=1)
			a.pb(mp(n, 1));
		LL ans = 1;
		EACH(it, a)
		{
			LL tmp = 1;
			for(int i=1; i<=it->s; i++)
				tmp += pow(it->f, i);
			ans *= tmp;
		}
		cout<<ans<<endl;
	}
	return 0;
}
