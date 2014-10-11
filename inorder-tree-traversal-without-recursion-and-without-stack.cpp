class Solution {
public:
	void MorrisTraversal(TreeNode *root, void(*visit)(TreeNode*)) {
		// http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
		//
		// Using Morris Traversal, we can traverse the tree without using stack and recursion. 
		// The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, 
		// we first create links to Inorder successor and print the data using these links, 
		// and finally revert the changes to restore original tree. 

		TreeNode *current = root;
		while (current != NULL) {
			if (current->left == NULL) {
				visit(current);
				current = current->right;
			}
			else {
				// Find the inorder predecessor of current
				TreeNode *pre = current->left;
				while (pre->right != NULL && pre->right != current) {
					pre = pre->right;
				}
				// Make current as right child of its inorder predecessor 
				if (pre->right == NULL) {
					pre->right = current;
					current = current->left;
				}
				else {
					// Revert the changes made in if part to restore the original 
					// tree i.e., fix the right child of predecssor
					pre->right = NULL;
					visit(current);
					current = current->right;
				}
			}
		}
	}
	void test() {
		TreeNode *root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->left = new TreeNode(4);
		root->left->right = new TreeNode(5);
		MorrisTraversal(root, &display);
	}
	static void display(TreeNode *p) {
		cout << p->val << endl;
	}
};
