// write a c program to find area of a circle, reactangl;e, and triangle.
#include<stdio.h>
#include<math.h>
float circularArea(float rad);
float rectangularArea(float a, float b);
float triangle(float a, float b);

int main(){
   float a, b;
   
   printf("Enter the value of a and b :");
   scanf("%f %f",&a,&b);
   float f1=circularArea(a);
   float f2=rectangularArea(a,b);
   float f3=triangle(a,b);
   printf("Only type fi or f2 or f3\n f1=circularArea(a)\n f2=rectangularArea(a,b)\n f3=triangle(a,b)\n");
   scanf("%f %f %f",&f1, &f2,&f3);
    printf("Area is : %f",f1);
    
    return 0;
};
 float circularArea(float rad){
     return 3.14*rad*rad;
 };
 float rectangularArea(float a,float b){
     return a*b;
 };
 float triangle(float a, float b){
     return 0.5*a*b;
 }