#include <stdio.h>
#include <stdlib.h>

#include <tree.h>

#define SIZEOF(x) sizeof(x)/sizeof(x[0])

int main(void)
{
	int i;
	int data[] = {1, 2, 4, 3, 8, 4, 0, 30, 9 ,78, 54, 32, 12};
	
	node_t *disp_array[20];
	for(i=0; i<SIZEOF(disp_array); i++)
	{
		disp_array[i] = NULL;
	}
	
	node_t *new=NULL, *ROOT=NULL;
	
	for(i=0; i<SIZEOF(data); i++)
	{
		new = createNode(data[i]);
		if(!new)
		{
			printf("cannot create node");
			exit(1);
		}
		if(ROOT==NULL)
		{
			//only first pass comes here
			ROOT = new;
		}
		else
		{
			attachLeaf(new, ROOT);
		}
		
	}
	
	treeToArray(disp_array, ROOT, 1, SIZEOF(disp_array));
	dispTreeArray(disp_array, SIZEOF(disp_array));
	printf("\n\n");
	
	rotate(ROOT, LEFT);
	ROOT = ROOT->parent;
	for(i=0; i<SIZEOF(disp_array); i++)
	{
		disp_array[i] = NULL;
	}
	treeToArray(disp_array, ROOT, 1, SIZEOF(disp_array));
	dispTreeArray(disp_array, SIZEOF(disp_array));
	return 0;
}
