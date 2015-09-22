
#include<iostream>
#include<string>
using namespace std;



int N;
 unsigned long long result;


int main()
{

	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		cin>>N;
		result=0;
		result=(unsigned long long)N*N;
			result+=(unsigned long long)3*N;
				result=(unsigned long long)result/2;

		cout<<result<<"\n";

	}
	return(0);
}

