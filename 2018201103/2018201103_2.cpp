#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct avl_node{
    int data;
    struct avl_node *right;
    struct avl_node *left;
};

vector<int> in;
avl_node* rotateLeft(avl_node* );
avl_node* rotateRight(avl_node* );
avl_node* rotateLeftThanRight(avl_node* );
avl_node* rotateRightThanLeft(avl_node* );
int height(avl_node* );

avl_node* restructure(avl_node* node, int value){

    
    int balance_factor = height(node->left) - height(node->right);
   
    if(balance_factor < -1 && value > node->right->data){
        //RR
        return rotateLeft(node);
    }
    
    if(balance_factor < -1 && value < node->right->data){
        //RL
        return rotateRightThanLeft(node);
    }

    if(balance_factor > 1 && value > node->left->data){
        //LR
        return rotateLeftThanRight(node);
    }

    if(balance_factor > 1 && value < node->left->data){
        //LL
        avl_node* d=rotateRight(node);
        return d;
    }
    return node;

}

avl_node* insert(avl_node* node, int value){
    if(node==NULL){
        node = new avl_node;
        node->data=value;
        node->left=NULL;
        node->right=NULL;

        return node;
    }
    else if(node->data > value){
        node->left=insert(node->left, value);
        node=restructure(node, value);
    }
    else if(node->data < value){
        node->right=insert(node->right, value);
        node=restructure(node, value);
    }
    
    return node;
}

avl_node* rotateRight(avl_node* node){
    avl_node* nodeleft=node->left;
    avl_node* nodeleftright=nodeleft->right;

    nodeleft->right=node;
    node->left=nodeleftright;

    return nodeleft;
}

avl_node* rotateLeft(avl_node* node){
    avl_node* noderight=node->right;
    avl_node* noderightleft=noderight->left;

    noderight->left=node;
    node->right=noderightleft;

    return noderight;
}

avl_node* rotateLeftThanRight(avl_node* node){
    node->left=rotateLeft(node->left);
    return rotateRight(node);
}

avl_node* rotateRightThanLeft(avl_node* node){
    node->right=rotateRight(node->right);
    return rotateLeft(node);
}

void display(avl_node *ptr, int level, avl_node *root)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1, root);
        cout<<endl;
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1, root);
    }
}

void preOrder(avl_node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int height(avl_node* node){
    if(node==NULL) return 0;
    return 1+max(height(node->left), height(node->right));
}

avl_node* search(avl_node* node, int value){
    if(node == NULL || node->data == value){
        return node;
    }
    else if(node->data > value){
        return search(node->left, value);
    }
    else if(node->data < value){
        return search(node->right, value);
    }  
    return NULL;
}

void inorder(avl_node* node){

    if(node!=NULL){
        inorder(node->left);
        in.push_back(node->data);
        inorder(node->right);
    }
}

void findKthMin(avl_node* node, int k){
    inorder(node);
}

avl_node* deleteNode(avl_node* node, int value){
    if(node == NULL){
        return node;
    }

    if(node->data < value ){
        node->right = deleteNode(node->right, value);
    }
    else if(node->data > value){
        node->left = deleteNode(node->left, value);
    }
    else{
        if (node->left == NULL){
            avl_node *t = node->right;
            free(node);
            return t;
        }
        else if (node->right == NULL)
        {
            avl_node *t = node->left;
            free(node);
            return t;
        }
 
        avl_node* t = node->right;

        while(t->left != NULL){
            t=t->left;
        }
 
        node->data = t->data;
 
        node->right = deleteNode(node->right, node->data);
    }

    if (node == NULL)
      return NULL;

    int balance_factor = height(node->left) - height(node->right);

    if (balance_factor > 1 && (height(node->left->left) - height(node->left->right)) >= 0){
        return rotateRight(node);
    }

    if (balance_factor > 1 && (height(node->left->left) - height(node->left->right)) < 0){
        return rotateLeftThanRight(node);
    }
 
    if (balance_factor < -1 && (height(node->right->left) - height(node->right->right)) <= 0){
        return rotateLeft(node);
    }

    if (balance_factor < -1 && (height(node->right->left) - height(node->right->right)) <= 0){
        return rotateRightThanLeft(node);
    }
 
    return node;

}

int main(){
    avl_node *root = NULL;
    
    int n,m;
    cin>>n>>m;

    while(n--){
        int a;
        cin>>a;

        root=insert(root,a);
    }

    while(m--){
        int q,x;
        cin>>q>>x;

        switch(q){
            case 1: root=insert(root,x);
                    break;

            case 2: if(search(root,x)==NULL) cout<<"0"<<endl;
                    else cout<<"1"<<endl;
                    break;
            
            case 3: findKthMin(root, x);
                    cout<<in[x-1]<<endl;
                    deleteNode(root, in[x-1]);
                    break;
        }
    }

    return 0;
}
