#include<iostream>
#include<string>
using namespace std;



int N;

 unsigned long long R,G,B;

 int M;

int main()
{

	int T;
	cin>>T;
	int i;
	int r,g,b;
	for(i=0;i<T;i++)
	{
		cin>>r;
		cin>>g;
		cin>>b;
		cin>>M;

		unsigned long long maxR;
		unsigned long long maxG;
		unsigned long long maxB;


		int fresh;

		fresh=0;
		for(int x=0;x<r;x++)
		{
			cin>>R;
			if(fresh==0){fresh=1;maxR=R;}
			else{if(R>maxR){maxR=R;}}
		}

		fresh=0;
		for(int x=0;x<g;x++)
		{
			cin>>G;
			if(fresh==0){fresh=1;maxG=G;}
			else{if(G>maxG){maxG=G;}}
		}

		fresh=0;
		for(int x=0;x<b;x++)
		{
			cin>>B;
			if(fresh==0){fresh=1;maxB=B;}
			else{if(B>maxB){maxB=B;}}
		}


		for(int x=0;x<M;x++)
		{
			if(maxR>=maxG && maxR>=maxB)
			{
				maxR=maxR/2;
			}
			else
			{
				if(maxG>=maxB)
				{
					maxG=maxG/2;
				}
				else
				{
					maxB=maxB/2;
				}

			}
		}


		if(maxR>=maxG && maxR>=maxB)
			{
				cout<<maxR<<"\n";
			}
			else
			{
				if(maxG>=maxB)
				{
					cout<<maxG<<"\n";
				}
				else
				{
					cout<<maxB<<"\n";
				}

			}


	}
	return(0);
}


