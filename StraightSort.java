package sort;

public class StraightInsertSort {
	public void straightInsertSort(double[] sorted){
		
		int	lenght = sorted.length;
		
		for(int j=2; j<lenght; ++j){
			
			if(sorted[j] < sorted[j-1]){			
				sorted[0] = sorted[j] ;
				sorted[j] = sorted[j-1] ;
				
				int insertPos = 0 ;
				for(int k=j-2; k>=0; --k){
					if(sorted[k] > sorted[0]){
						sorted[k+1] = sorted[k] ;
					}else{
						insertPos = k+1 ;
						break;
					}
				}//end for
				sorted[insertPos] = sorted[0];						
			}//end if
		}//end for
		
	}
}
