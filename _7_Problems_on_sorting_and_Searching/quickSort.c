int partision(int * arr,int low,int high)
{
	int i = low+1;
	int j = high;
	int tmp;
	int pivot = arr[low];
	while(i<=j)
	{
		while(arr[i]<=pivot)
			i++;
		while(arr[j]>pivot)
			j--;
		if(i<j)
		{
			tmp = arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
		}
	}
	tmp = arr[j];
	arr[j] = arr[low];
	arr[low] = tmp;
	return j;
}

void QuickSort(int * arr, int low,int high)
{
	if(low<high)
	{
		int k = partision(arr,low,high);
		QuickSort(arr,low,k-1);
		QuickSort(arr,k+1,high);
	}
}

