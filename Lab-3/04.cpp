#include <iostream>
#include <vector>

using namespace std;

namespace esm{

    template <typename T>
    void swap(T& a,T &b){
        T c = a;
        a = b;
        b = c;
    }

    template <typename T>
    void print(vector<T> A){
        for (int i = 0; i < A.size(); ++i) {
            cout << A[i] <<" ";
        }
        cout << endl;
    }

    template <typename T>
    void input(vector<T>& A, int size){
        A.clear();
        for (int i = 0; i < size; ++i) {
            T temp;
            cin >> temp;
            A.push_back(temp);
        }
    }

    template <typename T>
    void Merge(vector<T>& A, int l, int m, int r){
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;
        vector<T> L, R;
        for (i = 0; i < n1; i++) {
            L.push_back(A[l + i]);
        }

        for (j = 0; j < n2; j++) {
            R.push_back(A[m + 1 + j]);
        }

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2){
            if (L[i] <= R[j]){
                A[k] = L[i];
                i++;
            }
            else{
                A[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1){
            A[k] = L[i];
            i++;
            k++;
        }
        while (j < n2){
            A[k] = R[j];
            j++;
            k++;
        }
    }

    template <typename T>
    void MergeSort(vector<T>& A, int l, int r)
    {
        if (l < r)
        {
            int m = l+(r-l)/2;
            esm::MergeSort(A, l, m);
            esm::MergeSort(A, m+1, r);
            esm::Merge(A, l, m, r);
        }
    }
}

int main(){
    vector<int> A;
    cout<<"Enter 10 elements(int): ";
    esm::input(A, 10);
    cout<<"Before sorting: ";
    esm::print(A);
    esm::MergeSort(A,0,A.size());
    cout<<"After merge sort: ";
    esm::print(A);
    return 0;
}