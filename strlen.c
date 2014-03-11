int strlen(const char* str)
{
	assert(str != NULL);
	if(*str++ != '\0')
		return 1 + strlen(str);
	return 0;
}
