#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"
#include <math.h>
/* Ambika Venkatakrishnan
 * Homework 2 
 */


/* extract_digit
 * extracts a digit at a specified position
 * inputs: 
 *	unsigned int pattern
 * 	unsigned int digit
 * return value:
 * 	unsigned int -- the digit at the given position
 */
unsigned int extract_digit(unsigned int pattern, unsigned int digit)
{
	int p1 = pow(10,digit + 1);
	int p2 = pow(10,digit);
	return (pattern % p1)/p2;
}

/* num_of_color
 * finds the number of tokens of a particular color
 * inputs:
 * 	unsigned int pattern
 *	unsigned int color
 * return value:
 *	unsigned int -- number of tokens
 */
unsigned int num_of_color(unsigned int pattern, unsigned int color)
{
	int counter = 0;
	for (int i=0; i <=4; i++)
	{
		if (extract_digit(pattern,i) == color)
		{
			counter = counter + 1;
		}
	}
	return counter;
}

/* count_exact_matches
 * counts the number of exact matches between guess and solution
 * inputs:
 *	unsigned int guess
 *	unsigned int solution
 * return value:
 *	unsigned int - the number of matches
 */	
unsigned int count_exact_matches(unsigned int guess, unsigned int solution)
{
	int counter = 0;
	for (int i=0; i <4; i++)
	{
		if (extract_digit(guess,i) == extract_digit(solution,i))
			{
				counter = counter + 1;
			}
	}
	return counter;
}

/* count_color_matches
 * count the number of matches of color only
 * inputs:
 *	unsigned int guess
 *	unsigned int solution
 * return value:
 *	unsigned int - the number of matches
 */
unsigned int count_color_matches(unsigned int guess, unsigned int solution)
{
	int counter = 0;
	for (int i = 1; i < 7; i ++)
	{
		if ( num_of_color(guess,i) < num_of_color(solution,i))
		{
			counter = counter + num_of_color(guess,i);
		}
		else
		{
			counter = counter + num_of_color(solution,i); 
		}
	}
	return counter;
}
/* get_guess_feedback
 * returns exact matches and leftover color matches
 * inputs:
 * 	unsigned int guess
 *	unsigned int solution
 * return value:
 * 	unsigned int - value of matches
 */
unsigned int get_guess_feedback(unsigned int guess, unsigned int solution)
{   
	if ( ((guess/1000) >=  1) & ( (guess/1000) < 10))
	{
		for (int i = 0; i < 4; i++)
		{
			if (extract_digit (guess, i) > 6)
				{
					return 100;
				}
		}
		return (10* count_exact_matches(guess,solution))+ 
count_color_matches(guess,solution) - count_exact_matches(guess,solution);
	}
	return 100;
}

/* test_extract_digit
 * tests the extract digit function
 * inputs: 
 *	unsigned  int pattern
 *	unsigned int digit
 * 	unsinged int expected
 * return value:
 *	prints success or failure
 */

void test_extract_digit(unsigned int pattern, unsigned int digit, unsigned int expected)
{
	int result = extract_digit(pattern, digit);
	if (result == expected)
	{
		printf("extract_digit(%d, %d) = %d. Success\n", 
pattern, digit, result);
	}
	else
	{
		printf("extract_digit(%d,%d) = %d. Failure, expected %d\n",
 pattern, digit, result, expected);
	}
}

/* test_num_of_color
 * tests the num of color function
 * inputs:
 *	unsigned int pattern
 *	unsigned int color 
 *	unsigned int expected 
 * return value:
 *	prints success or failure
 */
	
void test_num_of_color(unsigned int pattern, unsigned int color, unsigned int expected)
{
	int result = num_of_color(pattern, color);
        if (result == expected)
        {       
                printf("num_of_color(%d, %d) = %d. Success\n",
 pattern, color, result);
        }
        else
        {       
                printf("num_of_color(%d,%d) = %d. Failure, expected %d\n",
 pattern, color, result, expected);
        } 
}
/* test_count_exact_matches
 * tests the count exact matches function
 * inputs: 
 *	unsigned int guess
 *	unsinged int solution
 *	unsigned int expected
 * return value:
 *	prints success or failure
 */

void test_count_exact_matches(unsigned int guess, unsigned int solution, unsigned int expected)
{
	int result = count_exact_matches(guess, solution);
        if (result == expected)
        {       
                printf("count_exact_matches(%d, %d) = %d. Success\n",
 guess, solution, result);
        }
        else
        {       
                printf("count_exact_matches(%d,%d) = %d. Failure, expected %d\n",
 guess, solution, result, expected);
        }
}

/* test_count_color_matches
 * tests the count color match
 * inputs:
 *	unsigned int guess
 *	unsigned int solution
 *	unsigned int expected
 * return value:
 *	prints success or failure
 */
	
void test_count_color_matches(unsigned int guess, unsigned int solution, unsigned int expected)
{
	int result = count_color_matches(guess, solution);
	if (result == expected)
	{
		printf("count_color_matches(%d,%d) = %d. Success\n", 
guess, solution, result);
        }
        else
        {
                printf("count_color_matches(%d,%d) = %d. Failure, expected %d\n",
 guess, solution, result, expected);
        }

}
/* test_get_guess_feedback
 * tests the get guess feedback function
 * inputs:
 *	unsigned int guess
 * 	unsigned int solution
 *	unsigned int expected
 * return value:
 *	prints success or failure
 */
