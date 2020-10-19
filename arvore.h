#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct node{
    int key;
    int data;

    int height;

    struct node* left;
    struct node* right;
}node;

node* new_node(int key, int data);
int max(int a, int b);
int height(node* p);
void recalc(node* p);
node* rotate_right(node* p);
node* rotate_left(node* p);
node* balance(node* p);
node* search(node* p, int key);
node* insert(node* p, int key, int data);
node* find_min(node* p);
node* remove_min(node* p);
node* remove_item(node* p, int key);
void free_tree(node* p);
void aux_pos_ordem(node *aux);



#endif // ARVORE_H_INCLUDED
