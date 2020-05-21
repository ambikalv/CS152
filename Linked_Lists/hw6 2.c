#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6.h"


char *category_strings[] = { "Grocery", "Office", "Pharmacy", "Hobby"};

void print_product(product_info *p, FILE *fp)
{
	fprintf(fp,"%s (%u) %s:",p->name, p->productID,
		category_strings[p->category]);
	fprintf(fp, "current: %u, min: %u, max: %u",
		p->current_stock, p->min_for_restock, p->max_after_restock);
}

void print_list(node *head, FILE *fp)
{
	node *tmp;
	printf("Product Status:\n");
	for(tmp = head; tmp != NULL; tmp = tmp->next)
	{
		print_product(tmp->product,fp);
		printf("\n");
	}
}


/*
 *product_info
 *Allocates memory and fills in the fields for a productID
 *inputs:
 *  char *name
 *  char *category
 *  uint id
 *  uint current
 *  uint min
 *  uint mx
 *returns:
 *  *product a pointer to productID
*/
product_info *create_product(char *name, char *category, uint id,
				uint current, uint mn, uint mx)
        {
            product_info *product = (product_info *)malloc(sizeof(product_info));
            if (strlen(name) <= 40)
            {
              strcpy(product->name,name);
            }


            product->productID = id;
            product->current_stock = current;
            product->min_for_restock= mn;
            product->max_after_restock= mx;




            for( int i = 0 ; i < 4; i ++)
            {
              if (strcmp(category_strings[i], category)== 0)
              {
                product->category = GROCERY;
              }
              else if (strcmp(category_strings[i],category)== 1)
              {
                product->category = OFFICE;
              }
              else if (strcmp(category_strings[i],category)== 2)
              {
                product->category = PHARMACY;
              }
              else if (strcmp(category_strings[i],category)== 2)
              {
                product->category = HOBBY;
              }
            }



            return product;

        }



/*
 *insert_head
 *inserts a head node to a linked list
 *inputs:
 *  node *head -- a pointer to the head _node
 *  product_info *pinfo -- a pointer to a product_info item
 *returns:
 *  tmp -- a pointer to the modified linked list
 */
node* insert_head(node *head, product_info *pinfo)
{
  node *tmp;
  tmp = malloc(sizeof(node));
  tmp -> product = pinfo;
  tmp -> next = head;
  return tmp;

}


/*
 *find
 *finds the product with a given id
 *inputs:
 *  node *head -- a pointer to the head _node
 *  uint pID -- the product ID
 * returns:
 *  a pointer to the node with the given id
*/
product_info *find(node *head, uint pID)
{
  node *cur_node = head;
  while (cur_node != NULL)
  {
    if (cur_node->product->productID == pID)
    {
      return cur_node-> product;
    }
    cur_node = cur_node -> next;
  }
  return NULL;
}


/*
 *record_restocked_single
 *sets the current stock of a product to the max after restock
 *inputs:
 *  node *head -- a pointer to the head _node
 *  uint pID -- the product ID
 * returns:
 *  void
*/
void record_restocked_single(node *head, uint pID)
{
  if(find(head,pID) == NULL)
  {
    fprintf(stderr,"ERROR: pID not found\n");

  }
  node *cur_node = head;
  while (cur_node != NULL)
  {
    if (cur_node->product->productID == pID)
    {
      cur_node->product->current_stock = cur_node->product->max_after_restock;
      return;
    }
      cur_node = cur_node -> next;
  }

}


/*
 *product_sold
 *sets the current stock of a product to one minus current
 *inputs:
 *  node *head -- a pointer to the head _node
 *  uint pID -- the product ID
 * returns:
 *  void
*/
void product_sold(node *head, uint pID)
{
  node *cur_node = head;
  while (cur_node != NULL)
  {
    if (cur_node->product->productID == pID)
    {
      cur_node->product->current_stock -=1;
    }
    cur_node = cur_node -> next;
  }

}


/*
 *add_sorted_productID
 *inserts a product based on ascending order of product ID
 *inputs:
 *  node *head -- a pointer to the head _node
 *  uint pID -- the product ID
 * returns:
 *  a pointer to the list of products
*/
node *add_sorted_productID(product_info *pinfo, node *head)
{
  node *tmp;
  if((head == NULL) || (head->product->productID < pinfo->productID))
  {
    head = insert_head(head, pinfo);
  }
  else
  {


    for(tmp = head; tmp!= NULL; tmp = tmp->next)
    {
      if(tmp->next->product->productID < pinfo->productID)
      {
        break;
      }
    }
    printf("%u\n", pinfo ->productID);
    printf("%u\n",tmp->next->product->productID );
    node *newnode;
    newnode = malloc(sizeof(node));
    newnode->product = pinfo;
    newnode->next = tmp->next;
    tmp->next = newnode;


  }
  return head;
}

/*
 *add_sorted_productID
 *inserts a product based on ascending order of category and then product id
 *inputs:
 *  node *head -- a pointer to the head _node
 *  uint pID -- the product ID
 * returns:
 *  a pointer to the list of products
*/
node *add_sorted_category_ID(product_info *pinfo, node *head)
{
  node *tmp;
  if((head == NULL) || (head->product->productID < pinfo->productID))
  {
    head = insert_head(head, pinfo);
  }
  else
  {


    for(tmp = head; tmp->next!= NULL; tmp = tmp->next)
    {
      if(tmp->next->product->category < pinfo->category)
      {
        break;
      }
    }

    printf("%u\n", pinfo ->productID);
    node *newnode;
    newnode = malloc(sizeof(node));
    newnode->product = pinfo;
    newnode->next = tmp->next;
    tmp->next = newnode;


  }
  return head;
}

/*
make_restock_list
goes through the list and finds items to be restocked
inputs:
  node *head pointer to the head of a list
returns:
  a pointer to a list of products to be restocked
*/
node *make_restock_list(node *head)
{
  node *new_list = NULL;
  node *tmp;
  for(tmp = head; tmp->next!= NULL; tmp = tmp->next)
  {
    if (tmp->product->current_stock < tmp->product->min_for_restock)
    {

      new_list= insert_head(new_list, tmp->product);
    }
  }
  return new_list;
}




/*
updates restocked items
inputs:
  node *head pointer to the head of a list
returns:
  a pointer to a list of products to be restocked
*/
void record_restocked_list(node *restocked_list, node *head)
{
  node *tmp;
  for( tmp = restocked_list; tmp != NULL; tmp = tmp->next)
  {
    record_restocked_single(head, tmp->product->productID);
  }
}


void test_restock_single(node *head, uint pID)
{
	record_restocked_single(head,pID);
  uint curstock = find(head, pID)->current_stock;
  uint maxstock = find(head, pID)->max_after_restock;
        if (curstock == maxstock)
        {
                printf( "Success\n");
                print_product(find(head,pID),stdout);
        }
        else
        {
          printf( "Failure\n");
          print_product(find(head,pID),stdout);
        }
}

void test_product_sold(node *head, uint pID)
{
  uint prevstock = find(head, pID)->current_stock;
	product_sold(head,pID);
  uint curstock = find(head, pID)->current_stock;

        if (prevstock - curstock == 1)
        {
                printf( "Success\n");
                print_product(find(head,pID),stdout);
        }
        else
        {
          printf( "Failure\n");
          print_product(find(head,pID),stdout);
        }
}
