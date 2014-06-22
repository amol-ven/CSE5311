#ifndef _TREE_H
#define _TREE_H

#define LEFT 1
#define RIGHT 2

#define MAX(x,y) (x<y)?(y):(x)

#define RETURN_HEIGHT_IF_NODE_EXISTS(x) (x==NULL)?0:x->height

typedef struct node
{
	struct node *parent;
	struct node *childL, *childR;
	int key;
	//int balance;						//balance = right-left
	int height;
}node_t;


void treeToArray(node_t **arr, node_t *root, int offset, int max_array_length);
//node_t *createNode(node_t *parent, node_t *childL, node_t *childR, int key);
node_t *createNode(int key);
int rotate(node_t *root, int direction);
void dispTreeArray(/*node_t *root, */node_t **array,int max_array_length);

int attachLeaf(node_t *new, node_t *root);











#endif