import java.util.Arrays;

public class Algorithms {
    
    // 1. Сортировка выбором (Selection Sort)
    public static void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n-1; i++) {
            int minIndex = i;
            for (int j = i+1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
    
    // 2. Сортировка обменом (Bubble Sort)
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    
    // 3. Сортировка вставками (Insertion Sort)
    public static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    
    // 4. Сортировка слиянием (Merge Sort)
    public static void merge(int[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        int[] leftArr = new int[n1];
        int[] rightArr = new int[n2];
        
        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    
    // 5. Сортировка Шелла (Shell Sort)
    public static void shellSort(int[] arr) {
        int n = arr.length;
        for (int gap = n/2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }
    
    // 6. Быстрая сортировка (Quick Sort)
    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        return i + 1;
    }
    
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    // 7. Пирамидальная сортировка (Heap Sort)
    public static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, n, largest);
        }
    }
    
    public static void heapSort(int[] arr) {
        int n = arr.length;
        
        for (int i = n/2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        
        for (int i = n-1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
    }
    
    // 8. Последовательный поиск (Linear Search)
    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    // 9. Бинарный поиск (Binary Search)
    public static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) {
                return mid;
            }
            
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    // 10. Интерполирующий поиск (Interpolation Search)
    public static int interpolationSearch(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;
        
        while (low <= high && target >= arr[low] && target <= arr[high]) {
            if (low == high) {
                if (arr[low] == target) return low;
                return -1;
            }
            
            int pos = low + (((high - low) / (arr[high] - arr[low])) * (target - arr[low]));
            
            if (arr[pos] == target) {
                return pos;
            }
            
            if (arr[pos] < target) {
                low = pos + 1;
            } else {
                high = pos - 1;
            }
        }
        return -1;
    }
    
    // 11. Поиск Фибоначчи (Fibonacci Search)
    public static int fibonacciSearch(int[] arr, int target) {
        int n = arr.length;
        
        int fib2 = 0;
        int fib1 = 1;
        int fib = fib2 + fib1;
        
        while (fib < n) {
            fib2 = fib1;
            fib1 = fib;
            fib = fib2 + fib1;
        }
        
        int offset = -1;
        
        while (fib > 1) {
            int i = Math.min(offset + fib2, n - 1);
            
            if (arr[i] < target) {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib - fib1;
                offset = i;
            } else if (arr[i] > target) {
                fib = fib2;
                fib1 = fib1 - fib2;
                fib2 = fib - fib1;
            } else {
                return i;
            }
        }
        
        if (fib1 == 1 && offset + 1 < n && arr[offset + 1] == target) {
            return offset + 1;
        }
        
        return -1;
    }
    
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Исходный массив: " + Arrays.toString(arr));
        
        // Тестирование сортировок
        int[] temp = arr.clone();
        
        selectionSort(temp);
        System.out.println("Сортировка выбором: " + Arrays.toString(temp));
        
        temp = arr.clone();
        bubbleSort(temp);
        System.out.println("Сортировка пузырьком: " + Arrays.toString(temp));
        
        temp = arr.clone();
        insertionSort(temp);
        System.out.println("Сортировка вставками: " + Arrays.toString(temp));
        
        temp = arr.clone();
        mergeSort(temp, 0, temp.length-1);
        System.out.println("Сортировка слиянием: " + Arrays.toString(temp));
        
        temp = arr.clone();
        shellSort(temp);
        System.out.println("Сортировка Шелла: " + Arrays.toString(temp));
        
        temp = arr.clone();
        quickSort(temp, 0, temp.length-1);
        System.out.println("Быстрая сортировка: " + Arrays.toString(temp));
        
        temp = arr.clone();
        heapSort(temp);
        System.out.println("Пирамидальная сортировка: " + Arrays.toString(temp));
        
        // Тестирование поиска
        int[] sortedArr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        int target = 7;
        
        System.out.println("\nПоиск в массиве: " + Arrays.toString(sortedArr));
        System.out.println("Ищем элемент: " + target);
        
        int result = linearSearch(sortedArr, target);
        System.out.println("Линейный поиск: позиция " + result);
        
        result = binarySearch(sortedArr, target);
        System.out.println("Бинарный поиск: позиция " + result);
        
        result = interpolationSearch(sortedArr, target);
        System.out.println("Интерполяционный поиск: позиция " + result);
        
        result = fibonacciSearch(sortedArr, target);
        System.out.println("Поиск Фибоначчи: позиция " + result);
    }
}
