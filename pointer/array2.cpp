#include<cstdio>

int main() {
    int array[5] =  {0,10,20,30,40};
    
    for(int i = 0;i < 5;i++) {
        printf("%d\n",*(array + i));//array[i]と同じ
    }
    return 0;
}
//*(参照)と+では優先順位が*方が高いので、()ついてる