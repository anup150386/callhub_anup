#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include <time.h>
#include "myheader.h"


char *calculate(int number)
{
	json_response *returned_result = fibonacci(number);

    char * final_json_string = NULL;
    
    size_t len = 0;
    

    len = snprintf(NULL,len,"{'number':%d,'result':%d,'time_in_sec':%lf}",returned_result->number,returned_result->result,returned_result->time);

    char *apstr = calloc (1, sizeof *apstr * len + 1);
    if (!apstr) {
        fprintf (stderr, "%s() error: virtual memory allocation failed.\n", __func__);
    }

    /* write/validate struct values to apstr */
    if (snprintf (apstr, len + 1, "{'number':%d,'result':%d,'time_in_sec':%lf}",returned_result->number,returned_result->result,returned_result->time) > len + 1)
    {
        fprintf (stderr, "%s() error: snprintf returned truncated result.\n", __func__);
        return NULL;
    }

    printf ("\n The final json response:\n\n  '%s'\n\n", apstr);

    /* free dynamically allocated memory */
    //if (apstr) free (apstr);  
    //char * json_in_string = convert_to_string(returned_result);
	// you got to free the memory to prevent memory leak, very important step , please don't forget
	//free(returned_result->result);
	//returned_result->result = NULL;
	free(returned_result);
	//free(final_json_string);
	return apstr;
}

json_response final_result;
json_response *fibonacci(int number)
{
	clock_t t;
	t = clock();

	// Initializations
	int* fib_arr = malloc(sizeof(int) * number);
	//memset(fib_arr,0,number * sizeof(int));
	//unsigned long long int *fib_arr = (unsigned long long int *)calloc(number,sizeof(long long int)+2);

	
	int i ;
	fib_arr[0] = 0;
	fib_arr[1] = 1;
	int a = 0;
	int b = 1;
	int result=0;
	
	
	// create the json response instance
    final_result.number = number;
    
    
    
 	// Engine
	for ( i = 2 ; i < number ; i++)
	{
		result = a+b;
		fib_arr[i] = result;
		a = b;
		b = result;
	}
	
	size_t len = 0;
    len = snprintf(NULL,len,"%d",fib_arr);
    char *apstr = calloc (1, sizeof *apstr * len + 1);
    if (!apstr) {
        fprintf (stderr, "%s() error: virtual memory allocation failed.\n", __func__);
    }

    /* write/validate arr values to apstr */
    printf ("\n The fib result :\n\n  '%s'\n\n", apstr);
    
	for ( i = 0 ; i < number ; i++)
	{
		snprintf (apstr, len + 1, "%d",fib_arr[i]);
		printf("\n The intermediate result : %d",fib_arr[i]);
	}
	
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	final_result.result = apstr;
	//final_result.result = fib_arr;
    final_result.time = time_taken;    
    
    return &final_result;
	
}




