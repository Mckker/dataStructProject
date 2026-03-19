#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
using namespace std;

class Product {

private:
    int productID;
    string productName;
    double price; 
public:
    //Default constructor
    Product() {
        productID = 0;
        productName = "";
        price = 0.0;
    }
    //primary constructor
    Product(int id, string name, double p) {
        productID = id;
        productName = name;
        price = p;
    }
    //copy constructor
    Product(const Product& p) {
        productID = p.productID;
        productName = p.productName;
        price = p.price;
    }

    //setters and getters
    void setProductID(int id) {productID = id;}
    void setProductName(string name) {productName = name;}
    void setPrice(double p) {price = p;}
    int getProductID() {return productID;}
    string getProductName() {return productName;}
    double getPrice() {return price;}

    //display product details
    void displayProductDetails() {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: $" << price << endl;
    }
};

    /*
    ---------------------------------------------------------------------------------------
    NODE CLASS FOR LINKED LIST OF PRODUCTS
    ---------------------------------------------------------------------------------------
    */
class Node {
        
    public:
        Product Data;
        Node* nextNode;

        //Default constructor
        Node(): Data() {
            Data = Product();
            nextNode = NULL;
        }

        //primary constructor1
        Node(Product data, Node* nextNode): Data(data) {
            this->nextNode = NULL;
        }
        //primary constructor2
        Node(Product data): Data(data) {
            nextNode = NULL;
        }
        //primary constructor3
        Node(int id, string name, double p): Data(id, name, p) {
            nextNode = NULL;
        }
        //copy constructor
        Node(Node* node) {
            Data = node->Data;
            nextNode = node->nextNode;
        }

        //accessors
        Product getData() {return Data;}
        Node* getNextNode() {return nextNode;}
        //mutators
        void setData(Product data) {Data = data;}
        void setNextNode(Node* nextNode) {this->nextNode = nextNode;}
    };

    /*
    ----------------------------------------------------
    PRODUCT LIST CLASS
    Linked List that stores products
    ----------------------------------------------------
    */
    class ProductList {
    
    private:
        Node* head;
    
    public:
    
        // Default constructor
        ProductList() {
            head = NULL;
        }
    
        // Primary constructor
        ProductList(Node* h) {
            head = h;
        }
    
        // Copy constructor
        ProductList(ProductList& list) {
            if(list.head == NULL) {
                head = NULL;
            }
            else {
                head = new Node(list.head); 
            }
        }

        void listEmpty() {
            if(head == NULL) {
                cout << "List is empty.\n";
            }
            else {
                cout << "List is not empty.\n";
            }
        }
        
        void listFull(){
            if (head != NULL){
                cout << "List is full.\n";
            }
            else {
                cout << "List is not full.\n";
            }
        }
        
        // Add product to list
        void addProduct(Product p) {
            Node* newNode = new Node(p);

            if(head == NULL) {
                head = newNode;
            }
            else {
                Node* current = head;

                while(current-> getNextNode() != NULL) {
                    current = current-> getNextNode();
                }
                current->setNextNode(newNode);
            }
        }
    
        /*
        // Search product by ID
        void searchProductByID(int id){
            Node* current = head;
            while(current != NULL) {
                if(current->getData().getProductID() == id) {
                    cout << "Product found:\n";
                    current->getData().displayProductDetails();
                    return;
                }
                current = current->getNextNode();
            }
    
            cout << "Product not found.\n";
        }
        */
       
        // Display all products
        void displayProducts() {
            Node* current = head;
            while(current != NULL) {
                current->getData().displayProductDetails();
                current = current->getNextNode();
            }
        }
};
    
/*
***********************************************************************************************
BIANRY SEARCH TREE CLASS
************************************************************************************************
*/
class BstNode {
public:
    Product* product;
    BstNode* left;
    BstNode* right;

    BstNode(Product* prod, BstNode* l = NULL, BstNode* r = NULL)
        : product(prod), left(l), right(r) {}
};
class ProductBst{
    public:
    BstNode* root;

    ProductBst(){
        root = NULL;
    }
BstNode* insert(BstNode* node, Product* product){
    if (!node){
        return new BstNode{product, NULL, NULL};
    }

    if(product->getProductID() < node->product->getProductID())
        node->left = insert(node->left, product);
    else
        node->right = insert(node->right, product);
    return node;   
}
Product* search(BstNode* node, int id){
    if(!node)
        return NULL;
    if(node->product->getProductID() == id)
        return node->product;
    if(id < node->product->getProductID())
        return search(node->left, id);
    return search(node->right, id);
    }

};
#endif
