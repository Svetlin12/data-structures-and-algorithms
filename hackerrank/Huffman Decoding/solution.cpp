/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/

bool isLeaf(node* node) {
    return node->left == NULL && node->right == NULL;
}

void decode_huff(node * root, string s) {
    node* traverse = root;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') 
            traverse = traverse->left;
        else
            traverse = traverse->right;
        
        if (isLeaf(traverse)) {
            cout << traverse->data;
            traverse = root;
        }
    }
    cout << endl;
}
