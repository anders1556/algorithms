package sort;

public class SelectSort {
	public void selectSort(double[] sorted){
		int length = sorted.length;
		
		for(int i=0; i<length; ++i){
			int position = i;
			double temp = sorted[i];
			
			for(int j=i+1; j<length; ++j){
				if(sorted[j] < temp){
					temp = sorted[j];
					position = j;
				}
			}//end for
			
			sorted[position] =sorted[i];
			sorted[i] = temp ;
		}//end for
	}
}
