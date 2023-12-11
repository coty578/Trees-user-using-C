#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 25
#define min(a,b) a>b? a:b

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *BTREE = NULL;

BTREE *new_node(int data){
    BTREE*p;
    p = (BTREE*)malloc(sizeof(struct node));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}

void insert(BTREE root,int x){
    if(root == NULL){
        root = new_node(x);
    }
    else{
        if(x <root->data){
            root->left =insert(root->left,x);
        }else{
            root->right = insert(root->right,x);
        }
    }
    return root;
}
void delete_node(BTREE root,int x){
    BTREE p,q;
    if(root == NULL){
        return NULL;
    }
    if(root->data == x){
        if(root->left==root->rift){
            free(root);
        }
        else{
            if(root->left == NULL){
                p = root->right;
                return p;
            }else{
                if(root->right == NULL){
                    p= root->left;
                    return NULL;
                }else{
                    p = q = root->right;
                    while (p->left != NULL)
                    {
                       p = q->left;
                       p->left = root->left;
                       free(root);
                       return q;
                    }
                }
            }
            if(root->data <x){
                root->right = delete_node(root->right,x);
            }else{
                root->left = delete_node(root->left,x);
            }
            return root;
        }
    }
}
int search(BTREE root,int key){
    if(root == NULL){
        return -1;
    }
    BTREE [MAX_SIZE];
    int front = -1;
    int rear = -1;

    queue[front + 1] = root;
    front = rear = 0;
    //do level order traversal to find the deepest node
    while (front <= rear)
    {
        BTREE temp = queue[front];
        front++;
    
    if(temp->data == key){
        return 1;
    }

    if(temp->left != NULL){
        queue[++rear] = temp->left;
    }
    if(temp->right != NULL){
        queue[++rear] = temp->right;
        }
    }
    return -1;
}
int height(BTREE root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    if (left > right)
    {
        return left +1;
    }
    else{
        return right+ 1;
    }

    // inorder Traversal
    void inorder(BTREE root){
        if(root == NULL){return;}
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
    //preorder traversal
    void preoder(BTREE root){
        if(root == NULL){return;}
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    //postorder traversal
    void postorder(BTREE root){
        if(root == NULL){return;}
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
    // finding the minimmun node in a BST
    int BSTmin(BTREE root){
        if(root != NULL){
            while (root->left!= NULL)
            {
                root= root->right;
                return root->data;
            }
        }else{
            return -100;
        }
    }
    // Find the number of node in a bst

    int size(BTREE root){
        if(root == NULL){
            return 0;
        }else{
            return 1 + size(root->left) + size(root->right);
        }
    }
    // Finding thr number of leaves in a BTS

    int leaves(BTREE root){
        if(root ==NULL){
            return 0;
        }else{
            if(root->left == root->right){
                return 1;
            }else{
                return leaves(root->left) + leaves(root->right);
            }
        }
    }

     //level order traversal
    void levelorder(BTREE root){
        if(root == NULL){
            printf("Tree is empty");
            return;
        }
        BTREE queue[MAX_SIZE];
        int front = -1;
        int rear = -1;
        queue[front + 1] = root;
        front = rear = 0;
    
    //do level order traversal to find the deepst node
    while(front <= rear){
        BTREE temp = queue[front];
        front++;

        printf("%d",temp->data);

        if(temp->left!= NULL){
            queue[++rear] = temp ->left;
            }
        if(temp->right!= NULL){
            queue[++rear] = temp->right;
            }
        }
    }
}

int main(){
    int user_choise,node_data;
    char user_active = 'Y';

    while (user_active == 'y' ||user_active == 'Y');
    {
        printf("\n\n-----Binary Tree ---\n\n");
        printf("\n1. insert");
        printf("\n2.delete");
        printf("\n3.search");
        printf("\n4.height");
        printf("\n5.inorder");
        printf("\n6.preonorder");
        printf("\n7.postorder");
        printf("\n8.BSTmin");
        printf("\n9.size");
        printf("\n10.leaves");
        printf("\n11.levelorder");
        printf("\n12.Exit");

        printf("Enter data for new node:");
        scanf("%d",&user_choise);
        printf("\n");

        switch (user_choise)
        {
        case 1:
            printf("Enter data for new node :");
            scanf("%d",&node_data);
            insert(node_data);
            break;
        case 2:
            printf("Enter node data");
            scanf("%d",node_data);
            delete(node_data);
            break;
        case 3:
            printf("Enter node data");
            scanf("%d",node_data);
            int has_found = search(node_data);

            if(has_found == -1){
                printf("\n Node was not found!");
            }else{
                printf("\n node was found");
            }
            break;
        case 4:
            printf("height of the tree is : %d",height(root));
            break;
        case 5:
            root = inorder(root ,9);
            root = inorder(root,12);
            root = inorder(root,14);
            root = inorder(root,17);
            root = inorder(root,19);
            root = inorder(root,23);
            root = inorder(root,54);
            root = inorder(root,67);
            root = inorder(root,72);
            root = inorder(root,76);
            root = inorder(root,50);
            printf("Inorder Traversal\n");
            inorder(root);
            break;
        case 6:
            printf("preorder Traversal\n");
            preorder(root);
            break;
        case 7:
            printf("postorder Traversal\n");
            postorder(root);
            break;
        case 8:
            printf("levelorder Traversal\n");
            levelorder(root);
            break;
        case 9:
        printf("program is terminating....\n");
        exit(0);
        default:
        printf("Invalid choise");
            break;
        }
      fflush(stdin);
      printf("\n\ndo you want to continue?(Y / N)");
      scanf("%c",user_active);
    }
return 0;
}