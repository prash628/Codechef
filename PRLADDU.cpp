#include<iostream>

using namespace std;



int N;
int V;

struct x
{
	int number;
	int location;
}dino[100002];


struct y
{
	int number;
	int location;
}vilard[100002];

int Dcount,Vcount;

int main()
{

	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		Dcount=0,Vcount=0;
		cin>>V;
		int value;
		for(int x=0;x<V;x++)
		{
			cin>>value;
			if(value<0)
			{
				int nom=value*-1;
				dino[Dcount].location=x;
				dino[Dcount].number=(nom);
				Dcount++;
			}
			if(value>0)
			{
				vilard[Vcount].location=x;
				vilard[Vcount].number=value;
				Vcount++;
			}
		}

		int p,q;
		p=0;
		q=0;

		unsigned long long total=0;
		int moi;
		while(1)
		{
			if(p==Dcount && q==Vcount){break;}

			else if(dino[p].number>vilard[q].number)
			{
				dino[p].number=dino[p].number-vilard[q].number;
				moi=((dino[p].location-vilard[q].location));
				if(moi<0){moi=moi*-1;}
				total=(unsigned long long)total+((unsigned long long)vilard[q].number*moi);
				q++;
			}
			else
			{
				if(dino[p].number==vilard[q].number)
				{
					moi=((dino[p].location-vilard[q].location));
					if(moi<0){moi=moi*-1;}
					total=(unsigned long long)total+((unsigned long long)vilard[q].number*moi);
					 q++;p++;
				}
				else
				{

					vilard[q].number=vilard[q].number-dino[p].number;
					moi=((dino[p].location-vilard[q].location));
					if(moi<0){moi=moi*-1;}
					total=(unsigned long long)total+((unsigned long long)dino[p].number*moi);
					p++;
				}
			}
			if(p==Dcount && q==Vcount){break;}
		}
		cout<<total<<"\n";

	}
	return(0);
}
