/* Include header files */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* end of header files */

/* constant definition */
#define MAX_INPUT_N	20
#define MIN_INPUT_K	0
#define MAX_INPUT_K	(int)pow(2,31)-1
/* end of constant definition */

/* global variables */
/* end of global values */

/* recursive function, maxValueOfCoin */
/* input
	int curCoinValue: current maximun value of coins
	int index: current index of coin buffer
   return value
*/
int maxValueOfCoin(int curCoinValue, int *buffer, int index, const int N, const int K)
{
	int retValue = 0;
	
	if( index > N )
	{
		/* buffer overflow */
		return -1;
	}
	
	if( (curCoinValue + *(buffer + index)) > K )
	{
		/* value is overflow. the curCoinValue is the maximun value of coins */
		return curCoinValue;
	}
	
	retValue = maxValueOfCoin(curCoinValue+*(buffer+index), buffer, index+1, N, K);
	printf("--%d\r\n", retValue);
	if( retValue == -1 )
	{
		/* means the sum of coins is smaller than K */
		return curCoinValue;
	}
	
	return retValue;
}
/* end of recursive function, maxValueOfCoin */

/* main function */
int main(int argc, char **argv)
{
	int maxValueCoin;
	int i;
	/* the buffer for the coins. dynamic allocte based on input N value */
	int *bufCoins;
	int inputN, inputK;
	
	/* operation hint */
	printf("Input 1\r\n");
	printf("Please input two intergers, N & K.\r\n");
	printf("Which \r\n\tN is number of coins and <= 20\r\n");
	printf("\t0<= K <= 2^31-1\r\n");
	
	/* get N & K value via user input */
	scanf("%d %d", &inputN, &inputK);
	
	/* debug message to show user input value */
	printf("Intput 1: %d, %d\r\n", inputN, inputK);
	if( (inputN > MAX_INPUT_N) || (inputK < MIN_INPUT_K) || (inputK > MAX_INPUT_K) )
	{
		printf("Incorrect intput value range.\r\n");
		printf("Which \r\n\tN is number of coins and <= 20\r\n");
		printf("\t0<= K <= 2^31-1\r\n");
		return 0;
	}
	
	/* request memory for input value */
	bufCoins = (int*)malloc(inputN);
	
	/* asking input coin value */
	printf("Input 2. Press ENTER key after input each coin value.\r\n");
	for(i=0; i<inputN; i++)
	{
		int val;
		scanf("%d", &val);
		*(bufCoins+i) = val;
	}
	
	/* debug message for input value */
	for(i=0; i<inputN; i++)
	{
		printf("%d ", *(bufCoins+i));
	}
	printf("\r\n");
	
	/* calculate maximun value of coins */
	/* initial maximun value coin is 0 and start index is 0 */
	maxValueCoin = maxValueOfCoin(0, bufCoins, 0, inputN, inputK);
	printf("The maximun value of coins is %d\r\n", maxValueCoin);
	
	/* release requested memory */
	free(bufCoins);
}
/* end of main function */

/* end of file */

