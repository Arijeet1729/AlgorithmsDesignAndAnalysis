#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For srand()

using namespace std;

class qSort {
public:

    void swap(vector<int>& a, int e1, int e2) {
        int temp = a[e1];
        a[e1] = a[e2];
        a[e2] = temp;
    }

    int randRange(int min, int max) {
        return min + rand() % (max - min + 1);
    }

    int Partition(vector<int>& arr, int l, int r) {
        srand(time(0)); //seeding
        int rind = randRange(l, r); // Randomized pivot
        swap(arr, l, rind);

        int x = arr[l];
        int j = l;

        for (int i = l + 1; i <= r; i++) {
            if (arr[i] <= x) {
                j++;
                swap(arr, i, j);
            }
        }
        swap(arr, l, j);
        return j;
    }

    void quickSort(vector<int>& arr, int l, int r) {
        if (l >= r) {
            return;
        }

        int m = Partition(arr, l, r);

        quickSort(arr, l, m - 1);
        quickSort(arr, m + 1, r);
    }
};





int main() {
    srand(time(0)); //seeding

    vector<int> input;

    input.push_back(3);
    input.push_back(6);
    input.push_back(8);
    input.push_back(10);
    input.push_back(1);
    input.push_back(2);
    input.push_back(1);

    qSort sorter;
    sorter.quickSort(input, 0, input.size() - 1);

    cout << "Sorted Array: ";
    for (int i=0;i<input.size();i++) {
        cout << input[i]<< " ";
    }
    cout << endl;

    return 0;
}
