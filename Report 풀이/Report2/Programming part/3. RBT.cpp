#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef struct _Node {
    int data;
    char color;
    struct _Node* left;
    struct _Node* right;
    struct _Node* parent;
} Node;
typedef struct {
    Node* root;
    Node* T_nil;
}Tree;

void Left_Rotate(Node** root, Node* x)
{
    //y stored pointer of right child of x
    Node* y = x->right;

    //store y's left subtree's pointer as x's right child
    x->right = y->left;

    //update parent pointer of x's right
    if (x->left != NULL)
        x->left->parent = x;

    //update y's parent pointer
    y->parent = x->parent;

    // if x's parent is null make y as root of tree
    if (x->parent == NULL)
        (*root) = y;

    // store y at the place of x
    else if (x == x->parent->left)
        x->parent->left = y;
    else x->parent->right = y;

    // make x as left child of y
    y->left = x;

    //update parent pointer of x
    x->parent = y;
}
void Right_Rotate(Node** root, Node* x)
{
    //y stored pointer of right child of x
    Node* y = x->left;

    //store y's left subtree's pointer as x's right child
    x->left = y->right;

    //update parent pointer of x's right
    if (x->right != NULL)
        x->right->parent = x;

    //update y's parent pointer
    y->parent = x->parent;

    // if x's parent is null make y as root of tree
    if (x->parent == NULL)
        (*root) = y;

    // store y at the place of x
    else if (x == x->parent->right)
        x->parent->right = y;
    else x->parent->left = y;

    // make x as left child of y
    y->right = x;

    //update parent pointer of x
    x->parent = y;
}
void RB_Insert_Fixup(Node** root, Node* z) {
    while (z->parent->color == 'R') {
        printf("1\n");
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            printf("2\n");
            if (y->color == 'R') {
                printf("3\n");
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }
            else if (z == z->parent->right) {
                printf("4\n");
                z = z->parent;
                Left_Rotate(root, z);
            }
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            Right_Rotate(root, z->parent->parent);
        }
        else {
            printf("5\n");
            Node* y = z->parent->parent->left;

            if (y->color == 'R') {
                printf("6\n");
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }
            else if (z == z->parent->left) {
                printf("7\n");
                z = z->parent;
                Right_Rotate(root, z);
            }
            printf("8\n");
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            Left_Rotate(root, z->parent->parent);
        }
    }
    (*root)->color = 'B';
}
int RB_Insert(Node** root, int data) {
    Node* z = (Node*)malloc(sizeof(Node));
    z->data = data;
    z->left = z->right = z->parent = NULL;

    //if root is null make z as root
    if (*root == NULL) {
        z->color = 'B';
        (*root) = z;
    }
    else {
        Node* y = NULL;
        Node* x = (*root);

        // Follow standard BST insert steps to first insert the node
        while (x != NULL) {
            y = x;
            if (z->data < x->data) x = x->left;
            else if (z->data > x->data) x = x->right;
            else return 0;
        }
        z->parent = y;
        if (z->data > y->data)
            y->right = z;
        else
            y->left = z;
        z->color = 'R';
        //RB_Insert_Fixup(root, z);
    }
    return 1;
}
void RB_Transplant(Node** root, Node* u, Node* v) {
    if (u->parent == NULL) *root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    v->parent = u->parent;
}
void RB_Delete_Fixup(Node** root, Node* x) {
    Node* w = NULL;

    while ((x != *root) && (x->color == 'B')) {
        if (x == x->parent->left) {
            w = x->parent->right;

            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                Left_Rotate(root, x->parent);
                w = x->parent->right;
            }

            if (w->left->color == 'B' && w->right->color == 'B') {
                w->color = 'R';
                x = x->parent;
            }

            else if (w->right->color == 'B') {
                w->left->color = 'B';
                w->color = 'R';
                Right_Rotate(root, w);
                w = x->parent->right;
            }

            if (w->right->color == 'R') {
                w->color = x->parent->color;
                w->right->color = 'B';
                x->parent->color = 'B';
                Left_Rotate(root, x->parent);
                x = *root;
            }
        }
        else {
            w = x->parent->left;

            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                Right_Rotate(root, x->parent);
                w = x->parent->left;
            }

            if (w->right->color == 'B' && w->left->color == 'B') {
                w->color = 'R';
                x = x->parent;
            }

            else if (w->left->color == 'B') {
                w->right->color = 'B';
                w->color = 'R';
                Left_Rotate(root, w);
                w = x->parent->left;
            }

            if (w->left->color == 'R') {
                w->color = x->parent->color;
                w->left->color = 'B';
                x->parent->color = 'B';
                Right_Rotate(root, x->parent);
                x = *root;
            }
        }
    }
    x->color = 'B';
}
void RB_Delete(Node** root, int data) {
    Node* target = *root; // the node that we want to remove.
    Node* y = NULL; // the node that is moved or removed.
    Node* x = NULL; // temp's original position

    // find the node that has the key
    while (data != target->data) {
        if (target->data > data) target = target->left;
        else target = target->right;
    }
    char y_original_color = target->color;

    if (target->left == NULL) {
        x = target->right;
        RB_Transplant(root, target, target->right);
    }

    else if (target->right == NULL) {
        x = target->left;
        RB_Transplant(root, target, target->left);
    }
    else {
        y = target->right;

        // find the minimum key
        while (y->left != NULL) y = y->left;
        y_original_color = y->color;
        x = y->right;

        if (y->parent == target) x->parent = y;
        else {
            RB_Transplant(root, y, y->right);
            y->right = target->right;
            y->right->parent = y;
        }
        RB_Transplant(root, target, y);
        y->left = target->left;
        y->left->parent = y;
        y->color = target->color;
    }
    if (y_original_color == 'B') RB_Delete_Fixup(root, x);
}
void Print_BST(Node* root) {
    if (root == NULL) return;
    Print_BST(root->left);
    printf("%d ", root->data);
    Print_BST(root->right);
}
int main() {
    Node *root = NULL;
    srand((unsigned)time(NULL));
    int A[20];
    for (int i = 0; i < 20; i++) {
        A[i] = rand() % 50;
        RB_Insert(&root, A[i]);
    }
    RB_Insert(&root, 2);
    printf("Print_BST Is : ");
    Print_BST(root);
    printf("\n");
    RB_Insert(&root, 22);
    printf("Print_BST Is : ");
    Print_BST(root);
    printf("\n");
    RB_Insert(&root, 13);
    printf("Print_BST Is : ");
    Print_BST(root);
    printf("\n");
    RB_Insert(&root, 47);
    printf("Print_BST Is : ");
    Print_BST(root);
    printf("\n");
    RB_Insert(&root, 36);
    printf("Print_BST Is : ");
    Print_BST(root);
    printf("\n");

    RB_Delete(&root, 6);
    printf("Print_BST Is : ");
    Print_BST(root);
    printf("\n");
    RB_Delete(&root, 17);
    printf("Print_BST Is : ");
    Print_BST(root);
    printf("\n");
    RB_Delete(&root, 21);
    printf("Print_BST Is : ");
    Print_BST(root);
    printf("\n");
    RB_Delete(&root, 7);
    printf("Print_BST Is : ");
    Print_BST(root);
    printf("\n");
    RB_Delete(&root, 45);
    printf("Print_BST Is : ");
    Print_BST(root);
    printf("\n");
    return 0;
}