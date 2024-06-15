#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000 // 데이터 배열 크기 상수로 선언

// 선택 정렬
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// 삽입 정렬
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 버블 정렬
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 쉘 정렬
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
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

// 합병 정렬
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // 임시 배열의 크기를 최대 배열 크기로 고정
    int L[ARRAY_SIZE], R[ARRAY_SIZE];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(int arr[], int l, int r) {
    mergeSortHelper(arr, l, r);
}

// 퀵 정렬
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
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

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int low, int high) {
    quickSortHelper(arr, low, high);
}

// 라이브러리를 사용한 퀵 정렬
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void quickSortLib(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
}

// 힙 정렬
void heapify(int arr[], int n, int i) {
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

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// 데이터를 무작위로 생성하는 함수
void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // 0부터 999 사이의 난수 생성
    }
}

// 시간 측정 함수
double measureTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// 각 정렬 알고리즘들의 실행 시간 측정 함수
double measureSortingTime(int arr[], int n, void (*sortFunc)(int[], int)) {
    clock_t start, end;
    start = clock();
    (*sortFunc)(arr, n);
    end = clock();
    return measureTime(start, end);
}

// 평균 시간 측정 함수
double measureAverageTime(int arr[], int n, void (*sortFunc)(int[], int), int iterations) {
    double totalTime = 0;
    for (int i = 0; i < iterations; i++) {
        generateRandomArray(arr, n); // 매 반복마다 새로운 데이터 생성
        totalTime += measureSortingTime(arr, n, sortFunc);
    }
    return totalTime / iterations;
}

int main() {
    const int iterations = 10; // 실험 반복 횟수
    const int arraySize = ARRAY_SIZE; // 배열 크기

    int arr[ARRAY_SIZE]; // 데이터 배열 선언


    // 각 정렬 알고리즘에 대해 평균 실행 시간 측정
    printf("Selection Sort: %.6f seconds\n", measureAverageTime(arr, arraySize, selectionSort, iterations));
    printf("Insertion Sort: %.6f seconds\n", measureAverageTime(arr, arraySize, insertionSort, iterations));
    printf("Bubble Sort: %.6f seconds\n", measureAverageTime(arr, arraySize, bubbleSort, iterations));
    printf("Shell Sort: %.6f seconds\n", measureAverageTime(arr, arraySize, shellSort, iterations));
    printf("Merge Sort: %.6f seconds\n", measureAverageTime(arr, arraySize, mergeSort, 0, arraySize - 1, iterations));
    printf("Quick Sort: %.6f seconds\n", measureAverageTime(arr, arraySize, quickSort, 0, arraySize - 1, iterations));
    printf("Quick Sort (using library): %.6f seconds\n", measureAverageTime(arr, arraySize, quickSortLib, iterations));
    printf("Heap Sort: %.6f seconds\n", measureAverageTime(arr, arraySize, heapSort, iterations));

    return 0;
}
