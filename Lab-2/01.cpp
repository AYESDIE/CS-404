/**
 * 1. Create text files with random names.
 */

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;
}


bool isgreater(string& a, string& b){
    for (int i = 0; i < a.size(); ++i) {
        int x = a[i];
        int y = b[i];
        if (x < y){
            return true;
        }
        if (x > y){
            return false;
        }
    }
    return false;
}

template <typename T>
void Sort(T arr[], int n)
{
    int i, j;
    T key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && !isgreater(arr[j], key))
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main(){
    string k[10];
    string txt = ".txt";
    for (int i = 0; i < 10; ++i) {
        k[i] = random_string(10);
    }

    Sort(k, 10);
    for (int j = 0; j < 10; ++j) {
        cout << k[j];
    }

    for (int l = 0; l < 10; ++l) {
        fstream file;
        file.open(k[l]+txt, ios::out);

        if(!file)
        {
            cout<< "Error in creating file";
        }
        file << k[l];
        file.close();
    }

    string t;
    cout << "Enter a file to search";
    cin>>t;

    for (int m = 0; m < 10 ; ++m) {
        if (t == k[m]){
            cout << " file found";
            return 0;
        }
    }
    return 0;
}