#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "memory.h"
#include "hw7.h"
//FINAL

int main(int argc, char *argv[])
{
	// make sure there are two arguments - hw5 and filename
	if (argc < 2)
	{
		printf("Usage: ./hw7 filename. Missing filename\n");
		exit(1);
	}
	char *filename = argv[1];



	bst  *out =read_memory_blocks("bsttest.txt",memory_size_cmp);
	memory *mem= memory_new(8,500);
	memory *mem1 = memory_new(18,500);
	memory *mem2 = memory_new(28,700);
	memory *delete = memory_new(4,2);
	memory *delete2 = memory_new(9,100);
	printf("TESTING INSERT\n" );
	bst_insert(out,mem);
	bst_inorder_traversal(out,memory_print);
	printf("\n" );

	bst_insert(out,mem1);
	bst_inorder_traversal(out,memory_print);
	printf("\n" );

	bst_insert(out,mem2);
	bst_inorder_traversal(out,memory_print);
	printf("\n" );

  printf("TESTING DELETE\n" );

	bst_delete(out,mem);
	bst_inorder_traversal(out,memory_print);
	printf("\n" );

	bst_delete(out,delete);
	bst_inorder_traversal(out,memory_print);
	printf("\n" );

	bst_delete(out,delete2);
	bst_inorder_traversal(out,memory_print);
	printf("\n" );

	printf("TESTING SEARCH\n" );
	memory *search = memory_new(2,50);
	node *n = bst_search(out,search);
	if (memory_addr_cmp(n->data,search)== 0)
	{
		printf("SUCCESS\n" );
	}


	printf("FREE NODE\n" );
	bst_free(out);




}

























	//read_memory_blocks(filename,memory_addr_cmp);




	// open file for reading
