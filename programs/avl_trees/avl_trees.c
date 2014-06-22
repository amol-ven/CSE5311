#include <stdio.h>
#include <stdlib.h>

#include <tree.h>

#define SIZEOF(x) sizeof(x)/sizeof(x[0])

extern node_t *ROOT_MAIN;

int main(void)
{
	int i;
	int data[] = {2, 1, 3,6, 8};
	
	node_t *disp_array[50];
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
			ROOT_MAIN = ROOT;
		}
		else
		{
			attachLeaf(new, ROOT);
		}
		printf("\n\n");
	}
	
	treeToArray(disp_array, ROOT_MAIN, 1, SIZEOF(disp_array));
	dispTreeArray(disp_array, SIZEOF(disp_array));
	printf("\n\n");
	
	/*rotate(ROOT, LEFT);
	ROOT = ROOT->parent;
	for(i=0; i<SIZEOF(disp_array); i++)
	{
		disp_array[i] = NULL;
	}
	treeToArray(disp_array, ROOT, 1, SIZEOF(disp_array));
	dispTreeArray(disp_array, SIZEOF(disp_array));
	*/
	printf("\n\n%d\n", (ROOT_MAIN)->height);
	return 0;
}
