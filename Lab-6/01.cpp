// 6.1  Input 10 numbers from the user and sort it using Heap sort.
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
    void heapify(vector<T>& A, int n, int i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;


        if (l < n && A[l] > A[largest])
            largest = l;

        if (r < n && A[r] > A[largest])
            largest = r;

        if (largest != i)
        {
            swap(A[i], A[largest]);
            heapify(A, n, largest);
        }
    }

    template <typename T>
    void heapSort(vector<T>& A, int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(A, n, i);

        for (int i=n-1; i>=0; i--)
        {
            swap(A[0], A[i]);
            heapify(A, i, 0);
        }
    }
}

int main()
{
    vector<int> A;
    cout<<"Enter 10 elements(int): ";
    esm::input(A, 10);
    cout<<"Before sorting: ";
    esm::print(A);
    esm::heapSort(A, A.size());
    cout<<"After quick sort: ";
    esm::print(A);
    return 0;
}