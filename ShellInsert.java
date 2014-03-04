package sort;

public class ShellInsertSort {
	
	public void shellInnerSort(double[] sorted, int inc){
		int lenght = sorted.length ;
		
		for(int j=inc+1; j<lenght; ++j){
			if(sorted[j] < sorted[j-inc]){
				sorted[0] = sorted[j] ;
				
				int insertPos = j;
				for(int k=j-inc; k>=0; k-=inc){
					if(sorted[k] > sorted[0]){
						sorted[k+inc] = sorted[k];
						
						if(k-inc <= 0)
							insertPos = k;
						
					}else{
						insertPos = k + inc ;
						break;
					}
				}//end for
				sorted[insertPos] = sorted[0];
				
			}//end if
		}//end for
	}
	
	public void shellInsertSort(double[] sorted){
		int[] incs = {7, 5, 3, 1};
		int nums =incs.length;
		
		for(int j=0; j<nums; ++j){
			shellInnerSort(sorted,incs[j]);
		}
	}
}
