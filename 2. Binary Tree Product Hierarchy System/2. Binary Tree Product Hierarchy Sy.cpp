/*2. Binary Tree: Product Hierarchy System
Real-Life Scenario: Consider an e-commerce platform that categorizes products into a hierarchy for easy navigation and management. Each category can have subcategories, forming a tree structure. For example, "Electronics" might branch into "Computers" and "Smartphones," each of which could have further subdivisions like "Laptops," "Desktops," and "Android," "iOS" phones, respectively. A binary tree can represent this hierarchy, where each node is a category that links to two subcategories.

Data Structure Suitability: A binary tree is ideal for the product hierarchy system because:

It allows for hierarchical organization of categories, which mirrors the real-world categorization of products.
Searching for a specific category or product can be efficient if the tree is balanced.
It can represent binary decisions or categorizations at each level, simplifying the navigation through categories.

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
/*A binary tree is suitable for the product hierarchy as it enables quick search, insertion, and deletion of categories.
It also mirrors the hierarchical nature of product categorization, making it intuitive to navigate through categories and subcategories.*/

