
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

LL type1(vector<int> &boys, vector<int> &girls)
{
	assert(boys.size() == girls.size());
	LL ans = 0;
	int sz = boys.size();
	for(int i=0; i<sz; i++)
		ans += abs(boys[i]-girls[i]);
	return ans;
}

LL type2(vector<int> &boys, vector<int> &girls)
{
	LL ans = type1(boys, girls);
	return ans;
}

char a[100100];
vector<int> boys, girls;
vector<int> b1, g1;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int type;
		SI(type);
		scanf("%s", a);
		int cnt1=0, cnt2=0;
		for(int i=0; a[i]; i++)
			if(a[i]=='B')
				cnt1++;
			else if(a[i] == 'G')
				cnt2++;
		if(abs(cnt1-cnt2) > 1)
		{
			printf("-1\n");
			continue;
		}
		int n = cnt1 + cnt2;
		if(type == 0)
		{
			int wrong = 0;
			for(int i=0; i<n; i+=2)
				if(a[i]=='B')
					wrong++;
			if(cnt1 == cnt2)
				printf("%d\n", min(wrong, cnt1-wrong));
			else if(cnt1 > cnt2)
				printf("%d\n", cnt1-wrong);
			else
				printf("%d\n", wrong);
		}
		else
		{
			if(cnt1!=cnt2)
			{
				char ch = cnt1 > cnt2 ? 'B' : 'G';
				boys.clear(); girls.clear();
				for(int i=0; a[i]; i++, ch = 'B'+'G'-ch)
				{
					if(a[i]!=ch)
					{
						if(a[i]=='B')
							boys.pb(i);
						else
							girls.pb(i);
					}
				}
				if(type == 1)
					printf("%lld\n", type1(boys, girls));
				else
					printf("%lld\n", type2(boys, girls));
			}
			else
			{
				boys.clear(); girls.clear(); b1.clear(); g1.clear();
				for(int i=0; a[i]; i++)
				{
					if(i%2 == 0)
					{
						if(a[i]=='G')
							girls.pb(i);
						else
							b1.pb(i);
					}
					else
					{
						if(a[i]=='G')
							g1.pb(i);
						else
							boys.pb(i);
					}
				}
				if(type == 1)
					printf("%lld\n", min(type1(boys, girls), type1(b1, g1)));
				else
					printf("%lld\n", min(type2(boys, girls), type2(b1, g1)));
			}
		}
	}
	return 0;
}
