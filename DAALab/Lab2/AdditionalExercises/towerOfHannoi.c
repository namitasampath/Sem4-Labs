#include<stdio.h>
static long int c=0;

void towerOfHanoi(int n, char source, char destination , char temp){
    c++;
    if (n==1){
        //printf("Move disk 1 from %c to %c\n", source , destination);
        return;
    }
    towerOfHanoi(n-1, source , temp, destination);
    //printf("Move disk %d from %c to %c\n", n, source , destination);
    towerOfHanoi(n-1, temp, destination, source);
}
int main(){
    int n,i;
    for(i=0; i<15; i++){
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    printf("Count: %ld\n", c);
    c=0;
    }
    return 0;
}
