Data Structures Group Project
========================================
    
Due Date: Week 10-12
--------------------------------
Project Title:
E-Commerce Platform for BrandEx Online Store using Data Structures and Files
Background
An online retailer, BrandEx, sells tens of products ranging from electronics to clothing. To provide a seamless shopping experience,
BrandEx develops a backend system to manage user accounts, product catalog, shopping carts, and order processing efficiently.
Scenario Details
(a) User Account Management
Customers create accounts with secure passwords that are hashed and stored in a PASSWORD FILE.
Customers can update their profiles, view order history, and manage their orders.
(b) Product Catalog
Products are stored in a linked list for easy insertion/deletion.
To quickly locate products by name or ID, the system uses a binary search tree (BST), enabling fast searches.
© Shopping Experience
Customers browse products, add items to their shopping cart, and modify quantities.
The shopping cart uses a linked list to track products added by the user.
To allow users to undo or redo recent actions (like removing an item or changing quantity), the system utilizes stacks, providing a better
user experience.
(d) Order Processing
When a customer checks out, their order is added to an order queue.
The warehouse's order fulfillment system processes orders in the order received, ensuring fairness.
The queue manages order processing asynchronously to handle high traffic efficiently.
(e) Security & Data Integrity
There are two types of user admin and customers.
Admin
The admin username is root and the password is admin. The admin is the only one that can do option (b,d). In addition, the admin can
change a customer password.
Customer
To purchase from the store a customer must first register. To register the customer will enter first name, last name, and a valid email
address ONLY. After registering the system will generate a One Time Password (OTP) that the user will enter to access the system.
After the customer enters the OTP the user will be forced to change their password.
The customer should be able to change their password at any time . NO CLEAR TEXT PASSWORD SHOULD BE STORED IN THE
PASSWORD FILE ONLY THE HASED OF THE PASSWORD.
If a user click forget password then they should enter first name and last name and the new password should be EMAILED to the
SIGNUP EMAIL PROVIDED.
If a user click change password then the old password should be entered. PLEASE NOTE a password history should be in place for the
last TWO passwords and no password in the history can be used as a new password. User inputs are validated to prevent injection or
corruption.
(f) User Interface:
Provide a console-based/GUI interface to interact with the system. If a console interface is used the user MUST NOT be able to scroll
up or down.
Workflow Example
User Sign-Up & Login
A customer signs up, creating a secure account.
Browsing & Searching
The customer searches for "Laptop" — the system uses BST to quickly find matching products.
Adding to Cart
The customer adds a laptop to the cart.
The action is pushed onto an undo stack, allowing the customer to revert if needed.
Modifying Cart
The customer removes an accessory; the action is pushed onto the redo stack.
Checkout
The cart contents are transferred into an order, which is enqueued for processing.
Order Fulfillment
Warehouse staff process orders in FIFO order from the queue.
Customers receive updates once their order is shipped via email.
AI Usage Policy for Assignments
Purpose:
To promote academic integrity and ensure that all submitted work reflects the student's own understanding and efforts, this policy
outlines the acceptable and unacceptable uses of AI tools in completing assignments.
Policy Guidelines:
a) Explicit Acknowledgment:
Students must disclose any use of AI tools (such as ChatGPT, coding assistants, or other generative AI platforms) in the completion of
the assignment.
All AI-generated content must be clearly identified and appropriately referenced within the submission.
b) Original Work Requirement:
The majority of the work submitted should be the student's own effort, understanding, and coding. Use of AI tools should serve as a
learning aid, not as the primary creator of the work.
Assignments should demonstrate critical thinking, problem-solving, and personal insight.
c) Prohibited Practices:
Submitting AI-generated work as your own without acknowledgment.
Using AI tools to bypass the learning process or to produce work that you do not understand.
e) Use of AI as a Learning Tool:
AI can be used for brainstorming, debugging, clarifying concepts, or getting suggestions, provided it is properly disclosed.
Students should review and understand AI outputs and modify or improve upon them before submission.
d) Consequences of Policy Violations:
Failure to disclose AI assistance or submitting work that violates this policy may result in academic penalties, including loss of up to
30% of grades.
e) Instructor's Role:
Instructors may use plagiarism detection tools, code review, and oral examinations to verify the authenticity of student work.
Submission Documents:
1. A comprehensive user manual with all group members name and id number on the front of the document. Please note if your name
and or id number does not appear on the manual you are not a part of the group.
2. All project source code files. Please check if files are corrupted or missing before submission failure to comply means no submission.
3. UML diagrams (any three processes)
4. Individual reflection
