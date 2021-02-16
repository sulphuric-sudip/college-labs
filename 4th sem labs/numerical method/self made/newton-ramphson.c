/*
		Created by sudip
		Edit denoted line before compile
		Edit denoted line before compile
		Edit denoted line before compile
*/

#include<stdio.h>
#include<math.h>
#include<windows.h>

float g(float x){
	float fx,dfx;
	fx=pow(x,3.0) - pow(x,2.0) + x +7;    //***EDIT HERE f(X) eg. 4x^3: 4*pow(x,3.0) ,  cos(x) 
	dfx = 3*pow(x,2.0) - 2*x + 1;         //***Edit here  f'(X)
	x = x - fx/dfx;
	return x;
}
 
int main(){
	printf("\tNewton Ramphson Iteration\n\n");
	printf("\t\tFunction:   X^3-X^2+X+7    \n");     ///****EDIT FUNCTION HERE
	printf("\n\t\tDerivative:  3X^2-2X+1   \n\n");   //****Edit here

	float x[100],err=1;
	int i=0;
	x[0]=0.112;   //***Edit here initial guess
	
	float err_pt = 4;    //****EDIT HERE error upto dec point
	err_pt=-1.0-err_pt;
	err_pt=pow(10.0,err_pt);
	
	while(err>err_pt){
		x[i+1]=g(x[i]);
		err=x[i+1]-x[i];
		err=fabs(err);
		printf("\t%d.\t%f\n",i+1,x[i+1]);
		i++;
		Sleep(500);
	}
	printf("\n \tThe root is %.5f",x[i]);
	printf("\n\n\t\tSULPHURIC.SUDIP SAYS:-\"THANK YOU FOR USING....STAY SAFE :) (:\"");
	getch();
	return 1;
}
