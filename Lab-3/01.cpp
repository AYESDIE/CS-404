//  2.3 insert 10 numbers from the user and sort it using Bubble sort algorithm.
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
    void BubbleSort(vector<T>& A){
        for (int i = 0; i <= A.size() - 1; ++i) {
            for (int j = A.size(); j >= i+1 ; --j) {
                if(A[j] < A[j-1])
                    esm::swap(A[j], A[j-1]);
            }
        }
    }
}


int main(){
    vector<int> A;
    cout<<"Enter 10 elements(int): ";
    esm::input(A, 10);
    cout<<"Before sorting: ";
    esm::print(A);
    esm::BubbleSort(A);
    cout<<"After bubble sort: ";
    esm::print(A);
    return 0;
}