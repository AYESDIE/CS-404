// 2.1  Input 10 numbers from the user and sort it using Insertion sort.
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
    void InsertionSort(vector<T>& A){
        for (int j = 1; j < A.size() ; ++j) {
            T key = A[j];
            int i = j - 1;
            while((i >= 0) && (A[i] > key)){
                A[i+1] = A[i];
                i = i - 1;
            }
            A[i + 1] = key;
        }
    }
}

int main(){
    vector<int> A;
    cout<<"Enter 10 elements(int): ";
    esm::input(A, 10);
    cout<<"Before sorting: ";
    esm::print(A);
    esm::InsertionSort(A);
    cout<<"After insertion sort: ";
    esm::print(A);
    return 0;
}