#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;



int N;

unsigned long long X,K;

int main()
{

	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		cin>>X;
		cin>>K;

		if(K==1)
		{
			double res=X/2;
			cout<<res<<"\n";
		}
		else{


			//write spl case for divisions=1 cuz 10 pow 12 into 2 ll be ...
			unsigned long long divisions;
			double partSize,sizeBefore,posChk;
			for(divisions=2;divisions<=K;)
			{
					divisions*=2;
			}


			partSize=(double)X/divisions;
			sizeBefore=(double)partSize*2;



			unsigned long long goBack=(divisions-K-1);

			posChk=X-partSize;

			posChk=posChk-(double)(goBack*sizeBefore);
   printf("%.8lf\n", posChk);


		//	cout<<posChk<<"\n";
		}

	}
	return(0);
}

