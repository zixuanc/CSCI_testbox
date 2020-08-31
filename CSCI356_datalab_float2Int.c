#include<stdio.h>

int float2Int(unsigned uf){
    int sign = uf >> 31;
    unsigned exponent = (uf >> 23) & 0xFF;
    int fraction = uf & 0x007FFFFF;
    int target = (uf & (0x80000000)) | 0x40000000 | (fraction << 7);
    int shift;
    if(exponent == 0xFF){
        return 0x80000000u;
    } 
    else if(exponent == 0x0){
        shift = 0;
    }
    else{
        shift = exponent - 127;
    }
    if(shift < 0) return 0;
    if(shift > 30) return 0x80000000u;
    printf("sign = %d, exp = %u, shift = %d, fraction = %x, target = %x\n",sign, exponent, shift, fraction, target);
    target = target >> (30 - shift);
    return target;
}

int main(void) {
    unsigned input;
    scanf("%x", &input);
    printf("input = %x\n", input);
    int ans = float2Int(input);
    printf("answer = %x", ans);
    
    return 0;
}
