//Question: WRITE A C PROGRAM TO FIND WHETHER A GIVEN INPUT NUMBER IS ODD OR EVEN

//by use function

#include <stdio.h>
int checkOddEven(int n);

int main(){
     int n;
     printf("enter intiger number :");
     scanf("%d",&n);
     int result=checkOddEven(n);
     if(result==0){
        printf("number is even %d \n",n);
     }else{
        printf("number is odd %d",n);
     }
}

int checkOddEven(int n){
    if(n%2==0){
        return 0; //even
    }else{
        return 1; //odd
    }
};

//by use without function.

#include<stdio.h>
int main(){
int number;
printf("Enter integer number :");
scanf("%d",&number);

    if((number%2)==0){
        printf("number is even.");
    }
    else{
        printf("number is odd.");
    };
    

return 0;
}
