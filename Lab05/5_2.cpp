// 5.2  Input info of 8 students from the user and sort it using Quick sort.
#include <iostream>
#include <vector>
#include <string>


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
            cout << A[i] <<" \n";
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
        T pivot = A[h];
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

namespace database
{
    class student{
    private:
        std::string name;
        float marks;

    public:
        student(const string &name, float marks) : name(name), marks(marks) {}
        student() {}

        bool operator<(student& k) {
            for (int i = 0; i < this->name.size(); ++i) {
                int a = this->name[i];
                int b = k.name[i];

                if ( a < b ){
                    return true;
                }

                if ( a > b ){
                    return false;
                }
            }
            return false;
        }

        bool checkName(const string& k){
            return k == this->name;
        }

        bool operator>(student& k) {
            return !(*this < k);
        }

        friend ostream &operator<<(ostream &os, const student &student1) {
            os << "name: " << student1.name << " marks: " << student1.marks;
            return os;
        }
    };
}

int main(){
    vector<database::student> A;
    cout<<"Enter 5 info of students: ";
    for (int i = 0; i < 5; ++i) {
        std::string name;
        float marks;
        std::cout << "\n>> name: ";
        std::cin >> name;
        std::cout << "\n>> marks: ";
        std::cin >> marks;
        database::student temp(name, marks);
        A.push_back(temp);
    }
    cout<<"Before sorting: \n";
    esm::print(A);
    esm::quickSort(A, 0, A.size()-1);
    cout<<"After quick sort: \n";
    esm::print(A);
    return 0;
}