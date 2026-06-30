#include <iostream>
#include <cassert>
#include <utility>

void print_arr(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void insertion_sort(int *arr, int start, int end) {
  for (int i = 1; i <= end; i++) {
    int pivot = arr[i];
    int j = i - 1;
    while (j >= start && arr[j] > pivot) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = pivot;
  }
}


void merge(int *dest, int start, int len, int *arr1, int start1, int end1, int *arr2, int start2, int end2) {
  int i = start1, j = start2;
  int k = 0;
  int tmp[len];
  while (i <= end1 && j <= end2) {
    if (arr1[i] < arr2[j]) {
      tmp[k++] = arr1[i++];
    } else {
      tmp[k++] = arr2[j++];
    }
  }
  if (i > end1) {
    while (j <= end2) {
      tmp[k++] = arr2[j++];
    }
  } else { // j > end2
    while (i <= end1) {
      tmp[k++] = arr1[i++];
    }
  }
  assert(k == len);
  for (int i = 0; i < len; i++) {
    dest[start+i] = tmp[i];
  }
}

void merge_sort(int *arr, int start, int end) {
  if (start < end) {
    int len = end - start + 1;
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, len, arr, start, mid, arr, mid+1, end);
  }
}


int partition(int *arr, int start, int end) {
  int pivot = arr[start];
  int smaller = start;
  int key = start;
  for (int i = start+1; i <= end; i++) {
    if (arr[i] < pivot) {
      std::swap(arr[i], arr[smaller]);
      key = i;
      smaller++;
    }
  }
  std::swap(arr[key], arr[smaller]);
  return smaller;
}

void quick_sort(int *arr, int start, int end) {
  if (start < end) {
    int mid = partition(arr, start, end);
    quick_sort(arr, start, mid);
    quick_sort(arr, mid+1, end);
  } 
}


int binary_search(int *arr, int start, int end, int value) {
  if (start < end) {
    int mid;
    while (start <= end) {
      mid = (start + end) / 2;
      if (value == arr[mid])
        return mid;
      else if (value < arr[mid])
        end = mid - 1;
      else
        start = mid + 1;
    }
  }
  return -1;
}


int main() {
  int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  int len = sizeof(arr) / sizeof(arr[0]);
  print_arr(arr, len);
  //insertion_sort(arr, 0, len-1);
  //merge_sort(arr, 0, len-1);
  quick_sort(arr, 0, len-1);
  print_arr(arr, len);

  int value = 6;
  int index = binary_search(arr, 0, len-1, value);
  std::cout << "The index of value " << value << " is : " << index << std::endl;

  return 0;
}
