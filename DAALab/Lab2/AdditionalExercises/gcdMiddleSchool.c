#include<stdio.h>
int gcd(int m, int n,int *opcount){
    int gcd=1;
    int i;
    int min =(m<n)?m:n;
    for(i=2; i<=min;i++){

        while(m%i ==0 && n%i==0){
            (*opcount)++;
            gcd *=i;
            m/=i;
            n/=i;
        }
    (*opcount)++;
    }
    return gcd;
}
int main(){
    int m;
    int n,i;
    for(i=0;i<20;i++){
    int sum=0;
    printf("Enter two numbers: ");
    scanf("%d %d", &m, &n);
    sum=m+n;
    printf("M+N: %d\n",sum);
    int opcount =0;
    int result = gcd(m,n,&opcount);
    printf("The gcd of %d and %d is %d\n", m,n, result);
    printf("The number of operations is: %d \n", opcount);}
    return 0;
}
