
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;
typedef pair<char, LL> P;

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

int isopening(char c)
{
	if(c=='{' || c=='[' || c=='(' || c=='<')
		return 1;
	return 0;
}

int getInt(char c)
{
	if(c=='{' || c == '}')
		return 1;
	else if(c=='[' || c==']')
		return 2;
	else if(c=='(' || c==')')
		return 3;
	else if(c=='<' || c=='>')
		return 4;

	return -1;
}

LL st[100100];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		SI(n);
		memset(st, 0, (n+5)*sizeof(LL));
		char a[n];
		int b[n];
		LL mx = 0;
		scanf("%s", a);
		for(int i=0; i<n; i++)
			SI(b[i]);
		stack<P> s;
		int depth = -1;
		for(int i=0; a[i]; i++)
		{
			if(isopening(a[i]))
			{
				depth++;
				st[depth+1] = 0;
				s.push(mp(a[i], b[i]));
			}
			else if(s.empty())
			{
				depth = -1;
				st[0] = 0;
			}
			else
			{
				P c = s.top(); s.pop();
				if(getInt(c.f) == getInt(a[i]))
				{
					st[depth] += c.s + b[i] + st[depth+1];
					mx = max(mx, st[depth]);
					depth--;
					if(depth == -1 && st[0] < 0)
						st[0] = 0;
				}
				else
				{
					while(!s.empty())
						s.pop();
					depth = -1;
					st[0] = 0;
				}
			}
		}
		printf("%lld\n", mx);
	}
	return 0;
}
