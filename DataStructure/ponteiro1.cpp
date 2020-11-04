#include <stdio.h>
#include <stdlib.h>
int main(){
	float x,y,*z;
	printf("&x=%u &y=%u &z=%u\n",&x,&y,&z);
	int a=1,*pa;
	x=2.5;
	z=(float*)malloc(sizeof(float));//para usar o ponteiro é preciso
	                        //usar um endereço válido!!!
	*z=5.0;
	y=x+(*z);
	printf("y=%f\n",y);
	pa=&a;
	printf("&a=%u\n",&a);
	printf("pa=%u\n",pa);
}
