#include <stdio.h>
#include <stdlib.h>

int main() {
	int N=0;
	char c;
	int kolvo = 0;
	printf("Enter count number :\n");
	c = fgetc(stdin);
	while (c != '\n' && c != ' ' && (c >= '0' && c <= '9')) {
		N = N * 10 + (c - '0');
		c = fgetc(stdin);
	}
	kolvo += Kolvo_N(0, N);
	kolvo += Kolvo_N(1, N);
	kolvo += Kolvo_N(2, N);
	kolvo += Kolvo_N(3, N);
	kolvo += Kolvo_N(4, N);
	kolvo += Kolvo_N(5, N);
	kolvo += Kolvo_N(6, N);
	kolvo += Kolvo_N(8, N);
	printf("kolvo tel nomer - %d", kolvo);
}

int Kolvo_N(int pos,int max) {
	if (max==0)
	{
		return 1;
	}
	int k = 0;
	if ((pos+5<9||pos+5==10)&&pos!=4) {
		k +=Kolvo_N(pos + 5, max - 1);
	}
	if ((pos+7<9||pos+7==10)&&pos!=4)
	{
		k += Kolvo_N(pos + 7, max - 1);
	}
	if (pos - 7 >= 0 && pos != 9)
	{
		k += Kolvo_N(pos - 7, max - 1);
	}
	if (pos - 5 >= 0 && pos != 9)
	{
		k += Kolvo_N(pos - 5, max - 1);
	}
	if (pos%3==0&&pos!=9&&pos!=0)
	{
		k += Kolvo_N(pos - 1, max - 1);
	}
	if ((pos+1) % 3 == 0 && (pos+1) != 9)
	{
		k += Kolvo_N(pos + 1, max - 1);
	}
	return k;
}