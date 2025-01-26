/*1). Write a program to find GCD using consecutive integer checking method and
analyze its time efficiency*/

#include<stdio.h>
unsigned int gcdConsecutiveIntegerChecking(unsigned int m, unsigned int n){
    unsigned int minValue=(m<n)?m:n;
    int opcount=0;
    while(minValue>0){
    opcount++;
        if(m%minValue==0&&n%minValue==0){
                printf("Operation count = %d\n",opcount);

            return minValue;
        }

        minValue--;
    }
    return 1;
}
int main(){
    unsigned int m,n ;
    printf("Enter the two numbers whose GCD has to be calculated");
    scanf("%u", &m);
    scanf("%u",&n);
    printf("GCD of two numbers using gcd Consecutive Integer Checking method is %d", gcdConsecutiveIntegerChecking(m,n));
    return 0;
}
