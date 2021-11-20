#ifndef AVLTREE_H
#define AVLTREE_H

template<typename T>
class AVLTree
{
    struct AVLNode
    {
        T data;
        AVLNode *left;
        AVLNode *right;
        int height;

        AVLNode(const T & data):data(data), left(nullptr), right(nullptr), height(0){}
    };

    private:
        AVLNode *root = nullptr;

    public:
        AVLTree() {}

        void insert(const T & t) {
            root = this->insert(t, root);
        }

        bool isEmpty() {
            return root == nullptr;
        }

        void clear() {
            this->InorderTraversal(root);
        }

        void PreorderTraversal() {
            PreorderTraversal(root);
        }

        bool find(const T & t) {
            return find(t, root);
        }

        ~AVLTree() {
            this->clear();
            root = nullptr;
            cout << "in ~AVLTree" << endl;
        }



    private:
        bool find(const T & t, AVLNode *node)
        {
            if (node == nullptr)
                return false;
            if (node->data == t)
                return true;
            if (node->data < t)
                return find(t, node->right);
            else
                return find(t, node->left);
        }

        void PreorderTraversal(AVLNode *node)
        {
            if (node == nullptr)
                return;
            cout << node->data << " ";
            PreorderTraversal(node->left);
            PreorderTraversal(node->right);
        }

        void InorderTraversal(AVLNode* node)
        {
            if (node == nullptr)
                return;
            InorderTraversal(node->left);
            InorderTraversal(node->right);
            delete node;
        }

        static int height(AVLNode* node) {
            return node == nullptr ? -1 : node->height;
        }

        AVLNode* insert(const T & t, AVLNode* node)
        {
            if (node == nullptr) {
                node = new AVLNode(t);
            } else if (t < node->data) {
                node->left = insert(t, node->left);
                if (height(node->left) - height(node->right) == 2) {
                    if (t < node->left->data) {
                        node = rotateWithLeftChild(node);
                    } else {
                        node = doubleWithLeftChild(node);
                    }
                }
            } else if (t > node->data) {
                node->right = insert(t, node->right);
                if (height(node->right) - height(node->left) == 2) {
                    if (t > node->right->data) {
                        node = rotateWithRightChild(node);
                    } else {
                        node = doubleWithRightChild(node);
                    }
                }
            } else {
                // do nothing
            }
            node->height = max(height(node->left), height(node->right)) + 1;
            return node;
        }

        AVLNode* rotateWithLeftChild(AVLNode* node)
        {
            AVLNode *p;
            p = node->left;
            node->left = p->right;
            p->right = node;
            node->height = max(height(node->left), height(node->right)) + 1;
            p->height = max(height(p->left), height(p->right)) + 1;
            return p;
        }

        AVLNode* rotateWithRightChild(AVLNode* node)
        {
            AVLNode *p;
            p = node->right;
            node->right = p->left;
            p->left = node;
            node->height = max(height(node->left), height(node->right)) + 1;
            p->height = max(height(p->left), height(p->right)) + 1;
            return p;
        }

        AVLNode* doubleWithLeftChild(AVLNode* node)
        {
            node->left = rotateWithRightChild(node->left);
            return rotateWithLeftChild(node);
        }

        AVLNode* doubleWithRightChild(AVLNode* node) {
            node->right = rotateWithLeftChild(node->right);
            return rotateWithRightChild(node);
        }
};

#endif