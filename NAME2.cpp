#include <iostream>
#include <string>
using namespace std;
 
string M,W;
int lenM,lenW;
int func();
int eqcheck();
int Msmall();
int Wsmall();
int main()
{
	int T;
	cin>>T;
    int i=0;
	int res;
	while(i<T)
	{
		cin>>M;
		cin>>W;
		res=func();
		if(res){cout<<"YES";}
		else{cout<<"NO";}
		cout<<"\n";
		i++;
	}
	return(0);
}
 
int func()
{
	lenM=M.length();
	lenW=W.length();
 
	if(lenM==lenW)
	{
		return(eqcheck());
	}
	if(lenM<lenW)
	{
		return(Msmall());
	}
	if(lenM>lenW)
	{
		return(Wsmall());
	}
}
int eqcheck()
{
	int i;
	for(i=0;i<lenW;i++)
	{
		if(M[i]!=W[i]){return(0);}
	}
	return(1);
}
int Msmall()
{
	int i;
	int chk=0;
	char chkdis=M[chk];
	for(i=0;i<lenW;i++)
	{
		if(W[i]==chkdis)
		{
			chk++;
			if(chk<lenM){chkdis=M[chk];}
			else{return(1);}
		}
	}
	return(0);
}
int Wsmall()
{
	int i;
	int chk=0;
	char chkdis=W[chk];
	for(i=0;i<lenM;i++)
	{
		if(M[i]==chkdis)
		{
			chk++;
			if(chk<lenW){chkdis=W[chk];}
			else{return(1);}
		}
	}
	return(0);
} 