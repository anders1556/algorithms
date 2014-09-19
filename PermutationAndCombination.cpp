void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a =  *b;
	*b = temp;
}

void permutation(int list[], int start, int end)
{
	if(start > end)//此时已经完成排列,打印出来
	{
		for(int i=0; i<=end; i++)
			printf("%d ", list[i]);
		printf("\n");
		count++;
	}
	else{
		for(int i=start; i<=end; i++)
		{
			swap(&list[start],&list[i]);
			permutation(list,start+1,end);
			swap(&list[start],&list[i]);
		}
	}
}

void combine(int list[], int n, int m, int storage[], const int M)
{
	for(int i=n; i>=m; i--)//从n个元素中选取m个
	{
		storage[m-1] = i-1;
		if(m > 1)
			combine(list,i-1, m-1, storage, M);
		else{//m == 1,输出一个组合
			for(int j=M-1; j>=0; j--)
				printf("%d ",list[storage[j]]);
			printf("\n");
		}
	}
}
