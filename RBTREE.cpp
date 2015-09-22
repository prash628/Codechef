#include<iostream>
#include<string>
#include <cstdio>
#include <algorithm>
#include<unordered_map>

using namespace std;



int N;
string queryType;//i,b,r
int query;//black=0,red=1,i=2

int root=0;//0 for black, 1 for red


long long x,y;

int colorX,colorY;
int isAncestor()
{
	if(x==y){return(1);}
	for(long long i=y;i>x;)
	{
		if(i==x)
		{return(1);}
		i=i/2;
	}
	return(0);

}


int findColor(long long x)
{
	int color=root;

	for(int i=2;i<=x;)
	{
		color=(color+1)%2;
		i*=2;
	}
	return(color);
}


long long findCommonRoot()
{
	unordered_map<long long,int> hashmap;


	for(int i=y;i>=1;)
	{
		hashmap[i]=1;

		i=i/2;
	}


	long long mostRecent=1;
	for(int i=x;i>=1;)
	{
		unordered_map<long long,int>::const_iterator got = hashmap.find (i);
		if (got == hashmap.end() )
		{

		}
		else
		{
			mostRecent=i;
			return(i);
		}



		i=i/2;
	}

	return(mostRecent);





}

long long compute()
{
	int ancestorQ=isAncestor();

	colorX=findColor(x);
	colorY=findColor(y);



	if(ancestorQ==1)
	{
		if(query==0)
		{
			long long numberBlack=0;
			if(x==y)
			{
				if(colorX==0){return(1);}
				else{return(0);}
			}
			int color=colorY;
			for(int i=y;i>x;)
			{
				if(color==0)
				{
					numberBlack++;
				}
				color=(color+1)%2;
				i=i/2;
			}
			return(numberBlack);
		}
		else
		{
			if(x==y)
			{
				if(colorX==1){return(1);}
				else{return(0);}
			}
			long long numberRed=0;
			int color=colorY;
			for(int i=y;i>x;)
			{
				if(color==1)
				{
					numberRed++;
				}
				color=(color+1)%2;
				i=i/2;
			}
			return(numberRed);
		}
	}
	else
	{
		long long commonRoot=findCommonRoot();
		 int rootColor=findColor(commonRoot);
		if(query==0)
		{
			long long numberBlack=0;



			int color=colorY;
			for(int i=y;i>=commonRoot;)
			{
				if(color==0)
				{
					numberBlack++;
				}
				color=(color+1)%2;
				i=i/2;
			}

			 color=colorX;
			for(int i=x;i>=commonRoot;)
			{
				if(color==0)
				{
					numberBlack++;
				}
				color=(color+1)%2;
				i=i/2;
			}

			if(rootColor==0){numberBlack--;}



			return(numberBlack);
		}
		else
		{

			long long numberRed=0;
			int color=colorY;
			for(int i=y;i>=commonRoot;)
			{
				if(color==1)
				{
					numberRed++;
				}
				color=(color+1)%2;
				i=i/2;
			}

		   color=colorX;
			for(int i=x;i>=commonRoot;)
			{
				if(color==1)
				{
					numberRed++;
				}
				color=(color+1)%2;
				i=i/2;
			}

				if(rootColor==1){numberRed--;}
			 	return(numberRed);
		}


	}
}

int main()
{

	int T;
	cin>>T;
	int i;

	for(i=0;i<T;i++)
	{
		cin>>queryType;


		if(queryType[1]=='i')
		{
			query=2;
		}
		if(queryType[1]=='b')
		{
			query=0;
		}

		if(queryType[1]=='r')
		{
			query=1;
		}

		if(query==2)
		{
			root=(1+root)%2;
		}
		else
		{
			long long temp1,temp2;
			cin>>x;
			cin>>y;

			if(x<y)
			{
			}
			else
			{
				temp1=x;temp2=y;
				x=temp2;y=temp1;
			}
			long long res=compute();
			cout<<res<<"\n";



		}





	}
	return(0);
}

