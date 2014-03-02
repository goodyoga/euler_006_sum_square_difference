/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <string.h>   /* strlen  */
#include <unistd.h>   /* getopt */

/**
 * @file main_006.c
 * @addtogroup  EULER_006  Euler_006_Sum_Square_Difference
 * @{
 */


#define BUFF_SIZE   128


void usage(void);
int main(int argc, char **argv);


/** @} */


/***********************************
 * Implementation
 ***********************************/


int main(int argc, char **argv)
{
    unsigned long long int max;
    unsigned long long int sum_of_sq, sq_of_sum, i, j;
    int opt, all = 0;
    char *p;
    
    max = 100;

    while ( -1 != (opt = getopt(argc, argv, "ahn:")) )
    {
        if('h' == opt)
	{
            usage();
            exit(EXIT_SUCCESS);
	}
        else if ('n' == opt)
        {
            max = strtoull(optarg, &p, 0);
        }
        else if ('a' == opt)
        {
            all = 1;
        }
    }
    
    printf("getting Smallest multiple in %llu ...\n", max);

    sum_of_sq = 0;
    sq_of_sum = 0;
    j = 0;
    for ( i = 1 ; i <= max ; i++)
    {
        sum_of_sq += i*i;
        j += i;
        if (all) printf("check  : %llu,%llu: sum_of_sq:%llu\n",i,j, sum_of_sq );
    }
    sq_of_sum = j*j;
    
    printf("answer: %llu - %llu = %llu\n", sq_of_sum, sum_of_sq, (sq_of_sum - sum_of_sq));
    return EXIT_SUCCESS;
}



void usage(void)
{
    printf("    http://projecteuler.net/problem=6\n");
    printf("    [Problem 6] Sum Square Difference\n");
    printf("    The sum of the squares of the first ten natural numbers is,\n"
           "        1^2 + 2^2 + ... + 10^2 = 385\n"
           "    The square of the sum of the first ten natural numbers is,\n"
           "        (1 + 2 + ... + 10)^2 = 55^2 = 3025\n"
           "    Hence the difference between \n"
           "    the sum of the squares of the first ten natural numbers and \n"
           "    the square of the sum is 3025 − 385 = 2640.\n"
           "\n"
           "    Find the difference between \n"
           "    the sum of the squares of the first one hundred natural numbers and \n"
           "    the square of the sum.\n\n");
    printf("    -h: show this help\n"
           "    -n <number>: solve this with max <number>\n");
    return;
}


