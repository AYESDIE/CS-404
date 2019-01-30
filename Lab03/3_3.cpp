// 2.4  input 10 characters from the user and sort it using Selection Sort
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
    void SelectionSort(vector<T>& A){
        for (int i = 0; i < A.size() - 1; ++i) {
            int idx = i;
            for (int j = i + 1; j < A.size() ; ++j) {
                if (A[j] < A[idx])
                    idx = j;
            }
            swap(A[idx], A[i]);
        }
    }
}

int main(){
    vector<int> A;
    cout<<"Enter 10 elements(int): ";
    esm::input(A, 10);
    cout<<"Before sorting: ";
    esm::print(A);
    esm::SelectionSort(A);
    cout<<"After selection sort: ";
    esm::print(A);
    return 0;
}