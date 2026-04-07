#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

struct compare
{
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string str)
{
    if(!root)
        return;

    if(root->data != '$')
        cout << root->data << ": " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for(int i = 0; i < size; i++)
        minHeap.push(new Node(data[i], freq[i]));

    while(minHeap.size() != 1)
    {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        Node *top = new Node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char data[50];
    int freq[50];

    cout << "Enter characters:\n";
    for(int i = 0; i < n; i++)
        cin >> data[i];

    cout << "Enter frequencies:\n";
    for(int i = 0; i < n; i++)
        cin >> freq[i];

    cout << "Huffman Codes:\n";
    HuffmanCodes(data, freq, n);

    return 0;
}