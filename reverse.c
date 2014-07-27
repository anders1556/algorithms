void reverser (char *s, int i, int len)
{
  int c, j;//c is a temp variable for changing
  j = len - (i + 1);
  if(i < j){
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
  reverser (s, ++i, len);
}

void reverse (char *s)
{
  int len = strlen(s);
  reverser(s, 0, len);
}
