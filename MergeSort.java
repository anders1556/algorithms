package sort;

public class MergeSort {
	public void mergeInner(double[] sorted, int low, int mid, int high){
		double[] temp = new double[sorted.length];
				
		int indexA = low;
		int indexB = mid+1;
		int index = low;
		
		while(indexA<mid+1 && indexB<high+1){
			if(sorted[indexA] - sorted[indexB] <= 0.000001){
				 temp[index++] = sorted[indexA++];
			}else{
				temp[index++] =sorted[indexB++];
			}	
		}//end while
		
		while(indexA < mid+1){
			temp[index++] = sorted[indexA++];
		}//end while
		
		while(indexB < high+1){
			temp[index++] = sorted[indexB++];
		}//end while
		
		index = low;
		while(index < high+1){
			sorted[index] = temp[index];
			index ++ ;
		}
	}
	
	public void mergeSort(double[] sorted, int low, int high){
		if(low < high){
			int median = (low + high) / 2 ;
			mergeSort(sorted, low, median);
			mergeSort(sorted, median+1, high);
			mergeInner(sorted, low, median, high);
		}
	}
}
