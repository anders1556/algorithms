void hanoi(char start, char helper, char end, int n)
{
	if(n == 1)//when n=1, just move straightly
	{
		std::cout << start << "->" << end << std:endl;
		return;
	}

	hanoi(start, end, helper, n-1);//move n-1 layer to helper
	std::cout << start << "->" << end << std::endl;//move the nth layer to terminal 
	hanoi(helper, start, end, n-1);//move n-1 layer to terminal
}
