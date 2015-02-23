
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

string parse(char s[], int start, int end, int n)
{
	char c = s[start];
	char tmp[100];
	strcpy(tmp, s);
	for(int i=start; i<n; i++)
		tmp[i] = tmp[i+1];
	for(int j=n; j>end; j--)
		tmp[j] = tmp[j-1];
	tmp[end] = c;
	return string(tmp);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		SI(n);
		char s[100];
		scanf("%s", s);
		string best(s);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			{
				string tmp = parse(s, i, j, n);
	//			cout<<tmp<<"----"<<endl;
				best = min(best, tmp);
			}
		cout<<best<<endl;
	}
	return 0;
}
