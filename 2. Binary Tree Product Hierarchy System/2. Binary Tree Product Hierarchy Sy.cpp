/*2. Product Hierarchy System: Representation via Binary Tree
Envision a huge online store with a huge selection of goods. The platform uses a hierarchical structure to efficiently arrange these items for simple management and client navigation. By grouping products into categories and subcategories, this hierarchy creates a structure like a tree.

Comprehending the Binary Tree
The product hierarchy in this system is represented by a Binary Tree. Every node in the tree represents a category, and it is associated with both a left and a right subcategory.

Typical Situation
To help you visualize this concept better, let's look at an example. Let's look at the top category, "Electronics." There are more subcategories within this category, like "Computers" and "Smartphones." Subcategories within each of these subcategories may then exist.


One could further divide "computers" into "laptops" and "desktops."
The terms "smartphones" may also refer to "Android" and "iOS."
This branching keeps going until we get to the last level of categories, which stand for particular kinds of things or products in general.

Visualizing the Binary Tree
Here's how the hierarchy would look in the form of a Binary Tree:
                          Electronics
                        /             \
                 Computers          Smartphones
                /         \         /           \
           Laptops     Desktops  Android         iOS
          /     \       /       /      \        /    \
      ...       ...   ...      ...    ...     ...   ...

The Binary Tree Structure's Advantages
Effective Navigation: It's simple for customers to browse the many product categories. Customers who are interested in smartphones, for example, can go to Electronics -> Smartphones -> Android/iOS.

Scalability: There is much scalability in the system. It is possible to create new categories and subcategories without affecting the current hierarchy.

Manage Products More Organizedly: Platform administrators find that managing products becomes more organized. Every category may possess a unique combination of characteristics and traits.

Search Optimization: By offering pertinent categories and subcategories, the hierarchy can assist clients in finding products by optimizing search results.

Considerations for Implementation
Each node in the binary tree would correspond to a category in programming terminology. It would include details like the product listings, connections to subcategories, category names, etc. The e-commerce platform's product hierarchy may be traversed and managed more effectively thanks to this data structure.

In summary

To put it briefly, the Binary Tree representation of the Product Hierarchy System is an effective tool for arranging and browsing the wide range of products on an e-commerce platform. It offers a methodical, effective, and expandable approach to product classification, improving platform administration and client experience.

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
/*
Actual Situation: Take into consideration an e-commerce platform that arranges items in a hierarchy for simple handling and navigation. There may be subcategories within each category, creating a tree structure. For instance, the category "Electronics" may subdivide into "Computers" and "Smartphones," each of which could further subdivide into "Laptops," "Desktops," and "Android," "iOS," and so on. This hierarchy can be represented as a binary tree, in which every node is a category connected to two subcategories.

Data Structure Suitability: The product hierarchy method works well with a binary tree because

It enables a hierarchical category structure, simulating how things are categorized in the real world.
If the tree is balanced, searching for a certain category or product can be effective.

It makes navigating between categories easier by representing binary choices or categorizations at each level.
Given its ability to facilitate rapid category insertion, deletion, and search, a binary tree makes sense for the product hierarchy.
Additionally, it replicates the product classification hierarchy, which makes it easy to move between categories and subcategories.*/
