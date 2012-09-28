/*
**问题： 
**	一个大小为n的数组，里面的数都属于范围[0, n-1]，有不确定的重复元素，
** 找到至少一个重复元素，要求O(1)空间和O(n)时间。
**
**思路：
**	申请一个与原数组一样大小的新数组。然后遍历原数组，获得每一项的值，然后将值作为下标，找到其在
**  新数组中的位置，如果该位置上没有数据,则插入到该值中，如果有且相等，即该值有重复，那么就返回该值。
**
**示例：
**  数组A[2,3,3]，因为A[0]=2，就将其放入到新数组B的第二个位置中，即B[1]中，将A[1]=3放入到B[2]中，A[2]=3
**  也放到B[2]中,但此时B[2]中已经有了一样的值, 所以3是重复的，输出即可。
**
**算法分析：
**  空间：因为只需要分配一个新的数组，所以空间复杂度为O(n)
**  时间：因为只需要一个for循环遍历，且最多只有n此，也满足题目要求
**
**Author:ToExplore
**History:2012-9-28
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_duplicate(int *array,int n)
{
	//we create a new array,the size is same with the old one.
	int *new_array;
	new_array = (int*)malloc(n*sizeof(int));
	if (!new_array)	
		return -1;    //memory allocated failure
	memset(new_array,0,n*sizeof(int));
		
	//then,we loop the old array,take each item into the new array.
	for (int i = 0; i < n+1;i++)
	{
		if (array[i] == new_array[array[i]])
			return array[i];			
		else		
			new_array[array[i]] = array[i];			
	}
	free(new_array);
	return -2;   //no duplicate
}

int main()
{
	//initialize test data
	int array[10] ={1,2,5,8,5,5,9,3,7,6};

	int item = find_duplicate(array,10);
	if (item == -1)
	{
		printf("failed");
		return -1;
	}
	if (item == -2)
	{
		printf("There is no duplicate value");
		return -2;
	}
	printf("the item %d has duplicate value",item);
}
	