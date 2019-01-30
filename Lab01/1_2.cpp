/**
 * 2. Input a string (i.e. a student's name),  search in the output set  above question
 * and display the related record details of the corresponding student.
 */

#include <iostream>
#include <string>

using namespace std;

class student{
private:
    string name;
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

template <typename T>
void Sort(T arr[], int n)
{
    int i, j;
    T key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main(){
    student x[4];
    for (int i = 0; i < 4 ; ++i) {
        string s;
        float t;
        cout << "name: ";
        cin >> s ;
        cout << "marks: ";
        cin >> t;
        x[i] = student(s, t);
    }

    Sort(x, 4);
    cout << "Sorted ";
    for (int j = 0; j < 4 ; ++j) {
        cout << x[j] <<" ";
    }

    string p;
    cout<< "  Enter a name to be searched: ";
    cin >> p;

    for (int k = 0; k < 4; ++k) {
        if(x[k].checkName(p)){
            cout << "name found";
            return 0;
        }
    }

    cout << "name not found";
    return 0;
}

