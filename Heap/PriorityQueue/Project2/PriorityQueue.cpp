#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int parent_index(int i) {
    return floor((i - 1) / 2);
}

void max_heapify(vector<int>& arr, int i, int heap_size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left<heap_size && arr[left]>arr[largest]) {
        largest = left;
    }
    if (right<heap_size && arr[right]>arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, heap_size);
    }
}

int Heap_Maximum(vector<int>& arr) {
    return arr[0];
}

int heap_extract_max(vector<int>& arr) {
    if (arr.size() < 1) {
        throw invalid_argument("Heap underflow");
    }
    int max_val = arr[0];
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    max_heapify(arr, 0, arr.size());
    return max_val;
}

void heap_increase_key(vector<int>& arr, int i, int key) {
    if (key < arr[i]) {
        throw invalid_argument("New key is smaller than current key");
    }
    arr[i] = key;
    while (i > 0 && arr[i] > arr[parent_index(i)]) {
        swap(arr[i], arr[parent_index(i)]);
        i = parent_index(i);
    }
}

void max_heap_insert(vector<int>& arr, int key) {
    arr.push_back(INT_MIN);
    heap_increase_key(arr, arr.size() - 1, key);
}
