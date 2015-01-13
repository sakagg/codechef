#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define mp make_pair
#define pb push_back
#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define f first
#define s second

template<class T> void print_v(vector<T> &v)
{
	for(int i=0; i<v.size(); i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

LL getval(vector<LL> &c1, vector<LL> &c2, pair<int, int> ind)
{
	if(ind.f >= ((int)c1.size()) || ind.s >= ((int)c2.size()))
		return 0;
	LL ans = 0;
	if(ind.f != -1)
		ans += c1[ind.f];
	if(ind.s != -1)
		ans += c2[ind.s];
	return ans;
}

int main()
{
	int n, w;
	LL c;
	SI(n);
	vector<LL> c1, c2;
	for(int i=0; i<n; i++)
	{
		SI(w); SLL(c);
		if(w == 1)
			c1.pb(c);
		else
			c2.pb(c);
	}
	sort(c1.rbegin(), c1.rend());
	sort(c2.rbegin(), c2.rend());
	for(int i=1; i < c1.size(); i++)
		c1[i] += c1[i-1];
	for(int i=1; i < c2.size(); i++)
		c2[i] += c2[i-1];
	int mxwt = c1.size() + 2*c2.size();
	vector< pair<int, int> > iters(mxwt + 1);
	iters[0] = mp(-1, -1);
	iters[1] = mp(0, -1);
	for(int i=2; i<=mxwt; i++)
	{
		pair<int, int> s1 = iters[i-2];
		s1.s += 1;
		pair<int, int> s2 = iters[i-1];
		s2.f += 1;
		if(getval(c1, c2, s1) >= getval(c1, c2, s2))
			iters[i] = s1;
		else
			iters[i] = s2;
		if(getval(c1, c2, iters[i-1]) > getval(c1, c2, iters[i]))
			iters[i] = iters[i-1];
	}
	for(int i=1; i<=mxwt; i++)
		printf("%lld ", getval(c1, c2, iters[i]));
//	printf("\n");
	return 0;
}
