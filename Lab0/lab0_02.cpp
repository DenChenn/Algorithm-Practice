#include <iostream>
#include <string>
using namespace std;

struct Node{
    Node(){
        next = NULL;
    }
    string content;
    Node* next;
};

int main () {
    string data;
    while(cin >> data){
        Node* result = new Node;
        Node* dummy_head = new Node;
        dummy_head->next = result;
        Node* end = result;
        string temp = "";
        bool is_front = true;
        for(int i = 0;i < data.length();i++){
            if(data[i] == '[' && temp != ""){
                if(is_front){
                    Node* new_node = new Node;
                    new_node->content = temp;
                    new_node->next = dummy_head->next;
                    dummy_head->next = new_node;
                    temp = "";
                    is_front = true;
                    continue;
                }
                else{
                    end->content = temp;
                    Node* new_node = new Node;
                    end->next = new_node;
                    end = end->next;
                    temp = "";
                    is_front = true;
                    continue;
                }
            }
            else if(data[i] == ']' && temp != ""){
                if(is_front){
                    Node* new_node = new Node;
                    new_node->content = temp;
                    new_node->next = dummy_head->next;
                    dummy_head->next = new_node;
                    temp = "";
                    is_front = false;
                    continue;
                }
                else{
                    end->content = temp;
                    Node* new_node = new Node;
                    end->next = new_node;
                    end = end->next;
                    temp = "";
                    is_front = false;
                    continue;
                }
            }
            else if(data[i] == ']' && temp == ""){
                is_front = false;
            }
            else if(data[i] == '[' && temp == ""){
                is_front = true;
            }
            
            if(data[i] != ']' && data[i] != '[')
                temp = temp + data[i];
        }
        
        if(is_front){
            Node* new_node = new Node;
            new_node->content = temp;
            new_node->next = dummy_head->next;
            dummy_head->next = new_node;
        }
        else{
            end->content = temp;
            Node* new_node = new Node;
            end->next = new_node;
            end = end->next;
        }

        if(dummy_head->next->next == NULL)
            cout << temp << endl;
        else{
            for(Node* t = dummy_head->next;t != NULL;t = t->next)
                cout << t->content;
            cout << endl;
        }
    }
    return 0;
}