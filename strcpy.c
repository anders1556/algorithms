char * strcpy(char * Destionation , const char * Source)
{
	assert(Destionation && Source);
	char * temp = Destionation; 
 	while((*temp++ = *Source++) != '\0');
	return temp;
}