void test_get_guess_feedback(unsigned int guess, unsigned int solution, unsigned int expected)
{
	int result = get_guess_feedback(guess, solution);
        if (result == expected)
        {
                printf("get_guess_feedback(%d,%d) = %d. Success\n",
 guess, solution, result);
        }
        else
        {
                printf("get_guess_feedback(%d,%d) = %d. Failure, expected %d\n"
, guess, solution, result, expected);
        }
}

/* test_mastermind
 * This is the test function that has 3+ good test cases for this function in your
 * mastermind program. This verifies that the bits are working so that if you find a 
 * bug you can more easily localize it.
 * inputs:
 *   none. Tests are hard coded.
 * outputs:
 *   none. Test results are printed out.
 */
void test_mastermind()
{
	// test cases for extract_digit
	test_extract_digit(3413,2,4);
	test_num_of_color(3413,1,1);
	test_num_of_color(3413,2,0);
	test_num_of_color(3413,2,0);
	test_num_of_color(3413,1,1);
	test_count_exact_matches(3413,2315,1);
	test_count_exact_matches(3413,3455,2);
	test_count_exact_matches(3413,5555,0);
	test_count_exact_matches(3413,4331,0);
	test_count_exact_matches(3413,3415,3);
	test_count_exact_matches(3413,3413,4);
	test_count_color_matches(3413,2315,2);
	test_count_color_matches(2315,3413,2);
	test_count_color_matches(3331,2331,3);
	test_count_color_matches(6543,3456,4);
	test_count_color_matches(6543,1122,0);
	test_get_guess_feedback(3413,2315,11);
	test_get_guess_feedback(3312,3312,40);
	test_get_guess_feedback(1234,4123,4);
	test_get_guess_feedback(1219,1999,0);
	test_get_guess_feedback(21212,1233,0);
	test_count_color_matches(2263,2200,2);
	test_get_guess_feedback(2263,2200,20);			
} 

/* print_mastermind_instructions
 * This prints out user instructions to play mastermind.
 * inputs:
 *   none
 * outputs:
 *   none. Insructions are printed to screen.
 */
void print_mastermind_instructions()
{
	printf("Welcome to mastermind. I am thinking of a 4-number\n");
	printf("sequence. All four numbers are between 1 and 6.\n");
	printf("You have 12 guesses to guess it correctly.\n");
	printf("Each time you guess, I'll tell two things.\n");
	printf("1. How many numbers are correct and in the correct position.\n");
	printf("2. How many other numbers are correct but in the wrong position.\n");
	printf("Let's get started!!!\n");
}

/* get_new_code
 * Generates a 4-digit number, with each digit a number from 1 to 6, inclusive.
 * inputs:
 *   none
 * outputs:
 *   unsigned int - 4-digit number with each digit from 1 to 6
 */
unsigned int get_new_code()
{
	int i;
	int result = 0;
	for (i = 0; i < 4; i++)
	{
		result = result * 10;
		result = result + ((rand() % 6) + 1);
	}
	return result;
}


/* play_mastermind
 * This is the game loop to play mastermind. All print statements are provided so that you 
 * have consistent messages for grading purposes. An example of how to do error checking is 
 * provided so you can model that.
 * inputs:
 *  none. Users play interactively
 * outputs:
 *  none. Everything is printed.
 */
void play_mastermind()
{

	unsigned int guess_num = 0;
	unsigned int solution = 0;
	unsigned int guess = 1;
	unsigned int feedback = 0;

	print_mastermind_instructions();
	solution = get_new_code();
	printf("solution: %u\n",solution);
	while (guess_num <= 12)
	{

		printf("Guess %d - ",guess_num);
		printf("Input your 4-digit guess: ");
		scanf("%u",&guess);
		
		
		unsigned int exact_matches = count_exact_matches( guess, solution);
		feedback = get_guess_feedback(guess,solution);
		
		while (feedback == 100)
		{
			printf("%u is an invalid guess. Make sure your guess is a 4-digit number, each digit between 1-6.\n",guess);
			printf("Try Again.Guess %d - ",guess_num);
                	printf("Input your 4-digit guess: ");
                	scanf("%u",&guess);
			feedback = get_guess_feedback (guess, solution);
		}

		guess_num += 1;
	
		// report the feedback
		
		printf("Feedback: %u correct placement, correct color,\n",
		(feedback / 10));
		printf("%u incorrect placement, correct color\n",
		feedback % 10);
		
	


		// if correct, print out congrats and return from this function.
		if (exact_matches == 4)
		{
			printf("Congratulations! Your guess of %u was correct!\n"
,guess);
			return;
		}
		else
		{
		// TODO: if incorrect, print out number of guesses left
		// if incorrect
			printf("Not quite - you still have %u guesses left!\n"
,(13 -guess_num));
		}
	}

	// only print this out if they ran out of guesses didn't win.
	printf("Sorry, you did not guess it! The solution was %u\n",solution);
	return;
}

