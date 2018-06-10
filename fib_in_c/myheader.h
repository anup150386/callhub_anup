/*********************************************************************
 * 
 *   Includes definitions for number crunching stuffs
 * 
 *
 * 
 ********************************************************************/

#ifndef MYHEADER 
#define MYHEADER

typedef struct 
{
  int number;
  char  *result;
  double time;
} json_response ;

char *calculate(int number);
json_response *fibonacci(int number);

#endif
