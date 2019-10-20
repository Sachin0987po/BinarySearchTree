#include <iostream>
#include <vector>

using namespace std;

struct node
{
    node* lchild;
    int data;
    node* rchild;

    node(int var) : lchild{ nullptr }, data{ var }, rchild{ nullptr } {
        //node constructed
    }
};

class BST
{
private:
    node* Root;
public:
    
    BST() : Root{ nullptr } {
        // BST
    };

    node* Insert(node* root, int Key) {
        node* new_node;
        if(root == nullptr) {
            new_node = new node(Key);
            Root = root;
            return new_node;
        }
        if(Key < root->data) {
            root->lchild = Insert(root->lchild, Key);
        }
        else if(Key > root->data) {
            root->rchild = Insert(root->rchild, Key);
        }
        return root;
    }

    void inorder(node* root) {
        if( root != nullptr) {
            inorder(root->lchild);
            cout << root->data << " ";
            inorder(root->rchild);
        }
    }

    void Search(node* root, int Key) {
        while(root != nullptr) {
            if(Key == root->data) {
                cout << "Found";
                break;
            }
            else if(Key < root->data) {
                root = root->lchild;
            }
            else {
                root = root->rchild;
            }
        }
    }

    

    void Insert_at_pos(node* root, int Key) {
        node* prev = nullptr;
        while(root != nullptr) {
            prev = root;
            if(Key == root->data) {
                return;
            }
            else if(root->data > Key) {
                root = root->lchild;
            }
            else {
                root = root->rchild;
            }
        }
        node* new_node = new node(Key);
        if(prev->data > Key)
            prev->lchild = new_node;
        else 
            prev->rchild = new_node;
    }

    int Height(node* root) {
        if(root == 0)
            return 0;
        else {
            int x = Height(root->lchild);
            int y = Height(root->rchild);
            if(x > y) 
                return x + 1;
            else 
                return y + 1;
        }
    }
};

int main()
{
    BST Tree;
    node* Root = nullptr;
    
    cout << "\n Enter Size :- ";
    size_t size; cin >> size;
    
    vector<int> vec;
    vec.reserve(size);

    for(int i = 0; i < size; i++) {
        int x; cin >> x;
        vec.push_back(x);
    }

    Root = Tree.Insert(Root, vec[0]);
    for(int i = 1; i < vec.size(); i++)
        Tree.Insert(Root, vec[i]);

    cout << "\nInorder Traversal is :- \n";
    cout << '['; Tree.inorder(Root); cout << ']';

    cout << "\n\nEnter num :- ";
    int Key; cin >> Key;
    Tree.Search(Root, Key);

    cout << "\nEnter Element :- ";
    int element; cin >> element;
    Tree.Insert_at_pos(Root, element);
    cout << '['; Tree.inorder(Root); cout << ']';

    cout << "\n\nHeight of Tree :- " << Tree.Height(Root) - 1;

    return 0;
}
