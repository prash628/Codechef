
#include<iostream>
#include<string>
using namespace std;



int N;
string paran;
int lens;


int func()
{
	int bal=0,max_bal=0;
	for(int i=0;i<paran.length();i++)
	{
		char chx=paran[i];
		int chk=(int)chx;


		int chk1=(int)'(';
		int chk2=(int)')';
		if(chk==chk1)
		{

			bal+=1;
		}
		if(chk==chk2)
		{
			bal-=1;
		}
		if(bal>max_bal){max_bal=bal;}

	}
	return(max_bal);
}


int main()
{

	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		cin>>paran;
		lens=func();

		string op="";
		for(int x=0;x<lens;x++)
		{
			op=op+"(";
		}
		for(int x=0;x<lens;x++)
		{
			op=op+")";
		}


		cout<<op<<"\n";

	}
	return(0);
}
