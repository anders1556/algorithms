/*using do-while in an art way*/

#define  N 10
bool excute()
{
  //allocating resouse
  int *p = (int *) malloc(N * sizeof(int) );
  bool bok = true;
  
  do{
    bok = func1();
    if(!bok) break;
    
    bok = func2();
    if(!bok) break;
    
    //..........
  }while(0);
  
  free(*p);
  p = NULL;
  return bok;
}
