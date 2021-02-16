/* 
	****GAUSS-SIDEL ITERATION(4X4)METHOD*******
	CREATED BY:- SULPHURIC.SUDIP
	STARTED ON:- SEP-16, 2O2O  -adding on gauss sidal(3X3) 
*/

#include <stdio.h>
#include<conio.h>
#include<windows.h>
#include<math.h>

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

float a[4][5];

float fx(float y, float z, float w){
	float x;
	x = (a[0][4]-a[0][1]*y-a[0][2]*z-a[0][3]*w)/a[0][0]; 
	return x;	
} 
float fy(float x, float z, float w){
	float y;
	y = (a[1][4]-a[1][0]*x-a[1][2]*z-a[1][3]*w)/a[1][1];
	return y;	
}
float fz(float x, float y, float w){
	float z;
	z = (a[2][4]-a[2][0]*x-a[2][1]*y-a[2][3]*w)/a[2][2];
	return z;	
}
float fw(float x, float y, float z){
	float w;
	w = (a[3][4]-a[3][0]*x-a[3][1]*y-a[3][2]*z)/a[3][3];
	return w;
}

int main(){
	float x[100],y[100],z[100],w[100],err[4];
	x[0]=0,y[0]=0,z[0]=0,w[0]=0;
	changeColor(15);
	gotoxy(5,1);printf("FIRST REARRNGE EQUATION AS DIAGONAL DOMINANT");
	gotoxy(5,2);printf("GIVE THE VALUE OF a's, b's, c's and d's.");
	changeColor(12);
	gotoxy(9,4);printf("a1  X + b1  Y + c1  Z + d1  W = e1");
	gotoxy(9,5);printf("a2  X + b2  Y + c2  Z + d2  W = e2");
	gotoxy(9,6);printf("a3  X + b3  Y + c3  Z + d3  W = e3");
	gotoxy(9,7);printf("a4  X + b4  Y + c4  Z + d4  W = e4");
	changeColor(15);
	gotoxy(5,9);printf("GIVE Coe. VALUE SERIALLY AS IN EQUATION ABOVE \n(wrong input runs programme in uncontrolled way)..Press any key to start......");
	int i,j;
	getch();
	changeColor(10);
	for(i=0;i<4;i++){
		for(j=0;j<5;j++){
			gotoxy(9+8*j,4+i);printf("  ");
			gotoxy(9+8*j,4+i);scanf("%f",&a[i][j]);
		}
		err[i]=1;
	}
	changeColor(12);
	gotoxy(10,11);printf("GIvE InItIaL GuEsS FoR Y, Z & W:   ");
	scanf("%f%f%f",&y[0],&z[0],&w[0]);
	gotoxy(3,15);changeColor(15);printf("CORRECT ERROR UPTO ... DECIMAL POINT:- ");
	float err_pt;
	int dec_pt;
	scanf("%d",&dec_pt);
	err_pt=-1.0-dec_pt;
	err_pt=pow(10.0,err_pt);
/*       NOW ITERATION STARTS   */
		i=0;
		changeColor(7);gotoxy(1,17);printf("ITERATON");gotoxy(18,17);printf("X");gotoxy(28,17);printf("Y");gotoxy(38,17);printf("Z");gotoxy(48,17);printf("W\n");
		for(j=0;j<60;j++)
			printf("-");
		changeColor(11);
		while(err[0]>err_pt||err[1]>err_pt||err[2]>err_pt||err[3]>err_pt){
		
			x[i+1]=fx(y[i],z[i],w[i]);
			err[0]=x[i+1]-x[i];
			err[0]=fabs(err[0]);
		
			y[i+1]=fy(x[i+1],z[i],w[i]);
			err[1]=y[i+1]-y[i];
			err[1]=fabs(err[1]);
		
			z[i+1]=fz(x[i+1],y[i+1],w[i]);
			err[2]=z[i+1]-z[i];
			err[2]=fabs(err[2]);
			
			w[i+1]=fw(x[i+1],y[i+1],z[i+1]);
			err[3]=w[i+1]-w[i];
			err[3]=fabs(err[3]);
		
			gotoxy(5,19+i);printf("%d",i+1);gotoxy(14,19+i);printf("%.5f",x[i+1]);gotoxy(24,19+i);printf("%.5f",y[i+1]);gotoxy(34,19+i);printf("%.5f",z[i+1]);gotoxy(44,19+i);printf("%.5f",w[i+1]);
			i++;
			Sleep(500);
		}
	changeColor(10);printf("\a\n\n\tThe roots are X: %.5f , Y: %.5f , Z: %.5f , W: %.5f ",x[i],y[i],z[i],w[i]);
	changeColor(15);
	printf("\n\n\t\tSULPHURIC.SUDIP SAYS:-\"THANK YOU FOR USING....STAY SAFE :) (:\"");
	getch();
	return 1;
}
