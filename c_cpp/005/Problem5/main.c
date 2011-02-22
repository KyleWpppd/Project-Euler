#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define LARGEST 20
/* How can we do this algorithmically...
 as a human I would take all of the factors and multiply them...
 first I would eliminate and multiply all primes in the sequence
 then I would decompose the largest composite numbers into their factors
 
 How do decompose.....a struct for every number... we'll try that for number 2...
 
 */

typedef struct {
	uint64_t integer_factor;
	uint16_t factor_count;
	bool is_used_alreadyP;
} factor_t;


uint64_t first_prime_factor(uint64_t);
uint64_t fact_mult(const factor_t *);
uint16_t number_of_primes(uint64_t);
int push_the_factors(uint64_t, factor_t *);
int prime_factorize(uint64_t);
int print_factor_counts(const factor_t *);
int init_factor_list(factor_t *);
int second_try();
int first_try();



// returns the number of primes below ceiling
// not yet implemented
uint16_t number_of_primes(uint64_t prime_ceiling)
{
	
	return 0;
}

uint64_t fact_mult(const factor_t *factor_list)
{
	uint64_t sum = 1;
	uint16_t i, fac_count;
	
	printf("From fact_mult\n");
	printf("Fac\t|\tCount\n_____________________\n");
		
	for(i = 0; i < LARGEST; i++)
	{
		fac_count = (factor_list+i)->factor_count;
		printf("%llu\t|\t%d\n",(factor_list+i)->integer_factor,(factor_list+i)->factor_count);
		
		while(fac_count > 0){
			sum *= (factor_list+i)->integer_factor;
			fac_count--;
		}
	}
	return sum;
}


int print_factor_counts( const factor_t * factor_list){
	uint16_t i;
	printf("Fac\t|\tCount\n_____________________\n");
	for (i = 0; i < LARGEST; i++)
	{
		printf("%llu\t|\t%d\n",(factor_list+i)->integer_factor, (factor_list+i)->factor_count);
	}
	return 0;
}

int push_the_factors(uint64_t composite_number, factor_t *master_factor_array_ptr)
{
	factor_t* comp_number_factor_list_ptr = (factor_t*) malloc(LARGEST * sizeof(factor_t));
	init_factor_list(comp_number_factor_list_ptr);
	uint64_t first_factor;
	uint16_t i;
		
		while(first_factor = first_prime_factor(composite_number)){
			// put the factor in the appropriate offset for the factors
			// since the head of the array = 1, subtract 1 from first_factor to 
			// get the appropriate cell
			
			
			(comp_number_factor_list_ptr+(first_factor-1))->factor_count += 1;
			//printf("%llu = _%llu_ * ",composite_number,(comp_number_factor_list_ptr+(first_factor-1))->integer_factor);
			composite_number /= first_factor;
			//printf("%llu (count: %d)\n",composite_number, (comp_number_factor_list_ptr+(first_factor-1))->factor_count);
		}
	
	for(i = LARGEST; i > 0; i--)
	{
		if( (comp_number_factor_list_ptr+i)->factor_count > (master_factor_array_ptr+i)->factor_count)
			(master_factor_array_ptr+i)->factor_count = (comp_number_factor_list_ptr+i)->factor_count;
	}
	
	
	// Give the memory back
	free(comp_number_factor_list_ptr);
	comp_number_factor_list_ptr = NULL;
	return 0;
}



int init_factor_list(factor_t *factor_list)
{
	if(factor_list == NULL)
	{
		printf("memory error\n");
		exit(1);
	}
	uint16_t i = 0;
	for(i = LARGEST; i > 0; i--, factor_list++)
	{
		factor_list->integer_factor = (LARGEST+1 - i);
		factor_list->is_used_alreadyP = false;
		factor_list->factor_count = 0;
		//printf("Factor %llu->%s\n",factor_list->integer_factor, factor_list->is_used_alreadyP == 1? "true": "false");
	}
	return 0;
}

// a function to return the prime factors of base
// works by dividing base by the smallest prime number it can
// if base is indivisible, base is prime
int prime_factorize(uint64_t composite_number){
	
	uint64_t first_factor[20];
	uint16_t i = 0;
	while(true){
		first_factor[i] = first_prime_factor(composite_number);
		if(first_factor[i] == 0)
			break;
		composite_number /= first_factor[i];
		if(i < 20 )
			i++;
		else
			return 1;
	}

	return 0;	
}

// returns the first prime between lower and uppper, inclusively [lower,upper]
// returns 0 if no factor is within range
uint64_t first_prime_factor(uint64_t composite_number){
	uint64_t first_factor = 2;
	
	if (composite_number <= 1)
		return 0;
	
	// go through every factor until a prime is reached
	while(composite_number % first_factor != 0 && first_factor < composite_number)
	{
		first_factor++;
	}
	
	//printf("first prime factor of %llu is %llu\n", composite_number, first_factor);

	//here for clarity
	if(first_factor == composite_number)
		return composite_number; 
	
	return first_factor;
}



int second_try(){
	uint16_t i;
	factor_t* factor_list_ptr = (factor_t*) malloc(LARGEST * sizeof(factor_t));

	if(factor_list_ptr == NULL){
		printf("Memory hates you\n");
		exit(1);
	}
	// initialize factors
	init_factor_list(factor_list_ptr);
	
	for(i = LARGEST; i > 0; i--)
	{
		push_the_factors(i, factor_list_ptr);
	}
	print_factor_counts(factor_list_ptr);
	
	printf("LCM -> %llu\n",fact_mult(factor_list_ptr));
	
	
	
	// give back the memory
	free(factor_list_ptr);
	factor_list_ptr = NULL;
	return 0;
	
}




int first_try () {
	uint64_t test=0, max_possible, i=0;
	max_possible = 1;
	
	for(i = 2; i <= LARGEST; i++) // compute the largest possible number
	{
		//printf("%llu * ", i);
		max_possible *= i;

	}
	printf("Max: %llu\n", max_possible);
	//	bool divisible_by_allP = false; //thought I might need this, but if we get out of the inner for loop and i == 2 we know we were successful;
	test = LARGEST;
	while(test < max_possible)
	{
		//printf("%llu >-x-< %llu: ",max_possible,test);
		
		for (i= LARGEST; i >= 2; i--) { // we count down since it is more likely to miss higher numbers
			
//			printf("%llu ",i);
			if(test % i != 0){ //if we aren't divisible by all less than LARGEST, then we break and increment
//				printf("nDiv, r=%llu",test%i);
				break;
			}
		
		}
		
//		printf("** i: %d", i);
		if(i <= 2)
			break;
		
		test += LARGEST; //the number must be divisible by the largest and 2, so just increment by it
//		printf("\n");
	}
	
	printf("Largest Number Divisible from 2 to %d: %llu\n", (int)LARGEST, test);
    return 0;
}
 

int main (int argc, const char * argv[]){
//	first_try();
	second_try();
//	prime_factorize(4532);
	return 0;
}
