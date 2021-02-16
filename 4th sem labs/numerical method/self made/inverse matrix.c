/*
	***INVERSE OF MATRIX*****
	CREATED BY:- SULPHURIC.SUDIP
	STARTED ON:- SEP_16, 2020
*/	
#include<stdio.h>
#include<conio.h>
#include<windows.h>

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

float x[3][3],a[3][3];

void printmatrix(){
	int i,j;
	for(i=0;i<3;i++){
		printf("\n");
		changeColor(9);
		for(j=0;j<3;j++){
			printf("\t%.2f",a[i][j]);
		}
		changeColor(15);
		printf("\t::");
		changeColor(11);
		for(j=0;j<3;j++){
			printf("\t%.2f",x[i][j]);
		}
	}
	Sleep(1000);
}
void swap(int pos){
	int i;
	float temp,temp1;
	if(pos==1){
		if(a[0][0]==0){
			if(a[1][0]!=0){
				for(i=0;i<3;i++){
					temp=a[0][i];
					a[0][i]=a[1][i];
					a[1][i]=temp;	
					temp1=x[0][i];
					x[0][i]=x[1][i];
					x[1][i]=temp1;
				}
				changeColor(15);printf("\n\nR1 <--> R2\n");
				printmatrix();
			}
			else if(a[2][0]!=0){
				for(i=0;i<3;i++){
					temp=a[0][i];
					a[0][i]=a[2][i];
					a[2][i]=temp;	
					temp1=x[0][i];
					x[0][i]=x[2][i];
					x[2][i]=temp1;
				}
				changeColor(15);printf("\n\nR1 <--> R3\n");
				printmatrix();
			}
		}
	}
	else if(pos==2){
		if(a[1][1]==0){
			if(a[2][1]!=0){
				for(i=0;i<3;i++){
					temp=a[2][i];
					a[2][i]=a[1][i];
					a[1][i]=temp;	
					temp1=x[2][i];
					x[2][i]=x[1][i];
					x[1][i]=temp1;
				}
				changeColor(15);printf("\n\nR2 <--> R3\n");
				printmatrix();
			}
		}
	}
}
int main(){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==j)
				x[i][j]=1;
			else
				x[i][j]=0;
		}
	}
	changeColor(15);
	printf("\n\t\tINVERSE FOR 3*3 MATRIX");
	printf("\ndont give fraction or function as input");
	changeColor(11);
	gotoxy(8,5);printf("a00      a01      a02");
	gotoxy(8,6);printf("a10      a11      a12");
	gotoxy(8,7);printf("a20      a21      a22");
	changeColor(15);gotoxy(3,9);printf("Give element of matrix in serial order mention as above");
	printf("\nPress any key to start.....");
	getch();
	changeColor(10);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			gotoxy(8+9*j,5+i);printf("   ");
			gotoxy(8+9*j,5+i);scanf("%f",&a[i][j]);
		}
	}
	gotoxy(0,11);
	printmatrix();
	
	swap(1);
	changeColor(15);printf("\n\nR1 --> 1/%.2f*R1\n",a[0][0]);
	float temp1,temp2;
	temp1=a[0][0];
	for(i=0;i<3;i++){
		a[0][i]=a[0][i]/temp1;
		x[0][i]=x[0][i]/temp1;
	}
	printmatrix();
	changeColor(15);printf("\n\nR2 --> R2 - %.2f*R1\nR3 --> R3 - %.2f*R1\n",a[1][0],a[2][0]);
	temp1=a[1][0];
	temp2=a[2][0];
	for(i=0;i<3;i++){
		a[1][i]=a[1][i]-temp1*a[0][i];
		x[1][i]=x[1][i]-temp1*x[0][i];
		a[2][i]=a[2][i]-temp2*a[0][i];
		x[2][i]=x[2][i]-temp2*x[0][i];
	}
	printmatrix();
	
	swap(2);
	changeColor(15);printf("\n\nR2 --> 1/%.2f*R2\n",a[1][1]);
	temp1=a[1][1];
	for(i=0;i<3;i++){
		a[1][i]=a[1][i]/temp1;
		x[1][i]=x[1][i]/temp1;
	}
	printmatrix();
	changeColor(15);printf("\n\nR1 --> R1 - %.2f*R2\nR3 --> R3 - %.2f*R2\n",a[0][1],a[2][1]);
	temp1=a[0][1];
	temp2=a[2][1];
	for(i=0;i<3;i++){
		a[0][i]=a[0][i]-temp1*a[1][i];
		x[0][i]=x[0][i]-temp1*x[1][i];
		a[2][i]=a[2][i]-temp2*a[1][i];
		x[2][i]=x[2][i]-temp2*x[1][i];
	}
	printmatrix();
	
	changeColor(15);printf("\n\nR3 --> 1/%.2f*R3\n",a[2][2]);
	temp1=a[2][2];
	for(i=0;i<3;i++){
		a[2][i]=a[2][i]/temp1;
		x[2][i]=x[2][i]/temp1;
	}
	printmatrix();
	changeColor(15);printf("\n\nR1 --> R1 - %.2f*R3\nR2 --> R2 - %.2f*R3\n",a[0][2],a[1][2]);
	temp1=a[0][2];
	temp2=a[1][2];
	for(i=0;i<3;i++){
		a[0][i]=a[0][i]-temp1*a[2][i];
		x[0][i]=x[0][i]-temp1*x[2][i];
		a[1][i]=a[1][i]-temp2*a[2][i];
		x[1][i]=x[1][i]-temp2*x[2][i];
	}
	printmatrix();
	changeColor(14);
	printf("\n\nTHE INVERSE IS \n\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("\t%.2f",x[i][j]);	
		}
		printf("\n");
	}
	changeColor(15);
	printf("\n\n\t\tSULPHURIC.SUDIP SAYS:-\"THANK YOU FOR USING....STAY SAFE :) (:\"");
	getch();
	return 1;
}
