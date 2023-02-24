#include <iostream>
#include <vector>

using namespace std;

void max_heapify(vector<int>& arr, int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, n);
    }
}

void build_max_heap(vector<int>& arr) {
    for (int i = arr.size() / 2 - 1; i >= 0; i--) {
        max_heapify(arr, i, arr.size());
    }
}

void heap_sort(vector<int>& arr) {
    build_max_heap(arr);
    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i);
    }
}

int main() {
    vector<int> arr = { 5, 2, 9, 1, 5, 6 };
    heap_sort(arr);

    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
/*
���̽��� �Ű������� arr�� �������� �� �ּҵ� �Բ� ���޵����� C�� C++������
�׷��� �����Ƿ� �ּҸ� �������־�� �Ѵ�. ���� �Ű������� �����ڸ� �����ߴ�. 
vector�� include�Ͽ� �迭�� vector�� ����Ͽ��� swap�Լ��� ����� ���� �������� �� �� �ִ�.
*/