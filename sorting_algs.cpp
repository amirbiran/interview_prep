
// https://leetcode.com/problems/sort-an-array/


// Built-ins

// https://www.geeksforgeeks.org/know-sorting-algorithm-set-1-sorting-weapons-used-programming-languages/

// C++ stl sort method - O(nlogn) time, O(logn) space.
// C++ stl stable_sort method - O(nlogn) time, O(n) space.

//

// When I reallyyyy care about space complexity O(1) - can use max-sort / bubble-sort in n^2 or heap-sort in nlogn

// Merge Sort

private:
  void merge(vector<int> &left, vector<int> &right, vector<int> &merged) {
    int i=0, j=0, k=0;
    while(i<left.size() && j<right.size()) {
      if(left[i] < right[j]) {
        merged[k++] = left[i++];
      } else {
        merged[k++] = right[j++];
      }
    }
    while(i<left.size()) {
      merged[k++] = left[i++];
    }
    while(j<right.size()) {
      merged[k++] = right[j++];
    }
  }

public:
  void mergeSort(vector<int> &arr) {
    if(arr.size() <= 1) {
      return;
    }

    vector<int> left = vector<int>(arr.begin(), arr.begin() + arr.size()/2);
    vector<int> right = vector<int>(arr.begin() + arr.size()/2, arr.end());

    mergeSort(left);
    mergeSort(right);
    merge(left, right, arr);
  }


// Quick Sort

private:
  int partition(vector<int> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    while(i <= j) {
      while(values[i] < pivotValue) {
          i++;
      }
      while(values[j] > pivotValue) {
          j--;
      }
      if(i <= j) {
          swap(values[i++], values[j--]);
      }
    }
    return i;
  }
    
void quickSort(vector<int> &values, int left, int right) {
    if(left < right) {
      int pivotIndex = partition(values, left, right);
      quickSort(values, left, pivotIndex - 1);
      quickSort(values, pivotIndex, right);
    }
  }

public:
  void quickSort(vector<int> &values) {
    quickSelect(values, 0, values.size()-1);
  }


// Quick Select (get k'th smallest element in unsorted array)

private:
  // same partition method used in quick sort
  int partition(vector<int> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    while(i <= j) {
      while(values[i] < pivotValue) {
          i++;
      }
      while(values[j] > pivotValue) {
          j--;
      }
      if(i <= j) {
          swap(values[i++], values[j--]);
      }
    }
    return i;
  }
    
  // Important - here always pass the vector by reference. Only difference from quick sort logic is the if-else.
  int quickSelect(vector<int> &values, int k, int left, int right) {
    if(left < right) {
      int pivotIndex = partition(values, left, right);
      if(pivotIndex > k) 
        quickSelect(values, k, left, pivotIndex - 1);
      else 
        quickSelect(values, k, pivotIndex, right);
    }
    return values[k];
  }
    
public:
  // pay attention - not passedd by reference. Crucial if you want to keep the original array values.
  int quickSelect(vector<int> values, int k) {
    return quickSelect(values, k, 0, values.size()-1);
  }
  
  

// Get K smallest/largest numbers in an unsorted array in O(n) time. If sorted results required, O(n + K*log(K)) time.

// Use Quick Select to find kth smallest/largest element, and partition around this element. 
  

// Count/Bucket Sort

// Use buckets when the number of possible array values are known and not too great.



// Radix Sort

// Time O((n+b) * logb(k)) Space O(n) because of count sorts used for different digits. Sometimes preferarable.



// Heap Sort

// Practically not as good as merge sort and quick sort. 







