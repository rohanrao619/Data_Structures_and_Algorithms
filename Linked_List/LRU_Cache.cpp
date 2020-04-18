// { Driver Code Starts




#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int value;
    Node *next, *pre;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = pre = NULL;
    }
};


 // } Driver Code Ends
/*
struct Node
{
    int key;
    int value;
    Node *next,*pre;
    Node(int key, int value)
    {
        this->key=key;
        this->value=value;
        next=pre=NULL;
    }

};
*/

class LRUCache {
  private:
    static unordered_map<int, Node *> hsmap;
    static int capacity, count;
    static Node *head, *tail;

  public:
    LRUCache(int cap) {
        // Your code here
        capacity = cap;
        count = 0;
        hsmap.clear();
        head = tail = NULL;
    }

    static int get(int key) {
        // Your code here
        if(hsmap.count(key)==0)
        return -1;
        
        Node *temp = hsmap[key];
        
        if(temp==head)
        return temp->value;
        
        if(temp==tail)
        {
            temp->pre->next=NULL;
            tail = temp->pre;
        }
        else
        {
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
        }
        
        temp->next = head;
        head->pre = temp;
        temp->pre=NULL;
        head = temp;
        
        return head->value;
        
    }

    static void set(int key, int value) {
        // Your code here
        if(count==0)
        {
            head = new Node(key,value);
            tail = head;
            hsmap[head->key] = head;
            count++;
            return;
        }
        
        Node *temp;
        
        if(hsmap.count(key)==0)
        {
            temp = new Node(key,value);
            hsmap[temp->key] = temp;
            count++;
        }
        else
        {
            temp = hsmap[key];
            temp->value = value;
            
            if(temp==head)
            return;       
        
            if(temp==tail)
            {
                temp->pre->next=NULL;
                tail = temp->pre;
            }
            else
            {
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
            }
            
        }
        
        temp->next = head;
        head->pre = temp;
        temp->pre = NULL;
        head=temp;
        
        if(count>capacity)
        {
            hsmap.erase(tail->key);
            tail = tail->pre;
            free(tail->next);
            tail->next =NULL;
            count--;
        }
      
    }
};

// { Driver Code Starts.

// Initializing static members
unordered_map<int, Node *> temp;
int LRUCache::capacity = 0;
Node *LRUCache::head = new Node(0, 0);
Node *LRUCache::tail = new Node(0, 0);
int LRUCache::count = 0;
unordered_map<int, Node *> LRUCache::hsmap = temp;

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        int queries;
        cin >> queries;

        LRUCache *cache = new LRUCache(capacity);
        while (queries--) {
            string q;
            cin >> q;
            if (q == "SET") {
                int key;
                cin >> key;
                int value;
                cin >> value;

                cache->set(key, value);

            } else {
                int key;
                cin >> key;

                cout << cache->get(key) << " ";
            }
        }

        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
