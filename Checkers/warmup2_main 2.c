#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assign.h"  // note this new include file!!!

// TODO: Write a test function for each exercise

/* Principle 2: Design a good set of test cases
 * they check the base case (0), right above the base case (1), well
 * above the base case (5, 8), and error conditions (-1, -5).
 * -1, 0, 1 are the boundary test cases - base, base+1, base-1.
 */
int main()
{

	// I am only putting one line in for each to make sure it compiles
	// you need to write your own test code

	// TODO: Write 3+ good test cases. 
	// TODO: Replace these calls with call to test function
	// Test case 1 Drawing an hourglass iteratively
	printf("drawing letter S \n");
	print_asterisk_letter('S');
	printf("drawing letter T \n"); 
	print_asterisk_letter('T');
	printf("drawing letter U \n"); 
	print_asterisk_letter('U');
	printf("drawing letter V \n"); 
	print_asterisk_letter('V');
	printf("\n");
	printf("drawing an hourglass recursively  size 0 \n");
	printf("\n");
	draw_hourglass_rec(0);
	printf("\n");
	printf("drawing an hourglass recursively size 1 \n");
	printf("\n");
	draw_hourglass_rec(1);
	printf("\n");
	printf("draw an hourglass recursively  of size 2 \n");
	printf("\n");
	draw_hourglass_rec(2);
	printf("\n");
	printf("draw and hourglass recursively of size 3 \n");
	printf("\n");
	draw_hourglass_rec(3);
	printf("\n");
	printf("draw an hourglass recursively of size 7 \n");
	printf("\n");
	draw_hourglass_rec(7);
	printf("\n");
	printf("draw an hourglass recursively of size 12 \n");
	printf("\n");
	draw_hourglass_rec(12);
	printf("\n");
	printf("drawing an hourglass iteratively \n");
	printf("\n");
	draw_hourglass_iter(0);
	printf("\n");
	printf("drawing an hourglass iteratively of size 1 \n");
	printf("\n");
	draw_hourglass_iter(1);
	printf("\n");
	printf("drawing an hourglass iteratively of size 2 \n");
	printf("\n");
	draw_hourglass_iter(2);
	printf("\n");
	printf("drawing an hourglass iteratively of size 3 \n");
	printf("\n");
	draw_hourglass_iter(3);
	printf("\n");
	printf("drawing an hourglass iteratively of size 7 \n");
	printf("\n");
	draw_hourglass_iter(7);
	printf("\n");
	printf("drawing an hourglass iteratively of size 12 \n");
	printf("\n");
	draw_hourglass_iter(11);  

}

