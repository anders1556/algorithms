package sort;

public class BubbleSort {
	public void bubbleSort(double[] sorted){
		int lenght = sorted.length;
		for(int i=0; i<lenght-1; ++i){
			for(int j=0; j<lenght-i-1; ++j){
				if(sorted[j] > sorted[j+1]){
					swap(j, j+1, sorted);
				}
			}//end for
		}//end for
	}
	
	public void swap(int a, int b, double[] sorted){
		double temp = sorted[a];
		sorted[a] = sorted[b];
		sorted[b] = temp;
	}
}
