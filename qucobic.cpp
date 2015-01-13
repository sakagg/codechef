
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
		int s;
		char a[10];
		scanf("%s", a);
		SI(s);
		if(s!=0)
			s = (s-1)/60 + 1;
		s%=(24*60);
		int h = (a[0] - '0')*10 + a[1] - '0';
		int m = (a[2] - '0')*10 + a[3] - '0';
		m += s;
		h += m/60;
		m %= 60;
		h %= 24;
		if(h/10 == 0)
			printf("0");
		printf("%d", h);
		if(m/10 == 0)
			printf("0");
		printf("%d\n", m);
	}
	return 0;
}
