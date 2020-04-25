#ifndef RBTREE_H
#define RBTREE_H

template<typename T>
class rbTree{
public:
    rbTree()
    {
        m_root = nullptr;
        m_size = 0;
    }

    int getSize() {return m_size;}
    void insert(T obj) {
        Node *n = new Node(obj, COLOR::RED, nullptr, nullptr);
        if (m_root == nullptr) {
            m_root = n;
            n->parent = nullptr;
        } else {
            Node *p = m_root;
            Node *q = nullptr;
            while (p != nullptr) {
                updateSize(p);
                q = p;
                if (p->data < n->data)
                    p = p->right;
                else if (p->data > n->data)
                    p = p->left;
                else // p->data == n->data
                    return;
            }
            m_size++;
            n->parent = q;
            if (q->data < n->data)
                q->right = n;
            else
                q->left = n;
        }
        insert_case1(n);
    }
private:
    enum class COLOR {RED, BLACK};
    struct Node {
        T data;
        COLOR color;
        int size;
        Node* parent;
        Node* left;
        Node* right;
        Node(T _data, COLOR _color, Node* _left, Node* _right)
        {
            data = _data;
            color = _color;
            size = 1;
            left = _left;
            right = _right;
        }
    };

    /* *
     * member variables
     * */

    Node* m_root;
    int m_size;



    Node* grandparent(Node* n)
    {
        if((n != nullptr) && (n->parent != nullptr))
            return n->parent->parent;
        return nullptr;
    }

    Node* uncle(Node* n)
    {
        Node* g = grandparent(n);
        if(g == nullptr)
            return nullptr;
        if(n->parent == g->left)
            return g->right;
        return g->left;
    }

    int nodeSize(Node* n)
    {
        return (n == nullptr) ? 0 : n->size;
    }

    void updateSize(Node* n)
    {
        n->size = nodeSize(n->left) + nodeSize(n->right) + 1;
    }

    void rotate_left(Node* n)
    {
        Node* pivot = n->right;

        pivot->parent = n->parent;
        if(n->parent != nullptr)
        {
            if(n->parent->left == n)
                n->parent->left = pivot;
            else
                n->parent->right = pivot;
        }

        n->right = pivot->left;
        if(pivot->left != nullptr)
            pivot->left->parent = n;

        n->parent = pivot;
        pivot->left = n;
    }

    void rotate_right(Node* n)
    {
        Node* pivot = n->left;

        pivot->parent = n->parent;
        if(n->parent != nullptr){
            if(n->parent->left == n)
                n->parent->left = pivot;
            else
                n->parent->right = pivot;
        }

        n->left = pivot->right;
        if(pivot->right != nullptr)
            pivot->right->parent = n;

        n->parent = pivot;
        pivot->right = n;
    }

    void insert_case1(Node* n)
    {
        if(n->parent == nullptr)
            //вставить
            n->color = COLOR::BLACK;
        else
            insert_case2(n);
    }

    void insert_case2(Node* n)
    {
        if(n->parent->color == COLOR::BLACK)
            return;
        else
            insert_case3(n);
    }

    void insert_case3(Node* n)
    {
        Node* u = uncle(n);
        Node* g;

        if((u != nullptr) && (u->color == COLOR::RED)) {
            n->parent->color = COLOR::BLACK;
            u->color = COLOR::BLACK;
            g = grandparent(n);
            g->color = COLOR::RED;
            insert_case1(g);
        }
        else {
            insert_case4(n);
        }
    }

    void insert_case4(Node* n)
    {
        Node* g = grandparent(n);

        if((n == n->parent->right) && (n->parent == g->left)) {
            rotate_left(n->parent);
            n = n->left;
        }
        else if ((n == n->parent->left) && (n->parent == g->right)) {
            rotate_right(n->parent);
            n = n->right;
        }
        insert_case5(n);
    }

    void insert_case5(Node* n)
    {
        Node* g = grandparent(n);

        n->parent->color = COLOR::BLACK;
        g->color == COLOR::RED;
        if((n == n->parent->left) && (n->parent == g->left)) {
            rotate_right(g);
        } else {
            rotate_left(g);
        }
    }

};

#endif //RBTREE_H
