package sort;

public class QuickSort {
	public int getMiddle(double[] sorted, int low, int high){
		double pivotKey = sorted[low];
		while(low < high){
		while(low<high && sorted[high]>=pivotKey)
			high -- ;
		sorted[low] = sorted[high];
		
		while(low<high && sorted[low]<=pivotKey)
			low ++ ;
		sorted[high] = sorted[low];
		}
		sorted[low] = pivotKey;
		
		return low;
	}
	
	public void quickSort(double[] sorted, int low, int high){
		if(low < high){
		int median = getMiddle(sorted, low, high);
		
		quickSort(sorted, median+1, high);
		
		quickSort(sorted, low, median-1);
		}
	}
}
