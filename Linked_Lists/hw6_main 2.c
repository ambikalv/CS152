#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6.h"

int main(int argc, char *argv[])
{
	// make sure there are two arguments - hw5 and filename
	if (argc < 2)
	{
		printf("Usage: ./hw6 filename. Missing filename\n");
		exit(1);
	}
	char *filename = argv[1];

	// open file for reading
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file %s for reading\n",filename);
		exit(2);
	}

	//making a new product list
	node *helloworld = NULL;

	// read in each record from the file
	char buffer[BUFSIZ];
	while (!feof(fp) && (fgets(buffer,500,fp) != NULL))
	{
		// parse the line to split up the fields
		char *category;
		char *name;
		uint pID;
		uint current_stock;
		uint min_stock;
		uint max_stock;
		char *tmp_s;

		// first field is category
		category = strtok(buffer," ,\n\r");
		// second field is name
		name = strtok(NULL," ,\n\r");
		// third is pID;
		tmp_s = strtok(NULL," ,\n\r");
		pID = atoi(tmp_s);
		// fourth is current
		tmp_s = strtok(NULL," ,\n\r");
		current_stock = atoi(tmp_s);
		// fifth is min
		tmp_s = strtok(NULL," ,\n\r");
		min_stock = atoi(tmp_s);
		// sixth is max
		tmp_s = strtok(NULL," ,\n\r");
		max_stock = atoi(tmp_s);

		printf("Read in record: %s, %s, %u, %u, %u, %u\n",
			category, name, pID, current_stock, min_stock,
			max_stock);
		product_info *new_product;

		new_product = create_product(name, category, pID, current_stock,min_stock, max_stock);

		helloworld = insert_head(helloworld, new_product);

	}

//Testing find
printf("%s\n", "Testing find" );
if(find(helloworld,2956) != NULL)
{
	print_product(find(helloworld, 2956),stdout);
}
printf("\n ");
if(find(helloworld,8261) != NULL)
{
	print_product(find(helloworld, 8261),stdout);
}
printf("\n ");
if(find(helloworld,82699) != NULL)
{
	print_product(find(helloworld, 826199),stdout);
}
else
{
	printf("%s\n", "This Id does not exist");
}
//Testing record_restocked_single
printf("%s\n", "Testing record_restocked_single" );
test_restock_single(helloworld, 2956);
printf("\n ");
test_restock_single(helloworld,8261);
printf("\n ");
test_restock_single(helloworld,3826);
printf("\n ");

printf("%s\n", "Testing product_sold" );
test_product_sold(helloworld, 2956);
printf("\n ");
test_product_sold(helloworld,8261);
printf("\n ");
test_product_sold(helloworld,3826);
printf("\n ");

product_info *baby_yoda_plushie = create_product("baby yoda plushie", "Office", 50000, 24,40, 80);

printf("%s\n","TESTING ADD SORTED" );
add_sorted_productID(baby_yoda_plushie, helloworld);
print_list(helloworld,stdout);
printf("%s\n","TESTING ADD SORTED CATEGORY" );
add_sorted_category_ID(baby_yoda_plushie,helloworld);
print_list(helloworld,stdout);
printf("%s\n","TESTING RESTOCK" );
make_restock_list(helloworld);
print_list(make_restock_list(helloworld),stdout);
printf("%s\n","TESTING RECORD RESTOCK" );
record_restocked_list(make_restock_list(helloworld),helloworld);
print_list(helloworld,stdout);




















}
