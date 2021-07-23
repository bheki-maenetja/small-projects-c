#include <iostream> 

using namespace std; 


struct Node
{
    int data;
    Node *link;
};
typedef Node* nodePtr;
void insert(nodePtr& head, int data);
int main()
{
   nodePtr head;
   head = new Node;
	head->data = 20;
 	head->link = NULL;
  
 
 insert (head, 30);
 nodePtr tmp;
 tmp = head;

 while(tmp->link != NULL)
 {
 	cout << tmp->data << endl;
 	tmp = tmp->link;
 }
 return 0;
}



