#include <iostream>
using namespace std;

// Node
struct node {
  int key;
  node *left, *right; // ptr stores mem add
};

// Create alias: tree = *node
// it points to the very first node (root)
typedef struct node *tree;

// Instantiate a tree
void createTree(tree &t) {
  t = NULL;
};

node* createNode(int x) {
    node *data = new node;
    
    // Check if computer OOM => avoid crash
    if (data == NULL) return NULL;
    
    data->key = x;
    data->left = data->right = NULL;
    return data; // return the ptr to this new node
};

bool addNode(tree &t, int x) {
    // find a position to add a node
    if (t != NULL) {
        if (t->key == x) return false; // x already existed
        if (t->key > x) return addNode(t->left, x);
        else return addNode(t->right, x);
        // con tro o tang tren se tro thanh "root" de xet tiep
    }
    // da tim dc vi tri t de them
    t = createNode(x);
    return true;
};

// Duyet truoc NLR
void NLR(tree t) {
    if (t != NULL) {
        cout << t->key << " "; // node
        NLR(t->left); //left
        NLR(t->right);
    }
}

// Duyet giua LNR
void LNR(tree t) {
    if (t != NULL) {
        LNR(t->left); //left
        cout << t->key << " "; // node
        LNR(t->right);
    }
}

node* search(tree t, int x) {
    node *p = t;
    while(p!=NULL) {
        if (p->key == x) return p;
        if (p->key > x) p = p->left;
        else p = p->right;
    }
    return NULL;    // there is no x
}

void replaceNodeY(tree &X, tree &Y) {
    // Y right LOWEST
    if (Y->left != NULL) {
        replaceNodeY(X, Y->left);
    } else {
        X->key = Y->key;
        tree t = Y; // Giữ địa chỉ node cũ để delete
        Y = Y->right;
        delete t;
    }
}

void removeNode(tree &t, int x) {
    // leaf => easy
    // 1 son => like singlyLinkedList
    // 2 son => 1) replace with left HIGHEST or 2) with right LOWEST
    if (t->key > x) {
        removeNode(t->left, x);
    } else {
        if (t->key < x) {
            removeNode(t->right, x);
        } else {
            // DA tim dc vi tri can xoa
            node *d = t;
            // now remove: combined leaf and 1-son cases
            if (t->left == NULL) {
                t = t->right;
            } else if (t->right == NULL) {
                t = t->left;
            } else {
                // has 2 sons
                replaceNodeY(t, t->right);
                return;
            }
            delete d;
        }
    }
}


int main_learn()
{
    tree s;
    createTree(s);
    
    int a[] = {12,8,23,15,2,7,9,3,25,18};
    for (int i=0;i<10;i++) {
        addNode(s, a[i]);
    }
    
    // cout << "Cay duyet TRUOC NLR: ";
    // NLR(s);
    // cout << endl;
    cout << "Cay duyet GIUA LNR: ";
    LNR(s);
    
    // find a key in BST
    int x;
    cout << "\n Enter x to find in the tree: ";
    cin >> x;
    if (search(s, x) == NULL){
        cout << x << " NOT existed !";
    }
    else {
        cout << x << " existed !";
        // function xoa node existed
        char del;
        cout << "Confirm to remove this node ? (y/n): ";
        cin >> del;
        if (del == 'y') {
            // xoa node
            removeNode(s, x);
            
            // duyet cay sau khi xoa
            cout << "Cay duyet GIUA LNR: ";
            LNR(s);
        }
    }
 
    return 0;
}