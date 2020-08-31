#include<stdio.h>

int isGreater(int x, int y){
    /*
    解决 x > y 
    第一种情况，x > y return 1, 等价于 y < x return 1
    第二种情况，x <= y return 0, 等价于 y >= x return 0;
    */
    // int sameSign = ((x ^ y) >> 31)+1; //xy同号为1，否则为0
    // int ySign = y >> 31; // y非负数为0， 负数为-1
    // int diffSign = (y + (~x+1)) >> 31; // y-x >= 0 为0. 否则为-1
    // int ans = ((!sameSign) & (ySign)) | ((sameSign) & (diffSign & 1));
    //     return ans;
    
    int diff = ~(~y + x);
    return ((diff ^ ((y ^ x) & (diff ^ y))) >> 31) & 1;
}

int main(void) {
    int x, y;
    scanf("%d%d", &x, &y);
    int ans = isGreater(x,y);
    printf("answer = %d", ans);
    return 0;
}
