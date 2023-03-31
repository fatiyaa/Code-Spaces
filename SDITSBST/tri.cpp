#include <iostream>
using namespace std;

typedef unsigned long long ull;

class Node{
    public:
        ull key;
        ull index=1;
        Node*left, *right;
};

class BST{
    public:
        BST();
        ull search(ull value);
        void insert(ull value);

    private:
        Node * root;
        ull find(ull value, Node* tree, ull & counter);
        void _maketree(ull value, Node *&tree);
};

BST::BST(){
    root=NULL;
}

ull BST::find(ull value, Node* tree, ull & counter){
    if (tree==NULL) return 0;
    else if(tree->key==value){
        return counter+tree->index;
    }
    else if(value>tree->key){
        return(find(value,tree->left,counter));
    }
    else if(value<tree->key){
        counter+=tree->index;
        return(find(value,tree->right, counter));
    }
    return 0;
}

ull BST::search(ull value){
    ull counter=0;
    counter=find(value, root, counter);
    return counter;
}

void BST::_maketree (ull value, Node *&tree){
    if(tree==NULL){
        tree = new Node;
        tree->key=value;
        tree->left= NULL;
        tree->right=NULL;
        return;
    }
    else if(value==tree->key) return;
    else if(value>tree->key){
        tree->index++;
        return(_maketree(value, tree->left));
    }
    else if(value<tree->key){
        return(_maketree(value, tree->right));
    }
}

void BST::insert(ull value){
    return(_maketree(value,root));
}

int main(){
    BST tree;
    int tcase;
    cin>>tcase;
    while(tcase--){
        int cmd;
        ull num;
        cin>>cmd>>num;
        if(cmd==1){
            tree.insert(num);
        }
        else{
            ull fin=tree.search(num);
            if(fin==0) cout<<"Data tidak ada"<<endl;
            else cout<<fin<<endl;
        }
    }
    return 0;
}