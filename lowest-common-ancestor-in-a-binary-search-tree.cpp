class Solution {
public:
	TreeNode *LowestCommonAncestor(TreeNode *root, int val1, int val2) {
		// http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
		//
		// Given values of two nodes in a Binary Search Tree, write a c program to find the 
		// Lowest Common Ancestor. return NULL if either node is not present in BST.

		if (val1 > val2) {
			swap(val1, val2);
		}
		while (root != NULL) {
			int val = root->val;
			if (val > val1 && val > val2) {
				root = root->left;
			}
			else if (val < val1 && val < val2) {
				root = root->right;
			}
			else {
				if (Find(root, val1) == NULL || Find(root, val2) == NULL){
					return NULL;
				}
				break;
			}
		}
		return root;
	}
	TreeNode *Find(TreeNode *root, int val) {
		while (root != NULL) {
			if (root->val == val) {
				return root;
			}
			else if (root->val > val) {
				root = root->left;
			}
			else {
				root = root->right;
			}
		}
		return NULL;
	}
	void test() {
		TreeNode *root = new TreeNode(4);
		root->left = new TreeNode(2);
		root->right = new TreeNode(5);
		root->left->left = new TreeNode(1);
		root->left->right = new TreeNode(3);
		TreeNode *p = LowestCommonAncestor(root, 1, 5);
		cout << p->val << endl;
		p = LowestCommonAncestor(root, 1, 3);
		cout << p->val << endl;
		p = LowestCommonAncestor(root, 0, 3);
		cout << p << endl;
	}
};
