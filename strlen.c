int strlen(const char* str)
{
	if(*str++ != '\0')
		return 1 + strlen(str);
	return 0;
}
