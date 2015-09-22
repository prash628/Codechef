#include<iostream>
#include<string>
using namespace std;



int N;



int main()
{

	int T;
	string x;
	int A[26];
	int res;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{

		for(int j=0;j<26;j++)
		{
			A[j]=0;
		}
		cin>>x;
		res=0;

		int sz=x.length();
		for(int j=0;j<sz;j++)
		{
			int chx=x[j]-97;
			if(A[chx]==0)
			{
				A[chx]++;
				res++;
			}
		}

		cout<<res<<"\n";

	}
	return(0);
}
