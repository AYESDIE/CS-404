// 5.1  Input 10 numbers from the user and sort it using Quick sort.
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
    int partition (std::vector<T>& A, int l, int h)
    {
        int pivot = A[h];
        int i = (l - 1);

        for (int j = l; j <= h- 1; j++)
        {
            if (A[j] < pivot)
            {
                i++;
                swap(A[i], A[j]);
            }
        }
        swap(A[i + 1], A[h]);
        return (i + 1);
    }

    template <typename T>
    void quickSort(std::vector<T>& A, int l, int h)
    {
        if (l < h)
        {
            int pi = partition(A, l, h);
            quickSort(A, l, pi - 1);
            quickSort(A, pi + 1, h);
        }
    }
}

int main(){
    vector<int> A;
    cout<<"Enter 10 elements(int): ";
    esm::input(A, 10);
    cout<<"Before sorting: ";
    esm::print(A);
    esm::quickSort(A, 0, A.size()-1);
    cout<<"After quick sort: ";
    esm::print(A);
    return 0;
}