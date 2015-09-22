#include<iostream>
#include<string>
using namespace std;



int N;

string ip;
int iplen;


int matrix[10][10];


int minusnext;
int minusresult;

int nextdp[100002][10];
int resdp[100002][10];


int findop(int pos,int vertex)
{
	//Chk for memo

	if(nextdp[pos][vertex]!=-2){return(nextdp[pos][vertex]);}
	if(pos==iplen-1)
	{
		return(1);
	}

	int res1,res2,nxt;

	int first,second;
	if(pos==-1)
	{
		if(ip[pos+1]=='A')
		{//0 or 5
			first=0;
			second=5;
		}
		if(ip[pos+1]=='B')
		{//1 or 6
			first=1;
			second=6;
		}
		if(ip[pos+1]=='C')
		{//2 or 7
			first=2;
			second=7;
		}
		if(ip[pos+1]=='D')
		{//3 or 8
			first=3;second=8;
		}
		if(ip[pos+1]=='E')
		{//4 or 9
			first=4;second=9;
		}

			res1=findop(pos+1,first);
			res2=findop(pos+1,second);
			if(res1==-1)
			{
				if(res2==-1)
				{
					nxt=-1;
				}
				else
				{
					nxt=second;
				}
			}
			else
			{
				nxt=first;
			}
			minusnext=nxt;
			minusresult=nxt;
			return(nxt);
	}


	{
		if(ip[pos+1]=='A')
		{//0 or 5
			first=0;
			second=5;
		}
		if(ip[pos+1]=='B')
		{//1 or 6
			first=1;
			second=6;
		}
		if(ip[pos+1]=='C')
		{//2 or 7
			first=2;
			second=7;
		}
		if(ip[pos+1]=='D')
		{//3 or 8
			first=3;second=8;
		}
		if(ip[pos+1]=='E')
		{//4 or 9
			first=4;second=9;
		}


		if(matrix[vertex][first]==0)
		{
			res1=-1;
		}
		else
		{
			res1=findop(pos+1,first);
		}

		if(matrix[vertex][second]==0)
		{
			res2=-1;
		}
		else
		{
			res2=findop(pos+1,second);
		}

			if(res1==-1)
			{
				if(res2==-1)
				{
					nxt=-1;
				}
				else
				{
					nxt=second;
				}
			}
			else
			{
				nxt=first;
			}
		nextdp[pos][vertex]=nxt;
		resdp[pos][vertex]=nxt;

		return(nxt);
	}


}


int main()
{

	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		cin>>ip;
		iplen=ip.length();
		for(int j=0;j<100002;j++)
		{
			for(int y=0;y<10;y++)
			{
				nextdp[j][y]=-2;
				resdp[j][y]=-2;
			}
		}
		for(int k=0;k<10;k++)
		{
			for(int p=0;p<10;p++)
			{
				matrix[k][p]=0;
			}
		}

		matrix[0][1]=1;
		matrix[0][4]=1;
		matrix[0][5]=1;

		matrix[1][0]=1;
		matrix[1][2]=1;
		matrix[1][6]=1;

		matrix[2][3]=1;
		matrix[2][7]=1;
		matrix[2][1]=1;

		matrix[3][4]=1;
		matrix[3][2]=1;
		matrix[3][8]=1;

		matrix[4][0]=1;
		matrix[4][9]=1;
		matrix[4][3]=1;

		matrix[5][0]=1;
		matrix[5][8]=1;
		matrix[5][7]=1;

		matrix[6][9]=1;
		matrix[6][8]=1;
		matrix[6][1]=1;

		matrix[7][5]=1;
		matrix[7][9]=1;
		matrix[7][2]=1;

		matrix[8][5]=1;
		matrix[8][6]=1;
		matrix[8][3]=1;

		matrix[9][4]=1;
		matrix[9][6]=1;
		matrix[9][7]=1;

		int res=findop(-1,0);

		if(res==-1)
		{	cout<<-1;	}
		else
		{
			cout<<res;
			for(int x=0;x<iplen-1;x++)
			{
				cout<<nextdp[x][res];
				res=nextdp[x][res];
			}
		}


		cout<<"\n";

	}
	return(0);
}

