/**
 * WAP to represent TOH.
 */

#include <iostream>
#include <vector>
#include <string>

namespace ens{

    void towerOfHanoi(
            int n,
            char from,
            char to,
            char aux)
    {
        if (n == 1)
        {
            std::cout<<"\n Disk 1 : "<< from << " ---> " << to;
            return;
        }
        towerOfHanoi(n-1, from, aux, to);
        std::cout<<"\n Disk "<< n <<" : "<< from << " ---> " << to;
        towerOfHanoi(n-1, aux, to, from);
    }
}

int main() {
    int n = 4;
    ens::towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}