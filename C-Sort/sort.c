#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int count = 11;

void swap(int *nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// 冒泡排序
void bubbleSort(int *nums, int count) {
	int i,j;
    for (i = 0; i < count; i++) {
        for (j = count - 1; j > i; j--) {
            if (nums[j] < nums[j - 1]) {
                swap(nums, j, j - 1);
            }
        }
    }
}

// 选择排序
void selectionSort(int *nums, int count) {
	int i,j;
    for (i = 0; i < count; i++) {
        int min = i;
        for (j = i + 1; j < count; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(nums, i, min);
        }
    }
}

// 插入排序
void insertionSort(int *nums, int count) {
	int i,j;
    for (i = 0; i < count; i++) {
        int min = i;
        for (j = i + 1; j < count; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = nums[min];
            for (j = min; j > i; j--) {
                nums[j] = nums[j-1];
            }
            nums[i] = temp;
        }
    }
}

// 快速排序
void partition(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int low = left, high = right;
    int pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            high--;
        }
        if (low < high) {
            nums[low++] = nums[high];
        }
        while (low < high && nums[low] <= pivot) {
            low++;
        }
        if (low < high) {
            nums[high--] = nums[low];
        }
    }
    nums[low] = pivot;
    partition(nums, left, low - 1);
    partition(nums, high + 1, right);
}

void quickSort(int *nums, int count) {
    partition(nums, 0, count - 1);
}

// 堆排序
void maxHeapify(int *nums, int start, int end) {
    int left = start * 2 + 1;
    if (left <= end && nums[left] > nums[start]) {
        swap(nums, left, start);
        maxHeapify(nums, left, end);
    }
    int right = left + 1;
    if (right <= end && nums[right] > nums[start]) {
        swap(nums, right, start);
        maxHeapify(nums, right, end);
    }
}

void heapSort(int *nums, int count) {
    // 构建初始堆，从最后一个父节点开始
    int i;
    for (i = count / 2 - 1; i >= 0; i--) {
        maxHeapify(nums, i, count - 1);
    }
    // 把最大值放到堆尾部
    for (i = count - 1; i > 0; i--) {
        swap(nums, i, 0);
        maxHeapify(nums, 0, i - 1);
    }
}

// 希尔排序
void shellSort(int *nums, int count) {
	int gap,i,j;
    for (gap = count / 2; gap > 0; gap /= 2) {
        // 这里的i表示每个分组里的最后一个数据
        for (i = gap; i < count; i++) {
            for (j = i; j > 0; j -= gap) {
                if (nums[j - 1] > nums[j]) {
                    swap(nums, j - 1, j);
                }
            }
        }
    }
}

//  归并排序
void merge(int *nums, int left, int middle, int right) {
    int count = right - left + 1;
    int *tempNums = malloc(sizeof(int) *count);
    int i = left, j = middle + 1, k = 0;
    while (i <= middle && j <= right) {
        if (nums[i] < nums[j]) {
            tempNums[k++] = nums[i++];
        } else {
            tempNums[k++] = nums[j++];
        }
    }
    while (i <= middle) {
        tempNums[k++] = nums[i++];
    }
    while (j <= right) {
        tempNums[k++] = nums[j++];
    }
    int l;
    for (l = 0; l < k; l++) {
        nums[left + l] = tempNums[l];
    }
}

void mergeSort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int middle = (right + left) / 2;
    mergeSort(nums, left, middle);
    mergeSort(nums, middle + 1, right);
    merge(nums, left, middle, right);
}

// 计数排序
void countSort(int *nums, int count) {
    int max = 0;
    int i;
    for (i = 0; i < count; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    int *buckets = malloc(sizeof(int) * (max + 1));
    memset(buckets, 0, max + 1);
    for (i = 0; i < count; i++) {
        buckets[nums[i]] += 1;
    }
    int k;
    for (i = 0, k = 0; i < max + 1; i++) {
        while (buckets[i]) {
            nums[k++] = i;
            buckets[i]--;
        }
    }
}

// 基数排序

int main(int argc, const char * argv[]) {
    int nums[] = {2, 10, 33, 63, 48, 41, 1, 0, 59, 86, 77};
    
//        bubbleSort(nums, count);
//        selectionSort(nums, count);
//        insertionSort(nums, count);
        quickSort(nums, count);
//        heapSort(nums, count);
//        shellSort(nums, count);
//        mergeSort(nums, 0, count - 1);
//        countSort(nums, count);
    int i;
    for (i = 0; i < count; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}
