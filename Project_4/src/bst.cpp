#include "bst.h"

BST::BST() = default;
BST::~BST() { clear(root_); }

void BST::clear(Node* n) {
    if (!n) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

// TODO: Implement insert (ignore duplicate)
BST::Node* BST::insertNode(Node* n, const ItemHandle& v, bool& added) {
    // (void)n; (void)v; added = false;
    //STUB
    if (n == nullptr){
        added = true;
        return new Node(v);
    }
    if (v == n->val){
        added = false;
        return n;
    }
    if (v < n->val){
        n->left = insertNode(n->left, v, added);
    }
    else{
        n->right = insertNode(n->right, v, added);
    }
    return n;
}

void BST::insert(const ItemHandle& v) {
    bool added = false;
    root_ = insertNode(root_, v, added);
    if (added) ++size_;
}

// TODO: Implement contains
bool BST::containsNode(Node* n, const ItemHandle& v) {
    //(void)n; (void)v;
    if(n == nullptr) return false;
    if(n != nullptr){
        if(n->val == v) return true;
        else if(n->val < v){
            return containsNode(n->right, v);
        }
        else{ // n->val > v
            return containsNode(n->left, v);
        }
    }
    return true; // STUB
}
bool BST::contains(const ItemHandle& v) const { return containsNode(root_, v); }

// TODO: Implement inorder traversal
void BST::inorderWalk(Node* n, std::vector<ItemHandle>& out) {
    (void)n; (void)out;
    if(n != nullptr){
        inorderWalk(n->left, out);
        out.push_back(n->val);
        inorderWalk(n->right, out);
    }
}
void BST::inorder(std::vector<ItemHandle>& out) const { out.clear(); inorderWalk(root_, out); }

// TODO: Implement validity check (strict BST)
bool BST::isValid(Node* n, const ItemHandle* lo, const ItemHandle* hi) {
    // (void)n; (void)lo; (void)hi;
    if (n == nullptr) {
           return true;
       }
       if (lo != nullptr && !(*lo < n->val)){
           return false;
       }
       if (hi != nullptr && !(n->val < *hi)){
           return false;
       }
       return isValid(n->left, lo, &n->val) && isValid(n->right, &n->val, hi);
}
bool BST::isValidBST() const { return isValid(root_, nullptr, nullptr); }

// Helper for two-child delete (successor)
BST::Node* BST::detachMin(Node* n, Node*& minNode) {
    // STUB for now
    if(n->left == nullptr){
        minNode = n;
        return n->right;
    }
    
    n->left = detachMin(n->left, minNode);
    return n;
}

// TODO: Implement erase (leaf / one child / two children via successor)
BST::Node* BST::eraseNode(Node* n, const ItemHandle& v, bool& erased) {
    //(void)n; (void)v; erased = false;
    if (n == nullptr){
        erased = false;
        return nullptr;
    }
    if (v < n->val){
        n->left = eraseNode(n->left, v, erased);
        return n;
    }
    else if (n->val < v){
        n->right = eraseNode(n->right, v, erased);
        return n;
    }
    erased = true;
    
    //Leaf
    if(n->left == nullptr && n->right == nullptr){
        delete n;
        return nullptr;
    }
    
    //One child
    if(n->left == nullptr && n->right != nullptr){
        Node* right = n->right;
        delete n;
        return right;
    }
    if(n->left != nullptr && n->right == nullptr){
        Node* left = n->left;
        delete n;
        return left;
    }
    
    //Two Children
    Node* successor = nullptr;
    n->right = detachMin(n->right, successor);

    successor->left = n->left;
    successor->right = n->right;

    delete n;
    return successor;
}

bool BST::erase(const ItemHandle& v) {
    bool erased = false;
    root_ = eraseNode(root_, v, erased);
    if (erased) --size_;
    return erased;
}
