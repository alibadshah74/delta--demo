// question 5 : write a c program to solve a quadratic equation.
#include<stdio.h>
#include<math.h>

void sqQuaratic(double a,double b, double c);

int main(){
    double a,b,c;
    printf("enter value of a b and c :");
    scanf("%lf %lf %lf",&a,&b,&c);
    if (a == 0) {
        printf("Coefficient 'a' cannot be zero.\n");
    } else {
        sqQuaratic(a, b, c);
    }
    return 0;
};

void sqQuaratic(double a,double b, double c){
    double D=b*b-4*a*c;

    if(D>0){
        double root1=(-b+sqrt(D))/(2*a);
        double root2=(-b-sqrt(D))/(2*a);
        printf("root1 is %lf\n",root1);
        printf("root2 is %lf\n",root2);
    }
    else if(D==0){
        double root1=(-b)/(2*a);
        printf("root1 is:%lf",root1);
    }else{
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-D) / (2 * a);
        printf("Root 1 = %lf + %lfi\n", realPart, imaginaryPart);
        printf("Root 2 = %lf - %lfi\n", realPart, imaginaryPart);
    };

};