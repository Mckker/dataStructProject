#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include "Product.h"

using namespace std;

class ShoppingCart {

private:
    Product product;
    int quantity;

public:

    // Default constructor
    ShoppingCart() {
        product = Product();
        quantity = 0;
    }

    // Primary constructor
    ShoppingCart(Product p, int q) {
        product = p;
        quantity = q;
    }

    // Copy constructor
    ShoppingCart(const ShoppingCart& cart) {
        product = cart.product;
        quantity = cart.quantity;
    }

    // Setters
    void setProduct(Product p) { product = p; }
    void setQuantity(int q) { quantity = q; }

    // Getters
    Product getProduct() { return product; }
    int getQuantity() { return quantity; }
};


/*
----------------------------------------------------
NODE CLASS FOR SHOPPING CART LINKED LIST
----------------------------------------------------
*/

class Node{
public:
    ShoppingCart Data;
    Node* nextNode;

    // Default constructor
    Node(): Data() {
        nextNode = NULL;
    }

    // Constructor with next node
    Node(ShoppingCart data, Node* nextNode): Data(data) {
        this->nextNode = nextNode;
    }

    // Constructor with only cart data
    Node(ShoppingCart data): Data(data) {
        nextNode = NULL;
    }

    // Constructor using product details
    Node(int id, string name, double p, int q)
    {
        Product prod(id, name, p);
        Data = ShoppingCart(prod, q);
        nextNode = NULL;
    }

    // Copy constructor
    Node(Node* node) {
        Data = node->Data;
        nextNode = node->nextNode;
    }

    // Accessors
    ShoppingCart getData() { return Data; }
    Node* getNextNode() { return nextNode; }

    // Mutators
    void setData(ShoppingCart data) { Data = data; }

    void setNextNode(Node* nextNode) {
        this->nextNode = nextNode;
    }
};


/*
----------------------------------------------------
SHOPPING CART LIST
----------------------------------------------------
*/

class ShoppingCartList{

private:
    Node* head;

    stack<string> undoStack;
    stack<string> redoStack;

public:

    // Default constructor
    ShoppingCartList(){
        head = NULL;
    }

    // Constructor
    ShoppingCartList(Node* h){
        head = h;
    }

    // Accessors
    Node* getHead() { return head; }

    // Mutator
    void setHead(Node* h) { head = h; }


    // Add product to cart
    void addToCart(Product p, int qty)
    {
        ShoppingCart cart(p, qty);
        Node* newNode = new Node(cart);

        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->getNextNode())
            {
                temp = temp->getNextNode();
            }

            temp->setNextNode(newNode);
        }

        undoStack.push("Added " + p.getProductName() + " x" + to_string(qty));
    }


    // Display cart items
    void displayCart()
    {
        if (!head)
        {
            cout << "Cart is empty\n";
            return;
        }

        Node* temp = head;

        while (temp)
        {
            ShoppingCart cart = temp->getData();
            Product p = cart.getProduct();
            int qty = cart.getQuantity();

            cout << p.getProductName()
                 << " x" << qty
                 << " - $" << p.getPrice() * qty << endl;

            temp = temp->getNextNode();
        }
    }


    // Undo operation
    void undo()
    {
        if (undoStack.empty())
        {
            cout << "Nothing to undo\n";
            return;
        }

        string action = undoStack.top();
        undoStack.pop();
        redoStack.push(action);

        cout << "Undo: " << action << endl;
    }


    // Redo operation
    void redo()
    {
        if (redoStack.empty())
        {
            cout << "Nothing to redo\n";
            return;
        }

        string action = redoStack.top();
        redoStack.pop();
        undoStack.push(action);

        cout << "Redo: " << action << endl;
    }

};