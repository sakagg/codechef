
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

int last;

void print_next(pair<int, char> a[])
{
	last++;
	if(last == 26 || a[last].f == 0)
		last = 1;
	printf("%c", a[last].s);
	a[last].f--;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		char s[100100];
		pair<int, char> a[26];
		memset(a, 0, sizeof(a));
		int n = 0;
		scanf("%s", s);
		for(int i=0; s[i]; i++)
			a[s[i]-'a'].f++;
		for(int i=0; i<26; i++)
		{
			a[i].s = i+'a';
			n += a[i].f;
		}
		sort(a, a+26, greater< pair<int, char> >());
		if(a[0].f > (n+1)/2)
		{
			printf("-1\n");
			continue;
		}
		int diff = n - a[0].f;
		last = 0;
		while(diff >= a[0].f)
		{
			print_next(a);
			diff--;
		}
		printf("%c", a[0].s);
		a[0].f--;
		while(a[0].f)
		{
			print_next(a);
			printf("%c", a[0].s);
			a[0].f--;
		}
		cout<<endl;
	}
	return 0;
}
