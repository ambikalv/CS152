#include <stdlib.h>
#include <stdio.h>
#include "assign.h"
//FINAL VERSION!!

/* Ambika Venkatakrishnan
 * Homework 2
 */

/* print_asterisk_letter
 * input: char letter - the letter to print out
 * output: nothing returned, just printed to the screen.
 * Given a character, print the corresponding upper-case letter of the 
 * alphabet using asterisks. The letter can be anything from 'N' to 'R'. 
 */
void print_asterisk_letter(char letter)
{ 
	switch (letter)

	{
		case ('S'): printf(" ****\n");
			  printf("*    \n");
			  printf(" *** \n");
			  printf("    *\n");
		          printf("**** \n");
			  break;
		case ('T'): printf("*****\n");
                          printf("  *  \n");
                          printf("  *  \n");
                          printf("  *  \n");
                          printf("  *  \n");
			  break;
		case ('U'): printf("*   *\n");
                          printf("*   *\n");
                          printf("*   *\n");
                          printf("*   *\n");
                          printf(" *** \n");
			  break;
		case ('V'): printf("*   *\n");
                          printf("*   *\n");
                          printf("*   *\n");
                          printf(" * * \n");
                          printf("  *  \n");
         		  break;                 

	}
}
/* print_multiple_chars
 * prints multiple characters in a line recursively
 * inputs:
 *	char character
 *	unsigned int num_to_print
 * return_value:
 * 	prints characters
 */
void print_multiple_chars(char character, unsigned int num_to_print)
{
	if (num_to_print == 0)
	{
		return;
	}
	if (num_to_print == 1)
	{
		printf("%c",character);
	}
	else
	{
		printf("%c",character);
		print_multiple_chars(character, num_to_print - 1);
	}
}



/* draw_hourglass_rec_helper
 * draws a hourglass with asterisks. implemented recursively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 *   uint offset - amount of spaces that should be to the left of this hourglass
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_rec_helper(unsigned int height, unsigned int offset)
{
	if (height == 1)
	{
		print_multiple_chars(' ', offset);
		print_multiple_chars('*',1);
		return;
	}
	if ( height == 2)
	{
		print_multiple_chars(' ', offset);
		print_multiple_chars('*',1);
		printf("\n");
		print_multiple_chars(' ', offset);
                print_multiple_chars('*',1);
		return;
	}
	else
	{ 
		print_multiple_chars(' ', offset);
		print_multiple_chars('*', height);
		printf("\n");
		draw_hourglass_rec_helper(height -2, offset+1);
		printf("\n");
		print_multiple_chars(' ',offset);
		print_multiple_chars('*', height);
	}
		
}

/* draw_hourglass_rec
 * draws a hourglass with asterisks. implemented recursively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_rec(unsigned int height)
{	if (height == 0)
	{
		return;
	}
	if (height == 1)
	{
		printf("*");
		return;
	}
	if (height == 2)
	{
		printf("*\n");
		printf("*");
		return;
	}
	if (height % 2 == 0)
	{
		height = height -1;
	} 	
	print_multiple_chars('*', height);   
	printf("\n");
	draw_hourglass_rec_helper(height-2,1);
	printf("\n");
	print_multiple_chars('*', height); 
}
/* draw_hourglass_iter
 * draws a hourglass with asterisks. Implemented iteratively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_iter(unsigned int height)
{
	if( height == 0)
	{
		return;
	}
	if ((height % 2) == 0)
	{
 		for (int i = 1; i <= height; i +=2)
		{	
			for (int j =0; j<(i/2); j++)
			{				
				printf(" ");
			}
			for( int k = 0; k < height - i; k++)

			{
				printf("*");
			}
			printf("\n");
		}
	
	 	for (int  i= 1; i <= height; i+=2)
        	{
                	for (int j = (height-i)/2; j >0; j-=1)
                	{
                        	printf(" ");
                	}	
                	for (int k = 1; k<=i; k+=1)
                	{
                        	printf("*");
                	}
                	printf("\n");
        	}
	}
	else
	{	for (int i = 1; i < height; i +=2)
		{
			for (int j = 0; j < (i/2); j++)
			{
				printf(" ");
			}
			for (int k = 0; k <= height -i; k++)
			{
				printf("*");
			}
			printf("\n");
		}
		for (int i = 1; i <= height; i +=2)
		{
			for(int j = (height -i)/2; j>0; j-=1)
			{
				printf(" ");
			}
			for ( int k = 1; k <=i; k+=1)
			{
				printf("*");
			}
			printf("\n");
		}
	}


}


