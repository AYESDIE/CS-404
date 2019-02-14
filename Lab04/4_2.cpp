#include <iostream>
#include <vector>

namespace ens
{
    class node{
        bool flag;
        std::vector<node*> linker;

        void set(node* l, int x) { linker[x] = l; }
    public:
        node() {
            flag = false;
            linker.clear();
            linker.push_back(nullptr);
            linker.push_back(nullptr);
        }
        bool isFlag() const {return flag;}
        const std::vector<node*> &getLinker() const { return linker; }
        void setLeft(node* l) { set(l, 0); }
        void setRight(node* r) { set(r, 1); }
        void setFlag(bool x) { flag = x; }
    };



    class tree
    {
        node* root;

        /**
         * Converts integer to boolean.
         *
         * @param k integer
         * @return boolean
         */
        std::vector<size_t> int2bool(size_t k)
        {
            std::vector<size_t> m;
            while(k!=0)
            {
                m.push_back(((k%2==0)?0:1));
                k/=2;
            }
            return m;
        }

        /**
         * Converts boolean to integer
         *
         * @param x boolean
         * @return integer
         */
        size_t bool2int(std::vector<size_t> x)
        {
            double m = 0;
            for (int i = x.size()-1; i >= 0; --i) {
                m = m + x[i] * pow(2,i);
            }
            return (size_t)m;
        }

        std::vector<size_t> flip(std::vector<size_t> x)
        {
            std::vector<size_t> m;
            for (int i = x.size()-1; i >= 0 ; --i) {
                m.push_back(x[i]);
            }
            return m;
        }

        void showbool(std::vector<size_t> m)
        {
            for (int i = 0; i < m.size(); ++i) {
                std::cout<<m[i];
            }
            std::cout<<std::endl;
        }



    public:
        tree() {}

        /**
         * Expands the tree to add any element
         * @param x integer to be added
         * @return root
         */
        void _insert(size_t x)
        {
            node* pointer = root;
            std::vector b = int2bool(x);
            b.pop_back();
            for (int i = b.size() - 1; i >= 0 ; --i) {
                //  left subtree
                if(b[i] == 0)
                {
                    std::cout<<"EL ";
                    std::vector<node*> linker = pointer->getLinker();
                    //  if left there is no left subtree
                    if(linker[0] == nullptr)
                    {
                        std::cout<<"N ";
                        pointer->left = newNode();
                    }
                    pointer = pointer->left;
                }
                else
                {
                    std::cout<<"ER ";
                    //  if left there is no right subtree
                    if(pointer->right == nullptr)
                    {
                        std::cout<<"N ";
                        pointer->right = newNode();
                    }
                    pointer = pointer->right;
                }
            }
            std::cout<<"node entered"<<std::endl;
            pointer->flag = true;
        }
    };
}


int main()
{
    ens::tree x;
    x._insert(1);
    x._insert(10);
    x._insert(39);
    x._insert(10);
}
