#include <bits/stdc++.h>
using namespace std;
int size;
vector<char> buf(size, '0');
struct node
{
    int i;
    char data;
    node *next;
};
class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void add_node(char d, int ind)
    {
        node *temp = new node;
        temp->data = d;
        temp->i = ind;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }
     void ddelete (node *n){
        node* temp;
        temp = n->next;
        n->next = temp->next;
        delete temp;
    }
    static void concatenate(node *a,node *b){
        if( a != NULL && b!= NULL ){
            if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next,b);
        }
        else{
            cout << "null pointer error\n";
        }
    }
    static void display(node *head)
    {
        if(head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->i << ": " << head->data << "->  ";
            display(head->next);
        }
    }

    node* thead()
    {
        return head;
    }
};

int main(){
    cout << "enter size of the buffer ";
    cin>>size;
    vector<linked_list> ll;
    while(1){
        cout << "enter file and head,tail: ";
        string s;
        cin >> s;
        int h, t;
        cin >> h >> t;
        int i = 0;
        linked_list l;
        l.add_node(s[0], h);
        buf[h] = s[0];
        while(i!= s.size() - 1){
            int j = rand() % 20;
            if(buf[j] == '0'){
                i++;
                buf[j] = s[i];
                l.add_node(s[i], j);
            }

        }
        buf[t] = ' ';
        ll.push_back(l);

    }

    cout << "--------------------------"<< endl;
    for(int i = 0; i < ll.size(); i++){
        linked_list::display(ll[i].thead());
        cout << "--------------------------"<< endl;
    }
    for(int i = 1;  i < buf.size(); i++){
		cout << i << ": " << buf[i] << "  ";
	}

    return 0;
}
