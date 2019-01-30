#include <iostream>
#include <vector>

namespace ens
{
    struct node
    {
        bool flag;
        struct node* left;
        struct node* right;
    };



    class tree
    {
        node* root;

        /**
         * Creates a new node.
         *
         * @param flag (default = false)
         * @return A new node.
         */
        node* newNode(bool flag = false)
        {
            node* f = new node;
            f->flag = flag;
            f->left = nullptr;
            f->right = nullptr;
            return f;
        }

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

        void bfstraverser(
                std::vector<size_t> counter,
                std::vector<node*> indexer)
        {
            std::vector<size_t> ncounter;
            std::vector<node*> nindexer;
            for (int i = 0; i < indexer.size(); ++i) {
                if(indexer[i]->left != nullptr)
                {
                    nindexer.push_back(indexer[i]->left);
                }

            }
        }


    public:
        tree() {
            root = newNode();
        }

        void _print(){
            std::vector<size_t> counter;
            std::vector<node*> indexer;
            counter.clear();
            counter.push_back(1);
            indexer.clear();
            indexer.push_back(root);
            bfstraverser(counter, indexer);
        }

        /**
         * Destroys the tree to remove an element
         * @param x element to be deleted
         * @return root/nullptr
         */
        void _delete(size_t x)
        {
            node* pointer = root;

            // Keeps track of pointer
            node* hook = pointer;
            std::vector b = int2bool(x);
            b.pop_back();
            for (int i = b.size() - 1; i >= 0 ; --i) {
                // Jump into left subtree
                if (b[i] == 0)
                {
                    // Terminates if the path doesn't exist
                    if(pointer->left == nullptr)
                        return;

                    if(pointer->flag)
                        hook = pointer;

                    pointer = pointer->left;
                }
                else
                {
                    if(pointer->right == nullptr)
                        return;

                    if(pointer->flag)
                        hook = pointer;

                    pointer = pointer->right;
                }

                if(i == 0)
                {
                    pointer->flag = false;
                }
            }

            //  Remove redundant nodes that don't hold any information
            if(!hook->left->flag)
                hook->left = nullptr;

            if(!hook->right->flag)
                hook->right = nullptr;
        }

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
                    //  if left there is no left subtree
                    if(pointer->left == nullptr)
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
    x.print();
}
