#include <stdio.h>
bool isRightTori(int a, int b, int c)
{

    return a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b;
}

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (isRightTori(a,b,c))
    {
        printf("直角三角形です\n");
    }
    else
    {
        printf("直角三角形ではありません\n");
    }
    return 0;
}