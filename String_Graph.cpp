
#include <iostream>
#include <codecvt>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <chrono>

using namespace std;
vector<string> split_string(string);

class Node
{
public:
    std::map<char, Node*> node_map;
    int count = 0;
    int rem_length;
    int index;
    
};

void create_tree(Node* root, string input_data)
{
    for (int start_index = 0; start_index < input_data.size(); start_index++)
    {
        Node* active_node = root;
        for (int index = start_index ; index < input_data.size(); index++)
        {
            if (active_node->node_map.find(input_data[index]) == active_node->node_map.end())
            {
                active_node->node_map[input_data[index]] = new Node;
                active_node = active_node->node_map[input_data[index]];
                active_node->rem_length = input_data.size() - index;
                active_node->index = index + 1;
                break;

            }
            active_node = active_node->node_map[input_data[index]];
            
        }
        active_node->count++;
        
    }
}

int main()
{
    Node* root;
    root = new Node;
    string x = "abcabdegh";
    create_tree(root, x);
    std::cout << "Hello World!\n";
}


