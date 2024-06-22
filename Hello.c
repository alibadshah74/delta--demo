#include<stdio.h>

float convertTemp(float celsius);

int main(){
   // float celsius;
   // printf("enter temperature :");
   // float far=scanf("%f", &celsius);
   float far=convertTemp(4);
   printf("far %f", far);
   return 0;
}

float convertTemp(float celsius){
   float far= celsius*(9.0/5.0)+32;
   return far;
}

// float c;
   // printf("enter temperature :");
   // scanf("%f", &c);

   // //f=(c*9/5)+32 centigrate to fahrenheit,, C= 5/9(f-32) fahrenheit to centigrade;

   // float f=(c*9/5)+32;

   // printf("%f",f);