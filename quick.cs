using System;

class ConsoleApp4 {
    static int Division(int[] array, int first, int last) {
        int pivot = array[last];
        int i = first - 1;
        for (int j = first; j <= last - 1; j++) {
            if (array[j] < pivot) {
                i++;
                Swap(array, i, j);
            }
        }
        
        Swap(array, i + 1, last);  
        return i + 1;
    }
 
    static void Swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    static void QuickSort(int[] arr, int low, int high) {
        if (low < high) {
            
            int piv = Division(arr, low, high);
            QuickSort(arr, low, piv - 1);
            QuickSort(arr, piv + 1, high);
        }
    }

    static void Main(string[] args) {
        int[] arr = {10, 7, 8, 9, 1, 5};
        int n = arr.Length;

        QuickSort(arr, 0, n - 1);
        foreach (int val in arr) {
            Console.Write(val + " "); 
        }
    }
}