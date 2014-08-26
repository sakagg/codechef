#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int t;
	int count;
	int left;
	char ch;
	cin>>t;
	getchar();
	while(t--)
	{
		count = 0;
		left = 0;
		while(1)
		{
			scanf("%c", &ch);
			if(ch == '<')
				left++;
			else if(ch == '>' && left>0)
			{
				left--;
				count+=2;
			}
			else
			{
				while(ch!='\n')
					ch = getchar();
				break;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}

