#include<iostream>
#include<string>
using namespace std;



int N;

int apples[100002];


int main()
{

	int T;
	cin>>T;
	int i,ele;
	int res;

	for(i=0;i<T;i++)
	{
		cin>>N;
		res=0;

		for(int x=0;x<100002;x++)
		{
			apples[x]=0;
		}
		for(int x=0;x<N;x++)
		{
			cin>>ele;
			if(apples[ele]==0)
			{
				res++;
				apples[ele]=1;
			}

		}

		cout<<res<<"\n";

	}
	return(0);
}
