import math

# 1. Сортировка выбором (Selection Sort)
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

# 2. Сортировка обменом (Bubble Sort)
def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

# 3. Сортировка вставками (Insertion Sort)
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key

# 4. Сортировка слиянием (Merge Sort)
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]
    
    left = merge_sort(left)
    right = merge_sort(right)
    
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    result.extend(left[i:])
    result.extend(right[j:])
    
    return result

# 5. Сортировка Шелла (Shell Sort)
def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# 6. Быстрая сортировка (Quick Sort)
def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i + 1

# 7. Пирамидальная сортировка (Heap Sort)
def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2
    
    if left < n and arr[left] > arr[largest]:
        largest = left
    
    if right < n and arr[right] > arr[largest]:
        largest = right
    
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
    
    for i in range(n//2 - 1, -1, -1):
        heapify(arr, n, i)
    
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

# 8. Последовательный поиск (Linear Search)
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

# 9. Бинарный поиск (Binary Search)
def binary_search(arr, target):
    left = 0
    right = len(arr) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid] == target:
            return mid
        
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1

# 10. Интерполирующий поиск (Interpolation Search)
def interpolation_search(arr, target):
    low = 0
    high = len(arr) - 1
    
    while low <= high and target >= arr[low] and target <= arr[high]:
        if low == high:
            if arr[low] == target:
                return low
            return -1
        
        pos = low + (((high - low) // (arr[high] - arr[low])) * (target - arr[low]))
        
        if arr[pos] == target:
            return pos
        
        if arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1
    
    return -1

# 11. Поиск Фибоначчи (Fibonacci Search)
def fibonacci_search(arr, target):
    n = len(arr)
    
    fib2 = 0
    fib1 = 1
    fib = fib2 + fib1
    
    while fib < n:
        fib2 = fib1
        fib1 = fib
        fib = fib2 + fib1
    
    offset = -1
    
    while fib > 1:
        i = min(offset + fib2, n - 1)
        
        if arr[i] < target:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i
        elif arr[i] > target:
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1
        else:
            return i
    
    if fib1 and offset + 1 < n and arr[offset + 1] == target:
        return offset + 1
    
    return -1

# Тестирование всех алгоритмов
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    print(f"Исходный массив: {arr}")
    
    # Тестирование сортировок
    temp = arr.copy()
    selection_sort(temp)
    print(f"Сортировка выбором: {temp}")
    
    temp = arr.copy()
    bubble_sort(temp)
    print(f"Сортировка пузырьком: {temp}")
    
    temp = arr.copy()
    insertion_sort(temp)
    print(f"Сортировка вставками: {temp}")
    
    temp = arr.copy()
    temp = merge_sort(temp)
    print(f"Сортировка слиянием: {temp}")
    
    temp = arr.copy()
    shell_sort(temp)
    print(f"Сортировка Шелла: {temp}")
    
    temp = arr.copy()
    quick_sort(temp, 0, len(temp)-1)
    print(f"Быстрая сортировка: {temp}")
    
    temp = arr.copy()
    heap_sort(temp)
    print(f"Пирамидальная сортировка: {temp}")
    
    # Тестирование поиска
    sorted_arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    target = 7
    
    print(f"\nПоиск в массиве: {sorted_arr}")
    print(f"Ищем элемент: {target}")
    
    result = linear_search(sorted_arr, target)
    print(f"Линейный поиск: позиция {result}")
    
    result = binary_search(sorted_arr, target)
    print(f"Бинарный поиск: позиция {result}")
    
    result = interpolation_search(sorted_arr, target)
    print(f"Интерполяционный поиск: позиция {result}")
    
    result = fibonacci_search(sorted_arr, target)
    print(f"Поиск Фибоначчи: позиция {result}")
