#include <iostream>
#include <vector>

template <typename T>
T findMax(const std::vector<T>& arr) {
    T maxElement = arr[0];
    for (const auto& element : arr) {
        if (element > maxElement) {
            maxElement = element;
        }
    }
    return maxElement;
}

template <typename T>
T findMin(const std::vector<T>& arr) {
    T minEl = arr[0];
    for (const auto& el : arr) {
        if (el < minEl) {
            minEl = el;
        }
    }
    return minEl;
}

template <typename T>
void bubbleSort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int binSearch(std::vector<T>& arr, T& target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

template <typename T>
void replace(std::vector<T>& arr, T& oldValue, T& newValue) {
    for (auto& element : arr) {
        if (element == oldValue) {
            element = newValue;
        }
    }
}

int main() {
    std::vector<int> arr;
    std::cout << "Enter size: "; int n; std::cin >> n;
    int vrem;
    for (int i = 0; i < n; ++i) {
        std::cin >> vrem;
        arr.push_back(vrem);
    }
    std::cout << "Array: ";
    for (auto& i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Max: " << findMax(arr) << std::endl;
    std::cout << "Min: " << findMin(arr) << std::endl;

    bubbleSort(arr);
    std::cout << "Sorted: ";
    for (auto& i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    int ta;
    std::cout << "Enter value for searching: ";
    std::cin >> ta;
    int index = binSearch(arr, ta);
    if (index != -1) {
        std::cout << "Element " << ta << " is at index " << index << std::endl;
    }
    else {
        std::cout << "Element " << ta << " was not found in the arr" << std::endl;
    }

    int old;
    int newq;
    std::cout << "Enter value for searching: ";
    std::cin >> ta;
    std::cout << "Enter old and new value separating with a space: ";
    std::cin >> old >> newq;
    replace(arr, old, newq);
    std::cout << "Array after replacing " << old << " with " << newq << ": ";
    for (auto& i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
