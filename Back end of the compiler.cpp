#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char* value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(char* value, TreeNode* left, TreeNode* right) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void generateAssembly(TreeNode* node) {
    if (node == NULL)
        return;

    if (node->value != NULL) {
        printf("%s\n", node->value);
    }

    generateAssembly(node->left);
    generateAssembly(node->right);
}

int main() {
    TreeNode* root = createNode("MOV R1, #10", NULL, NULL);
    TreeNode* node1 = createNode("MOV R2, #20", NULL, NULL);
    TreeNode* node2 = createNode("ADD R3, R1, R2", NULL, NULL);
    root->left = node1;
    root->right = node2;

    printf("Assembly code generated:\n");
    generateAssembly(root);

    return 0;
}

