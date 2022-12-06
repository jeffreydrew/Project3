struct Node
{
    char character;
    int frequency;
    Node left, right;

    Node() : frequency(0), character(0), left(nullptr), right(nullptr) {}
    Node(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {};
    Node(int f, char c, Node* lf, Node* rt) : character(c), frequency(f), left(lf), right(rt) {};

};


struct comp
{
    bool operator()(Node* a, Node* b)
    {
        return a->frequency > b->frequency;
    }
};

class HuffMan
{
public:
    string word;

    priority_queue<Node, vector<Node>, comp> queue;
    unordered_map<char, int> map;

    HuffMan(string& str)
    {
        word = str;

        for (char& i : str)
        {
            map[i]++;
        }

        for (auto it = map.begin(); it != map.end(); it++) {
            queue.push(new Node(it->first, it->second));
        }

        while (queue.size() > 1)
        {
            Node* tl, * tr;
            tl = queue.top();
            queue.pop();
            tr = queue.top();
            queue.pop();

            Node* n = new Node(tl->frequency + tr->frequency, ' ', tl, tr);
            queue.push(n);
        }
    }

    Node* get()
    {
        return queue.top();
    }
};
Rafa333 — Today at 7:49 PM
Huffman :
class HuffMan
{
private:
    struct Node
    {
        char character;
        int frequency;
        Node left, right;

        Node() : frequency(0), character(0), left(nullptr), right(nullptr) {}
        Node(char c, int f) : character(c), frequency(f), left(nullptr), right(nullptr) {};
        Node(int f, char c, Node* lf, Node* rt) : character(c), frequency(f), left(lf), right(rt) {};
    };

    struct comp
    {
        bool operator()(Node* a, Node* b)
        {
            return a->frequency > b->frequency;
        }
    };

public:
    string word;

    priority_queue<Node, vector<Node>, comp> queue;
    unordered_map<char, int> map;

    HuffMan(string& str)
    {
        word = str;

        for (char& i : str)
        {
            map[i]++;
        }

        for (auto it = map.begin(); it != map.end(); it++) {
            queue.push(new Node(it->first, it->second));
        }

        while (queue.size() > 1)
        {
            Node* tl, * tr;
            tl = queue.top();
            queue.pop();
            tr = queue.top();
            queue.pop();

            Node* n = new Node(tl->frequency + tr->frequency, ' ', tl, tr);
            queue.push(n);
        }
    }


    vector<int> getRGB()
    {
        vector<int> rgb;
        rgb.push_back(queue.top()->frequency);
        rgb.push_back(queue.top()->left->frequency);
        rgb.push_back(queue.top()->right->frequency);

    }
};