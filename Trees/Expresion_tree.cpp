/*
Construct an Expression Tree from postfix and prefix expression. Perform recursive and nonrecursive
 In-order, pre-order and post-order traversals
*/

#include <iostream>
#include <stack>
using namespace std;

struct node
{
    char data;
    node *left, *right;

    node(char value)
    {
        data = value;
        left = right = NULL;
    }
};

class tree
{
public:
    struct node *root;

    tree()
    {
        root = NULL;
    }
    node *expresion_tree_by_post();
    node *expresion_tree_by_prefix();
    void preOrder_nonrec(node *root);
    void inOrder_nonrec(node *root);
    void postOrder_nonrec(node *root);
    void preorder(node *root);
    void inorder(node *root);
    void postorder(node *root);
};

node *tree::expresion_tree_by_post()
{

    stack<node *> st;
    char Exp[21];
    cout << "Enter postfix Expression to create tree : ";
    cin >> Exp;
    for (int i = 0; Exp[i] != '\0'; i++)   // a s d k j \0
    {
        if (isalnum(Exp[i]))
        {
            node *temp;
            temp = new node(Exp[i]);
            st.push(temp);
        }
        else
        { // operator
            root = new node(Exp[i]);
            root->right = st.top();
            st.pop();
            root->left = st.top();
            st.pop();
            st.push(root);
        }
    }
    root = st.top();
    st.pop();
    return root;
}

node *tree::expresion_tree_by_prefix()
{

    stack<node *> st;
    string Exp;
    cout << "Enter prefix Expression to create tree : ";
    cin >> Exp;
    for (int i = (Exp.length() - 1); i >= 0; i--)  //   * + a b c
    {
        if (isalnum(Exp[i]))
        {
            node *temp;
            temp = new node(Exp[i]);
            st.push(temp);
        }
        else
        { // operator
            root = new node(Exp[i]);
            root->left = st.top();
            st.pop();
            root->right = st.top();
            st.pop();
            st.push(root);
        }
    }
    root = st.top();
    st.pop();
    return root;
}

void tree::preOrder_nonrec(node *root)
{
    stack<node *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        cout << root->data << " ";
        if (root->left && root->right)
        {
            st.push(root->right);
            st.push(root->left);
        }
        else if (root->left)
        {
            st.push(root->left);
        }
        else if (root->right)
        {
            st.push(root->right);
        }
    }
}

void tree::inOrder_nonrec(node *root)
{
    stack<node *> st;
    node *current = root;
    while (current != NULL || (!st.empty()))
    {
        while (current != NULL)
        {
            st.push(current);
            current = current->left;
        }

        node *poped;
        poped = st.top();
        st.pop();
        cout << poped->data << " ";
        current = poped->right;
    }
}

void tree::postOrder_nonrec(node *root)
{
    stack<node *> st;
    st.push(NULL);

    while (!st.empty())
    {
        while (root != NULL)
        {
            if (root->right != NULL)
            {
                st.push(root->right);
            }
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();
        if (root->right != NULL && root->right == st.top())
        {
            st.pop();
            st.push(root);
            root = root->right;
        }
        else
        {
            if (st.top() == NULL)
            {
                st.pop();
            }
            cout << root->data << " ";
            root = NULL;
        }
    }
}

void tree::preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void tree::inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void tree::postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{

    tree t;
    int ch;
    node *root;
    do
    {
        cout << "\n1. create tree using Postfix Expression \n2. create tree using Perfix Expression ";
        cout << "\n3. Non Recursive Preorder \n4. Non Recursive inorder \n5. Non Recursive Postorder ";
        cout << "\n6. Recursive Preorder \n7. Recursive inorder \n8. Recursive Postorder \n9. Exit";
        cout << "\nEnter your choise : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            root = t.expresion_tree_by_post();
            cout << "To perform traversal operations on created Expression tree press 3/4/5/6/7/8 " << endl;
            break;
        case 2:
            root = t.expresion_tree_by_prefix();
            cout << "To perform traversal operations on created Expression tree press 3/4/5/6/7/8 " << endl;
            break;
        case 3:
        {
            cout << "Non recursive Preorder : ";
            t.preOrder_nonrec(root);
            cout << endl;
        }
        break;
        case 4:
        {
            cout << "Non recursive inorder : ";
            t.inOrder_nonrec(root);
            cout << endl;
        }
        break;
        case 5:
        {
            cout << "Non Recursive Postorder : ";
            t.postOrder_nonrec(root);
            cout << endl;
        }
        break;
        case 6:
        {
            cout << "Recursive Preorder : ";
            t.preorder(root);
            cout << endl;
        }
        break;
        case 7:
        {
            cout << "Recursive inorder : ";
            t.inorder(root);
            cout << endl;
        }
        break;
        case 8:
        {
            cout << "Recursive Postorder  : ";
            t.postorder(root);
            cout << endl;
        }
        break;
        case 9:
            cout << "********** Exit **********" << endl;
            break;
        }
    } while (ch != 9);

    return 0;
}

/*
OUTPUT ->

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 1
Enter postfix Expression to create tree : ab+cd-*
To perform traversal operations on created Expression tree press 3/4/5/6/7/8

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 3
Non recursive Preorder : * + a b - c d

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 4
Non recursive inorder : a + b * c - d

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 5
Non Recursive Postorder : a b + c d - *

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 6
Recursive Preorder : * + a b - c d

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 7
Recursive inorder : a + b * c - d

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 8
Recursive Postorder  : a b + c d - *

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 2
Enter prefix Expression to create tree : +-*$4233//84+11
To perform traversal operations on created Expression tree press 3/4/5/6/7/8

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 3
Non recursive Preorder : + - * $ 4 2 3 3 / / 8 4 + 1 1

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 4
Non recursive inorder : 4 $ 2 * 3 - 3 + 8 / 4 / 1 + 1

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 5
Non Recursive Postorder : 4 2 $ 3 * 3 - 8 4 / 1 1 + / +

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 6
Recursive Preorder : + - * $ 4 2 3 3 / / 8 4 + 1 1

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 7
Recursive inorder : 4 $ 2 * 3 - 3 + 8 / 4 / 1 + 1

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 8
Recursive Postorder  : 4 2 $ 3 * 3 - 8 4 / 1 1 + / +

1. create tree using Postfix Expression
2. create tree using Perfix Expression
3. Non Recursive Preorder
4. Non Recursive inorder
5. Non Recursive Postorder
6. Recursive Preorder
7. Recursive inorder
8. Recursive Postorder
9. Exit
Enter your choise : 9
********** Exit **********
*/