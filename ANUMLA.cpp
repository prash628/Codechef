#include<iostream>
#include<string>
#include <cstdio>
#include <algorithm>
#include<unordered_map>
using namespace std;



static struct IO {
	char tmp[1 << 10];

	// fast input routines
	char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

	// fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;


struct mystruct
{
	int total;
	int used;
}Count;


unordered_map<long long,mystruct> hashmapSum;

int N;
int acount;
 unsigned long long result;
 int elements[50000];
 long long resultA[16];
 int total;

int main()
{

	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{

		acount=-1;
		total=0;
		cin>>N;
		double lim=(double)N;
		double limit=pow(2.0,lim);
		int limI=(int)limit;


		for(int k=0;k<limI;k++)
		{

			cin>>elements[k];

		}

			sort(&elements[0],&elements[limI]);

			for(int j=1;j<limI;j++)
			{
				  struct mystruct mycheck;
				long long elemchk=(long long)elements[j];
				unordered_map<long long,mystruct>::const_iterator found=hashmapSum.find(elemchk);

				int goWhere;
				if(found==hashmapSum.end())
				{
					goWhere=1;
				}
				else
				{
					struct mystruct mycheck=found->second;
					if(mycheck.total-mycheck.used<1)
					{
						goWhere=1;
					}
					else
					{
						goWhere=2;
					}
				}
				if(goWhere==1)
				{
					resultA[total]=elemchk;

					total++;

					vector<long long> addTo;
					vector<int> valuesTo;

					for(unordered_map<long long,mystruct>::iterator found2=hashmapSum.begin();found2!=hashmapSum.end();found2++)
					{
							long long ele=found2->first;

							long long newele=ele+elemchk;

							addTo.push_back(newele);valuesTo.push_back((found2->second).total);
					}




					for(int p=0;p<addTo.size();p++)
					{
							unordered_map<long long,mystruct>::const_iterator found3=hashmapSum.find(addTo[p]);
							if(found3==hashmapSum.end())
							{
								struct mystruct newx;
								newx.total=valuesTo[p];
								newx.used=0;
								hashmapSum[addTo[p]]=newx;
							}
							else
							{
								struct mystruct newx;
								newx.total=valuesTo[p]+(found3->second).total;
								newx.used=(found3->second).used;
								hashmapSum[addTo[p]]=newx;
							}
					}

					unordered_map<long long,mystruct>::const_iterator found1=hashmapSum.find(elemchk);
					if(found1==hashmapSum.end())
					{
						struct mystruct newx;
								newx.total=1;
								newx.used=1;
						hashmapSum[elemchk]=newx;
					}
					else
					{
						struct mystruct newx;
								newx.total=1+(found1->second).total;
								newx.used=(found1->second).used+1;
						hashmapSum[elemchk]=newx;

					}

				}
				else
				{
					struct mystruct newx;
					newx.total=(found->second).total;
					newx.used=(found->second).used+1;
					hashmapSum[elemchk]=newx;
				}
			}
			sort(&resultA[0],&resultA[total]);
				for(int y=0;y<total;y++)
			{
				if(y!=total-1)
				{
					cout<<resultA[y]<<" ";
				}
				else
				{
					cout<<resultA[y];
				}

			}
		    cout<<"\n";
			hashmapSum.clear();

	}
	return(0);

}
