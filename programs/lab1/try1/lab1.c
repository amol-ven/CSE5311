#include <stdio.h>
#include <stdlib.h>

#include <treaps.h>

#define SIZEOF(z) sizeof(z)/sizeof(z[0])

extern node_t *ROOT_MAIN;

extern int closest1x, closest2x, closest1y, closest2y;
extern int max_nodes_count, current_nodes_count;
extern int rotations_left_count, rotations_right_count;

typedef struct point
{
	int x;
	int y;
}point_t;


int main(void)
{
	point_t data[] = {	
						//x=heap, y=tree
						{.x = 0, .y = 1},
						{.x = 0, .y = 5},
						{.x = 1, .y = 1},
						{.x = 1, .y = 2},
						{.x = 2, .y = 3}, 
					};
	int Dmin_sq = 0x7FFFFFFF;        //max integer
	
	
	int i;
	node_t *disp_array[50];
	for(i=0; i<SIZEOF(disp_array); i++)
	{
		disp_array[i] = NULL;
	}
	
	ROOT_MAIN = NULL;
	node_t *new=NULL;
	
	
	
	
	for(i=0; i<SIZEOF(data); i++)
	{
		new = createNode(data[i].x, data[i].y);
		if(!new)
		{
			printf("cannot create node");
			exit(1);
		}
		if(ROOT_MAIN==NULL)
		{
			//only first pass comes here
			//ROOT_ = new;
			ROOT_MAIN = new;
			continue;
		}
		else
		{
			attachLeaf(new, ROOT_MAIN);
		}
		
		checkForRemovals(ROOT_MAIN, new, &Dmin_sq);
		node_t *ret;
		do
		{
			ret = removeNodes(ROOT_MAIN);
			if(ret)
			{
				deleteNode(ret, 1);
			}
		}
		while(ret);
		
		
		
		printf("\n\n");
	}
	
	
	treeToArray(disp_array, ROOT_MAIN, 1, SIZEOF(disp_array));
	dispTreeArray(disp_array, SIZEOF(disp_array));
	printf("\n\n----------------------------------\n\n");
	printf("Left Rotations: %d\n", rotations_left_count);
	printf("Right Rotations: %d\n", rotations_right_count);
	printf("Max Nodes: %d\n", max_nodes_count);
	printf("Current Nodes: %d\n", current_nodes_count);
	return 0;
}
