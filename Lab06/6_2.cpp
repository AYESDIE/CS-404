/**
 *  6.2 Given weights and values of n items, put these items in a
 *  knapsack of capacity W to get the maximum total value in the
 *  knapsack. In other words, given two integer arrays val[0..n-1]
 *  and wt[0..n-1] which represent values and weights associated
 *  with n items respectively. Also given an integer W which
 *  represents knapsack capacity, find out the maximum value subset
 *  of val[] such that sum of the weights of this subset is smaller
 *  than or equal to W. You cannot break an item, either pick the
 *  complete item, or don’t pick it (0-1 property).
 */

#include <iostream>
#include <vector>

using namespace std;

namespace esm{
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
    T max(T a, T b)
    {
        return (a > b) ? a : b;
    }

    int knapSack(int W, const vector<int>& wt, const vector<int>& val, int n)
    {
        if (n==0||W==0)
            return 0;

        if (wt[n-1] > W)
            return knapSack(W, wt, val, n-1);

        else
            return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1));
    }
}

int main()
{
    vector<int> wt, val;
    int num, W;
    cout << "Enter number of items\n>> ";
    cin >> num;

    cout << "Enter " << num << " weights: ";
    esm::input(wt, num);
    cout << "Enter " << num << " values: ";
    esm::input(val, num);
    cout << "Enter W: ";
    cin >> W;

    cout << "\nWeights\n";
    esm::print(wt);

    cout << "\nValues\n";
    esm::print(val);

    cout << "\n KnapSack: " << esm::knapSack(W, wt, val, num);
    return 0;


}