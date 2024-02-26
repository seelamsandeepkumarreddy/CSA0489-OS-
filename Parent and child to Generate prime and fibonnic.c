#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int isPrime(int num){
    if(num<2) return 0;
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return 0;
    }
    return 1;
}
void printPrimes(){
    printf("prime numbers:");
    for(int i=2;i<=20;i++){
        if(isPrime(i)){
            printf("%d",i);
        }
    }
    printf("\n");
}
void generateFibonacci(){
    printf("fibonacci series:\n");
    int a=0,b=1,temp;
    for(int i=0;i<10;i++){
        printf("%d",a);
        temp=a+b;
        a=b;
        b=temp;
    }
    printf("\n");
}
int main()
{
    pid_t pid=fork();
    if(pid<0){
        perror("fork failed:");
        exit(EXIT_FAILURE);
    }
    if(pid==0)
    {
        generateFibonacci();
    }
    else
    {
        wait(NULL);
        printPrimes();
    }
    return 0;
}
    
