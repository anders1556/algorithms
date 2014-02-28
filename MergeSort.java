
  6ckage sort;

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
00  cat test.java | grep "this"
  601  echo "hello" >> a.log
  602  cat a.log
  603  echo << a.log
;
cjdfkds




  604  echo << cat a.log
a.log

  605  history
  606  history --help
  607  man history
  608  history 1 20
  609  history 20
  610  history 100 > history.list
  611  ls
  612  cat history.list 
  613  vi history.list 
  614  clear
  615  ls
  616  ls -a
  617  git add .
  618  ls
  619  git status -s
  620  git commit -m "git log"
  621  cat history.list 
  622  git push origin master
  623  git remote -v
  624  git status -s
  625  git status
  626  ls -a
  627  git add history.list
  628  git commit -m "git history"
  629  git checkout master 
  630  ls
  631  cd ..
  632  branch
  633  cd test/
  634  git branch
  635  cd ..
  636  ls
  637  cd test/
  638  ls
  639  cd ..
  640  ls
  641  cd ..
