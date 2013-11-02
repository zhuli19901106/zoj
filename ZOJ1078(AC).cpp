#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool sym(int n, int i){
	string s;
	string t;
	int n0;
	for(n0 = n; n0 != 0; n0 = n0 / i)
	{
		s = s + char(n0 % i + '0');
	}
	t = s;
	reverse(s.begin(), s.end());
	return (t == s);
}

int main(){
	int n;
	int i;

	while(cin>>n && n)
	{
		cout<<"Number "<<n<<" is ";
		vector<int> v;
		for (i = 2; i < 17; ++i)
		{
			if(sym(n, i))
			{
				v.push_back(i);
			}
		}
		if(v.size())
		{
			cout<<"palindrom in basis";
			for(i = 0; i < v.size(); ++i)
			{
				cout<<' '<<v[i];
			}
			cout<<endl;
		}
		else
		{
			cout<<"not a palindrom"<<endl;
		}
	}

	return 0;
}

