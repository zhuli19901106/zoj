#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int top;
	int available;
	int i;
	int t;
	string a[105];
	char cmd[1000];
	char head[20];
	char url[200];
	string urlstr;
	string headstr;
	//ofstream cout("out.txt");

	for(i = 0; i < 105; i++)
	{
		a[i] = "";
	}
	a[0] = "http://www.acm.org/";

	gets(cmd);
	sscanf(cmd, "%d", &t);
	for(i = 0; i < t; i++)
	{
		gets(cmd);
		if(i > 0)
		{
			cout<<endl;
		}

		available = 1;
		top = 1;
		while(1)
		{
			gets(cmd);
			sscanf(cmd, "%s", head);
			headstr = head;
			if(headstr == "QUIT")
			{
				break;
			}
			else if(headstr == "BACK")
			{
				if(top <= 1)
				{
					cout<<"Ignored"<<endl;
				}
				else if(top > 1)
				{
					top--;
					cout<<a[top - 1]<<endl;
				}
			}
			else if(headstr == "FORWARD")
			{
				if(available > top)
				{
					cout<<a[top]<<endl;
					top++;
				}
				else
				{
					cout<<"Ignored"<<endl;
				}
			}
			else if(headstr == "VISIT")
			{
				strcpy(url, cmd + 6);
				urlstr = url;
				a[top] = url;
				cout<<a[top]<<endl;
				top++;
				if(available < top)
				{
					available = top;
				}
				else if(available > top)
				{
					available = top;
				}
			}
		}
	}

	return 0;
}

