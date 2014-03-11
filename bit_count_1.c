int bit_count_1(int n)
{
	assert(n > 0);
	int result = 0;
	int num = n;
	for(;num;num&=num-1,++result);
	return result;
}
