#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Сортировка выбором (Selection Sort)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 2. Сортировка обменом (Bubble Sort)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// 3. Сортировка вставками (Insertion Sort)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
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
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < leftArr.size()) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < rightArr.size()) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 5. Сортировка Шелла (Shell Sort)
void shellSort(vector<int>& arr) {
    int n = arr.size();
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
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 7. Пирамидальная сортировка (Heap Sort)
void heapify(vector<int>& arr, int n, int i) {
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
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 8. Последовательный поиск (Linear Search)
int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// 9. Бинарный поиск (Binary Search)
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
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
int interpolationSearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));
        
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
int fibonacciSearch(vector<int>& arr, int target) {
    int n = arr.size();
    
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
        int i = min(offset + fib2, n - 1);
        
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
    
    if (fib1 && offset + 1 < n && arr[offset + 1] == target) {
        return offset + 1;
    }
    
    return -1;
}

// Функция для вывода массива
void printArray(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "Исходный массив: ";
    printArray(arr);
    
    // Тестирование сортировок
    vector<int> temp = arr;
    
    selectionSort(temp);
    cout << "Сортировка выбором: ";
    printArray(temp);
    
    temp = arr;
    bubbleSort(temp);
    cout << "Сортировка пузырьком: ";
    printArray(temp);
    
    temp = arr;
    insertionSort(temp);
    cout << "Сортировка вставками: ";
    printArray(temp);
    
    temp = arr;
    mergeSort(temp, 0, temp.size()-1);
    cout << "Сортировка слиянием: ";
    printArray(temp);
    
    temp = arr;
    shellSort(temp);
    cout << "Сортировка Шелла: ";
    printArray(temp);
    
    temp = arr;
    quickSort(temp, 0, temp.size()-1);
    cout << "Быстрая сортировка: ";
    printArray(temp);
    
    temp = arr;
    heapSort(temp);
    cout << "Пирамидальная сортировка: ";
    printArray(temp);
    
    // Тестирование поиска
    vector<int> sortedArr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;
    
    cout << "\nПоиск в массиве: ";
    printArray(sortedArr);
    cout << "Ищем элемент: " << target << endl;
    
    int result = linearSearch(sortedArr, target);
    cout << "Линейный поиск: позиция " << result << endl;
    
    result = binarySearch(sortedArr, target);
    cout << "Бинарный поиск: позиция " << result << endl;
    
    result = interpolationSearch(sortedArr, target);
    cout << "Интерполяционный поиск: позиция " << result << endl;
    
    result = fibonacciSearch(sortedArr, target);
    cout << "Поиск Фибоначчи: позиция " << result << endl;
    
    return 0;
}
