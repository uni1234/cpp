#include <cstdio>
void toUpper(char str[])
{

    for (int i = 0; str[i] != '\0'; i++)
    {

        
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            printf("%c", str[i] - 32);
        }
        else
        {
            printf("%c", str[i]);
        }
        
    }
}
int main()
{
    char str[101];
    scanf("%[^\n]", str);
    toUpper(str);
    printf("\n");
    return 0;
}