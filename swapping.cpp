#include<stdio.h>
int main(){
    char s[21];
    char c[21];
    scanf("%s",s);
    scanf("%s",c);
    for(int i = 0;s[i] != '\0';i++){
        if(s[i] == c[1] && s[i + 1] == '\0' ){
            for(int j = 0;c[j] != '\0';j++){
                if(c[j] != 'n' && c[j + 1] == '\0'){
                    printf("OK\n");
                }
                else if(c[j] == 'n' && c[j + 1] =='\0'){
                    printf("NG\n");
                }
            }
        }
        else if(s[i] != c[1] && s[i + 1] == '\0'){
            printf("NG\n");
        }

    }
    return 0;
    }