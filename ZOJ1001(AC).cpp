#include <cstdio>
using namespace std;

int main()
{
    int a, b;

    while(1)
    {
        if(scanf("%d%d", &a, &b) != 2)
        {
            break;
        }
        else
        {
            printf("%d\n", a + b);
        }
    }

    return 0;
}

