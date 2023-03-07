/**************************************************************************
 * Joel Brigida
 * COP3530: Data Structures
 * This is a CLASS implementation of the Binary Search Tree ADT.
**************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class treenode							// Class for each node of the tree
{
	public:

		string info;
		treenode *lchild, *rchild;		// Pointers to BST Child Nodes
};

class BST								// Class for the BST containing treenodes
{
	public:

		BST() { root = 0; }				// Default Constructor (inline implementation)
		~BST();
		bool empty();
		void insert(string item );
		void insert_aux(treenode*&, string item );
		void del(string item );
		void del_aux(treenode*& loc_ptr, string item );
		treenode* search_tree_aux(treenode*, string item );
		treenode* search_tree(string item);
		treenode* inorder_succ(treenode* );
		void print_tree();
		void print_tree_aux(treenode* );

	private:
		treenode *root;					// points to the root (topmost) node of the search tree

};

/*****************************************************************
Function Name: empty()
Description: Check if the Tree is empty. Note that empty would be 
defined as having a null root node.
*****************************************************************/
bool BST::empty()
{
	return (root == 0);
}

/*****************************************************************
Function Name: insert()
Description: Inserts another node starting at the root node of
the Binary Search Tree.
*****************************************************************/
void BST::insert(string item)
{
	insert_aux(root, item);
}

/*****************************************************************
Function Name: insert_aux()
Description: Auxiliary Function which inserts a node into 
the Binary Search Tree.
*****************************************************************/
void BST::insert_aux(treenode*& loc_ptr, string item)
{
	if (loc_ptr == 0)
		{
			loc_ptr = new treenode;
			loc_ptr->lchild = loc_ptr->rchild = 0;
			loc_ptr->info = item;
		}
	else if (loc_ptr->info > item)
		insert_aux(loc_ptr->lchild, item);
	else if (loc_ptr->info < item)
		insert_aux(loc_ptr->rchild, item);
	else
		cout << "This item is already in the tree" << endl;
}

/*****************************************************************
Function Name: search_tree()
Description: Accessor Function which searches the tree for 'item'
starting at the root node.
*****************************************************************/
treenode* BST::search_tree(string item)
{
	return search_tree_aux(root, item);
}

/*****************************************************************
Function Name: search_tree_aux()
Description: Function which searches the tree for 'item'
starting at the given location pointer.
*****************************************************************/
treenode* BST::search_tree_aux(treenode* loc_ptr, string item)
{
	if (loc_ptr != 0)
		{
			if (loc_ptr->info == item)
				return loc_ptr;
			else if (loc_ptr->info>item)
				return search_tree_aux(loc_ptr->lchild, item);
			else
				return search_tree_aux(loc_ptr->rchild, item);
		}
	else
		return loc_ptr;
}

/*****************************************************************
Function Name: del()
Description: Function which deletes the specified 'item' starting
at the search node.
*****************************************************************/
void BST::del(string item)
{
	del_aux(root, item);
}

/*****************************************************************
Function Name: del_aux()
Description: Function which deletes the node specified by loc_ptr
*****************************************************************/
void BST::del_aux(treenode*& loc_ptr, string item)
{
	if (loc_ptr == 0)
		cout << "Item Not in Tree" << endl;
	
	else if (loc_ptr->info > item)
		del_aux(loc_ptr->lchild, item);			// recursive call to delete left child

	else if (loc_ptr->info < item)
		del_aux(loc_ptr->rchild, item);			// recursive call to delete right child
	
	else
	{
		treenode *ptr;

		if (loc_ptr->lchild == 0)				// if node has no Left Child
			{
				ptr = loc_ptr->rchild;
				delete loc_ptr;
				loc_ptr = ptr;
			}
		else if (loc_ptr->rchild == 0)			// if node has no Right Child
			{
				ptr = loc_ptr->lchild;
				delete loc_ptr;
				loc_ptr = ptr;
			}
		else
			{
				ptr = inorder_succ(loc_ptr);	// find in-order sucessor node
				loc_ptr->info = ptr->info;
				del_aux(loc_ptr->rchild, ptr->info);
			}
	}
}

/*****************************************************************
Function Name: inorder_succ()
Description: This function searches the BST for the next ordered
node. It returns a pointer to that node. If that node does not
exist than it will return a null pointer.
*****************************************************************/
treenode* BST::inorder_succ(treenode* loc_ptr)
{
	treenode *ptr = loc_ptr->rchild;

	while (ptr->lchild != 0)
		{
			ptr = ptr->lchild;
		}
	return ptr;
}

/*****************************************************************
Function Name: inorder_succ()
Description: This function searches the BST for the next ordered
node. It returns a pointer to that node. If that node does not
exist than it will return a null pointer.
*****************************************************************/
void BST::print_tree()
{
	print_tree_aux(root);
}

/*****************************************************************
Function Name: inorder_succ()
Description: This function searches the BST for the next ordered
node. It returns a pointer to that node. If that node does not
exist than it will return a null pointer.
*****************************************************************/
void BST::print_tree_aux(treenode* loc_ptr)
{
	if (loc_ptr != 0)
		{
			print_tree_aux(loc_ptr->lchild);
			cout << loc_ptr->info << endl;
			print_tree_aux(loc_ptr->rchild);
		}
}

/*****************************************************************
Function Name: ~BST
Description: Class Destructor. Deallocates the entire BST.
*****************************************************************/
BST::~BST()
{
	while (root != 0)
		{
			del(root->info);
		}
}


// Main Driver Program
int main()
{
	BST B; // Binary Search Tree Object Declaration.
	//treenode *root1=0, *root2=0;
	
	string s;
	char ch;
	string key3;
	string key4;
	string response;
	string r1, r2;

	cout << "Enter Command: c = count, i = insert item, s = search tree," << endl
		 << "d = delete item, p = print tree, r = range, e = exit: ";
	cin >> ch;
	cout << endl;

	while (ch != 'e')
		{
			switch (ch)
				{
					case 'i':
						cout << "Enter string to insert: ";
						cin >> s;
						B.insert(s);
						break;

					case 's':
						cout << "Enter word to search for: ";
						cin >> s;
						if (!B.search_tree(s))
							cout << s << " not in tree" << endl;
						else
							cout << s << " was found in the tree" << endl;
						break;

					case 'd':
						cout << "Enter Word to Delete: ";
						cin >> s;
						B.del(s);
						break;

					case 'p':
						cout << "*** Printing Tree ***" << endl;
						B.print_tree();
						break;

					default:
						break;
				}
			cout << "Enter command:" << endl;
			cout << "i = insert item, s = search tree, d = delete item, p = print tree, e = exit: ";
			cin >> ch;
			cout << endl;
		}
	cout << endl << "Binary Search Tree has been deallocated...Goodbye" << endl;
	return 0;
}