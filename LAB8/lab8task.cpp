#include <iostream>
#include <vector>
#include <iomanip> // Required for spacing and alignment (setw)

using namespace std;

// Helper function to print the array with indices directly underneath (like the slides)
void printArrayWithIndices(const vector<int>& arr, int start, int end, bool resetIndices = false) {
    // Print the actual numbers
    for (int i = start; i <= end; i++) {
        cout << left << setw(5) << arr[i];
    }
    cout << "\n";

    // Print the index numbers directly below them
    for (int i = start; i <= end; i++) {
        // Merge sort slides reset the index to 0 for sub-arrays
        int indexToPrint = resetIndices ? (i - start) : i;
        cout << left << setw(5) << indexToPrint;
    }
    cout << "\n";
}

void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        cout << "Pass " << i + 1 << " :\n";
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                cout << "swap " << arr[j] << " and " << arr[j+1] << "\n";
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) cout << "already sorted\n";
        printArrayWithIndices(arr, 0, n - 1);
        cout << "\n";
    }
}

void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        cout << "Step " << i + 1 << " :\n";
        int key = arr[i];
        int j = i - 1;

        cout << "i = " << i << ", x = " << key << "\n";
        bool shifted = false;

        while (j >= 0 && arr[j] > key) {
            cout << "Shift down " << arr[j] << "\n";
            arr[j + 1] = arr[j];
            j = j - 1;
            shifted = true;
        }

        if (!shifted) {
            cout << "No Shift will take place\n";
        }

        arr[j + 1] = key;
        printArrayWithIndices(arr, 0, n - 1);
        cout << "\n";
    }
}

void selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        cout << "Step " << i + 1 << " :\n";
        printArrayWithIndices(arr, i, n - 1); // Only print the unsorted part

        int min_idx = i;
        cout << "Minj = " << i << ", Minx = " << arr[i] << "\n";

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                cout << "Index = " << j << ", value = " << arr[j] << "\n";
            }
        }

        if (min_idx != i) {
            cout << "Swap " << arr[i] << " and " << arr[min_idx] << "\n";
            swap(arr[min_idx], arr[i]);
        } else {
            cout << "No Swapping as min value is already at right place\n";
        }
        cout << "\n";
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
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

void mergeSortHelper(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;

    cout << "Step: Split the selected array\n";
    printArrayWithIndices(arr, left, mid, true); // true resets index to 0
    cout << "\n";
    printArrayWithIndices(arr, mid + 1, right, true);
    cout << "------------------------\n";

    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);

    merge(arr, left, mid, right);

    cout << "Sorted elements:\n";
    printArrayWithIndices(arr, left, right, true);
    cout << "------------------------\n";
}

void mergeSort(vector<int> arr) {
    printArrayWithIndices(arr, 0, arr.size() - 1, true);
    cout << "\n";
    mergeSortHelper(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> numbers = {72, 14, 55, 9, 31, 88, 42};

    cout << "========== UNSORTED ARRAY ==========\n";
    printArrayWithIndices(numbers, 0, numbers.size() - 1);
    cout << "\n";

    cout << "========== BUBBLE SORT ==========\n";
    bubbleSort(numbers);

    cout << "========== INSERTION SORT ==========\n";
    insertionSort(numbers);

    cout << "========== SELECTION SORT ==========\n";
    selectionSort(numbers);

    cout << "========== MERGE SORT ==========\n";
    mergeSort(numbers);

    return 0;
}