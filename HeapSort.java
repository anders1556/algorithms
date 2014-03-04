package sort;

public class HeapSort {
	public void buildMaxHeap(double[] sorted, int i){
		int size = sorted.length - i;
		for(int j=size; j>1; j--){
			if(sorted[j] - sorted[j/2] >= 0.000001){
				swap(sorted,j,j/2);
			}
		}
	}
	
	public void heapSort(double[] sorted){
		for(int i=1; i<sorted.length - 1; i++){
			buildMaxHeap(sorted,i);
			swap(sorted, 1, sorted.length-i);
		}//end for
	}
	
	public void swap(double[] sorted, int i, int j){
		double temp = sorted[i];
		sorted[i] = sorted[j];
		sorted[j] = temp;
	}
}
