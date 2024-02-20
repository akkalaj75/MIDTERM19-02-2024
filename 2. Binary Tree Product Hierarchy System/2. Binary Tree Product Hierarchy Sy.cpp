/*2. Product Hierarchy System: Binary Tree
Actual Situation: Take into consideration an e-commerce platform that arranges items in a hierarchy for simple handling and navigation. There may be subcategories within each category, creating a tree structure. For instance, the category "Electronics" may subdivide into "Computers" and "Smartphones," each of which could further subdivide into "Laptops," "Desktops," and "Android," "iOS," and so on. This hierarchy can be represented as a binary tree, in which every node is a category connected to two subcategories.

Data Structure Suitability: The product hierarchy method works well with a binary tree because

It enables a hierarchical category structure, simulating how things are categorized in the real world.
If the tree is balanced, searching for a certain category or product can be effective.

It makes navigating between categories easier by representing binary choices or categorizations at each level.

Binary Tree Code for Product Hierarchy System:*/

#include <iostream>
#include <string>
using namespace std;

// Node structure for a binary tree
struct CategoryNode {
    string category;
    CategoryNode* left;
    CategoryNode* right;

    CategoryNode(string category) : category(category), left(nullptr), right(nullptr) {}
};

// Binary Tree class for the product hierarchy
class ProductHierarchy {
private:
    CategoryNode* root;

    // Helper function to add a category in the binary tree
    void addCategoryHelper(CategoryNode*& node, string category) {
        if (node == nullptr) {
            node = new CategoryNode(category);
        }
        else if (category < node->category) {
            addCategoryHelper(node->left, category);
        }
        else {
            addCategoryHelper(node->right, category);
        }
    }

    // Helper function to display the categories
    void displayCategoriesHelper(CategoryNode* node) {
        if (node != nullptr) {
            displayCategoriesHelper(node->left);
            cout << node->category << endl;
            displayCategoriesHelper(node->right);
        }
    }

public:
    ProductHierarchy() : root(nullptr) {}

    // Function to add a category to the hierarchy
    void addCategory(string category) {
        addCategoryHelper(root, category);
    }

    // Function to display all categories
    void displayCategories() {
        displayCategoriesHelper(root);
    }

    // Destructor to clean up memory
    ~ProductHierarchy() {
        // Implement a destructor to delete all nodes and prevent memory leak
    }
};

// Main function to demonstrate the ProductHierarchy class
int main() {
    ProductHierarchy myHierarchy;
    myHierarchy.addCategory("Electronics");
    myHierarchy.addCategory("Books");
    myHierarchy.addCategory("Clothing");

    cout << "Product Categories:\n";
    myHierarchy.displayCategories();

    return 0;
}
/*Given its ability to facilitate rapid category insertion, deletion, and search, a binary tree makes sense for the product hierarchy.
Additionally, it replicates the product classification hierarchy, which makes it easy to move between categories and subcategories.*/

