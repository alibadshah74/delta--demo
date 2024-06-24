#include<stdio.h>

int main(){
    int a, b, choice;
    printf("enter a value of a and b :");
    scanf("%d %d",&a,&b);

    printf("enter your choice what you want \n1. Addition, \n2. Subtraction, \n3. multiplication \n4. division\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("sum %d",a+b);
        break;
    case 2:
        printf("sub %d",a-b);
        break;
     case 3:
        printf("mul %d",a*b);
        break;
    case 4:
        if (b==0){
            printf("Division by zero error");
        }else{
            printf("div %d",a/b);
        }
        break;

    default: printf("invalid choice ");
        break;
    }
    return 0;
}