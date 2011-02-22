/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91  99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/


#include <stdio.h>
#include <stdlib.h>

//define crap
#define TRUE 1
#define FALSE 0
#define PALMAXFACTOR 999
#define PALMINFACTOR 1

// funtion prototypes
int num_digits(int);
int is_pal(int);


int main()
               
{
	int maxpalfound = 0;
	maxpalfound = pal_gen();
	printf("Max pal =%d\n", maxpalfound);
		
   return 0;
   
}


/* 	generates multiples of 3 digit numbers starting at 999
 	and going backwards until it finds a palindrome
*/
int pal_gen(){
	int start=PALMAXFACTOR, stop=PALMINFACTOR, testnum, otherfactor, maxpal =0;
	while(start > 0)
	{
		testnum = start * start;
		otherfactor = start;
		if (testnum < maxpal){ //if there's no way to get to maxpal, just quit
		printf("%d (%d*%d) is less than %d\n", testnum, start,start, maxpal);
			break;
		}
		while(testnum > maxpal && !is_pal(testnum)){
			
		//	printf("%d=%d*%d   max=%d\n",testnum,start,otherfactor,maxpal);
			testnum -= start;
			otherfactor--;
		}
		if(is_pal(testnum) && testnum > maxpal){
			maxpal = testnum;
			printf ("The number %d is the highest Palindrome\n", maxpal);
		}
		start--;
	}
	return maxpal;
}


int is_pal(int number)
{
	int remainder=0, sum=0, temp=number;
	while(temp>0)
	    {
	      remainder = temp%10; //Gets Last Digit
	      temp/=10;          //Truncates Last Digit
	      sum=sum*10 + remainder; //Builds value of reversed number
		//printf("rem=%d, tmp=%d, sum=%d\n", remainder, temp, sum);
	     }

	   if (sum==number){
	     	//printf ("The Number %d Is A Palindrome\n", number);
			return TRUE;
		}
		else{
			return FALSE;
		}
	
}