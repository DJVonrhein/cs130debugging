#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct node
{
    node * prev;
    node * next;
    std::string data;

    node(node * p, node * n, const std::string& s)
        :prev(p), next(n), data(s)
    {
    }
    
};

struct list
{
    node * head;
    node * tail;
    size_t n;
    
    list()
        :head(0), tail(0), n(0)
    {
    }

    ~list()
    {
        if(head && head->next){
            for(node * n = head->next; n; n = n->next)
                delete n->prev;
            // delete tail;
        }
        else if(head)
            delete head;
    }

    size_t size() const
    {
        return n;
    }

    node * append(const std::string& str)
    {
        if(tail)
        {
            tail = tail->next = new node(tail, 0, str);
        }
        else
        {
            tail = head = new node(0, 0, str);
        }
        return tail;
    }

    node * add_after(node* n, const std::string& str)
    {
        node * a = new node(n, n->next, str);
        if(n->next)
            n->next->prev = a;
        n->next = a;
        return a;
    }

    void remove(node* n)
    {
        if(n){
            if(n == tail && n == head){
                head = nullptr;
                tail = nullptr;
            }
            else if(n == head){
                n->next->prev = nullptr;
                head = n->next;
            }
            else if(n == tail){
                n->prev->next = nullptr;;
                tail = n->prev;
            }
            else{
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }
            
            delete n;
        }
    }

    void print()
    {
        for(node * n = head; n; n = n->next)
            std::cout << n->data << std::endl;
    }
};

int main()
{
    list L;

    node * a = L.append("A");
    node * c = L.append("C");
    node * e = L.append("E");
    L.print();

    node * b = L.add_after(a, "B");
    node * d = L.add_after(c, "D");
    node * f = L.add_after(e, "F");
    L.print();

    L.remove(a);
    L.remove(d);
    
    L.print();

    return 0;
}

