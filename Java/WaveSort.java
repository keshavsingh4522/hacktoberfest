class WaveSort { 
	static void swap(int arr[], int a, int b) { 
		int temp = arr[a]; 
		arr[a] = arr[b]; 
		arr[b] = temp; 
	} 

	static void sort(int arr[], int n)  {
		for (int i = 0; i < n; i+=2) { 
			if (i>0 && arr[i-1] > arr[i] ) 
				swap(arr, i-1, i); 

			if (i<n-1 && arr[i] < arr[i+1] ) 
				swap(arr, i, i + 1); 
		} 
	} 

	public static void main(String args[]) { 
		int arr[] = {22,10,3,12,21,1,2002,2001}; 
		int n = arr.length; 
		sort(arr, n); 
		
		for (int i : arr) 
			System.out.print(i); 
    
		
	} 
} 
