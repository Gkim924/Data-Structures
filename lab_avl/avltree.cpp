/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

int max(int a, int b) {
  if (a > b) { return a; }
  else       { return b; }
}


template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node * y = t->right;
    t->right = y->left;
    y->left = t;

    //updates node that was brought down/left
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    t = y; //sets t to be node that was brought up
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node * y = t->left;     //rotate right is mirror of rotate left
    t->left = y->right;
    y->right = t;

    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    t = y;
    t->height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;

}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    int balance = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);
    if(balance==2){ //possible L or RL rotation 
        int r_balance = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
        if(r_balance==1){
            rotateLeft(subtree);
        }
        else {
            rotateRightLeft(subtree);
        }
    }
    if(balance==-2){ //possible R or LR rotation 
        int l_balance = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
        if(l_balance==-1){
            rotateRight(subtree);
        }
        else {
            rotateLeftRight(subtree);
        }
    }

    subtree->height = max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right))+1;

}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree==NULL){
        subtree = new Node(key,value);
    }
    else if(key<subtree->key){
        insert(subtree->left,key,value);
    }
    else if(key>subtree->key){
        insert(subtree->right,key,value);
    }
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left,key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right,key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree=NULL;

        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here

            //find IOP value
            Node * search = subtree;
            if(search->left!=NULL){
                search = search->left;
                while(search->right!=NULL){
                    search = search->right;
                }
            }
            //swap node with IOP
            //std::cout<<"IOP of:"<<subtree->key<<" is:"<<search->key<<std::endl;
            swap(subtree,search);
            remove(subtree->left,key);

        } else {
            /* one-child remove */
            // your code here
            if(subtree->left == NULL && subtree->right != NULL){ //remove left child
                Node * temp = subtree;
                subtree = subtree->right;
                delete temp;
            }
            else {
                Node * temp = subtree;
                subtree = subtree->left;
                delete temp;
            }
        }
        // your code here
        rebalance(root);
    }
}