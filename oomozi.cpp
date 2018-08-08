#include<cstdio>
int main(){
  char s[1201];//ヌル文字分
 scanf("%[^\n]", s);
 for (int i =0;s[i] != '\0';i++){
   char c = s[i];
   if(c >= 65 && c <= 90){
     s[i] = c + 32;
   }
   else if(c >= 97 && c <= 122){
     s[i] = c -32;
   }
 }
 printf("%s\n", s);
 return 0;
}
