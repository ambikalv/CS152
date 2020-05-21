#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
//FINAL

/* malloc a new node and assign the data
 * pointer to its data field
 */
node* node_new(void* data){
  //TODO
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right =NULL;
  return new_node;

}

/* create a new bst, initialize its root to be NULL
 */
bst* bst_new(int (*cmp)(const void* x, const void* y)){
  //TODO
  bst *new_bst = (bst*) malloc(sizeof(bst));
  new_bst->root = NULL;
  new_bst->cmp = cmp;
  return new_bst;
}

/* Insert a node to to a subtree with a root node as parameter
 * Insertion is in sorted order.
 * Return the new root of the modified subtree.
 */
node* node_insert(node* root, void* data,
    int (*cmp)(const void* x, const void* y)){
  //TODO


  if (root == NULL)
  {
    return node_new(data);
  }

  int c = cmp(data, root->data);// if data is bigger

  if (c == 1)
  {

    root->right = node_insert(root->right,data,cmp);

  }
  else if (c == -1)
  {
    root->left = node_insert(root->left,data,cmp);

  }

return root;

}

/* Insert a new node to the bst
 */
void bst_insert(bst* b, void* data){

  b->root = node_insert(b->root, data, b->cmp);

}

node* left_most_child(node *root)
{
  node* tmp = root;

  while ((tmp->left !=NULL) & (tmp != NULL))
  {
    tmp = tmp->left;
  }

  return tmp;
}
/* delete a node from a subtree with a given root node
 * use the comparison function to search the node and delete
 * it when a matching node is found. This function only
 * deletes the first occurrence of the node, i.e, if multiple
 * nodes contain the data we are looking for, only the first node
 * we found is deleted.
 * Return the new root node after deletion.
 */
node* node_delete(node* root, void* data,
    int (*cmp)(const void* x, const void* y)){
  //free the left most child of the right subtree and swap values with the thing being deleted


  if (root == NULL)
  {
    return root;
  }

  int c = cmp(data, root->data);// if data is bigger

  if (c== -1)
  {
    root->left = node_delete(root->left,data,cmp);
  }
  else if (c == 1)
  {
    root->right = node_delete(root->right, data,cmp);
  }
  else if (c==0)
  {
    if (root->left == NULL)
    {
      free(root);
      return root->right;
    }
    else if (root->right == NULL)
    {
      free(root);
      return root->left;
    }
    node* tmp = left_most_child(root->right);
    root->data = tmp->data;
    root->right = node_delete(root->right, tmp->data,cmp);
  }




  return root;
}

/* delete a node containing data from the bst
 */
void bst_delete(bst* b, void* data){
   node_delete(b->root,data,b->cmp);
}

/* Search for a node containing data in a subtree with
 * a given root node. Use recursion to search that node.
 * Return the first occurrence of node.
 */
void* node_search(node* root, void* data,
    int (*cmp)(const void* x, const void* y)){



      int c = cmp(data, root->data);// if data is bigger

      if ((c == 0) || (root == NULL))
      {
        return root;
      }

      if (c == 1)
      {

        return node_search(root->right,data,cmp);

      }
      else
      {
        return node_search(root->left,data,cmp);

      }



    }

/* Search a node with data in a bst.
 */
void* bst_search(bst* b, void* data){
  return node_search(b->root,data,b->cmp);

}

/* traverse a subtree with root in ascending order.
 * Apply func to the data of each node.
 */
void inorder_traversal(node* root, void(*func)(void* data)){
  // go to the left most root then parent then right most
  if (root == NULL)
  {
    return;
  }
  inorder_traversal(root->left, func);
  func(root->data);
  inorder_traversal(root->right,func);

}

/* traverse a bst in ascending order.
 * Apply func to the data of each node.
 */
void bst_inorder_traversal(bst* b, void(*func)(void* data)){
  inorder_traversal(b->root,func);
}

void node_free(node* node)
{
  if (node == NULL)
  {
    return;
  }
  node_free(node->left);
  node_free(node->right);
  free(node);
}
/* free the bst with
 */
void bst_free(bst* b){

  node_free(b->root);
  printf("FREE\n" );
}
