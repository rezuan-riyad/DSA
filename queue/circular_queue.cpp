// Array based implementaion of circular queue
#include <iostream>
using namespace std;

#define SIZE 5

class Queue{
  private:
  int items[SIZE], top, bottom;

  public:
  Queue(){
    top = -1;
    bottom = -1;
  }

  bool isfull(){
    if(bottom == 0 && top == SIZE - 1) return true;
    if(bottom == top + 1) return true;
    return false;
  }

  bool isempty(){
    if(bottom == -1) return true;
    return false;
  }

  // adding an element
  void enqueue(int elem){
    if(isfull()){
      cout << "Queue is full" << endl;
    } else {
      if(bottom == -1) bottom = 0;
      top = (top + 1) % SIZE;
      items[top] = elem;
      cout << "Inserted: " << elem << endl;
    }
  }

  // removing an element
  int dequeue(){
    if(isempty()){
      cout << "Queue is empty" << endl;
      return -1;
    } else {
      int elem;
      elem = items[bottom];
      
      if(top == bottom){
        top = -1, bottom = -1;
      } else {
        bottom = (bottom + 1) % SIZE;
      }

      return elem;
    }
  }

  void display(){
    if(isempty()){
      cout << "Empty Queue" << endl;
    } else {
      cout << "Items-------" << endl;
      
      int i;
      for( i = bottom; i != top; i = (i+1) % SIZE){
        cout << items[i] << endl;
      }

      cout << "\n\n";
    }
  }

  void display_index(){
    cout << "top: " << top << ", bottom: " << bottom << endl;
  }
};

int main(){
  Queue q;
  q.dequeue();

  q.display_index();

  q.enqueue(10);
  q.display_index();

  q.enqueue(20);
  q.display_index();
  
  
  q.enqueue(30);
  q.display_index();
  
  q.enqueue(40);
  q.display_index();
  
  q.enqueue(50);
  q.display_index();
  // Fails to enqueue because front == 0 && rear == SIZE - 1
  q.enqueue(6);
  q.display_index();


  //q.display();
  q.display_index();


  int elem = q.dequeue();

  if (elem != -1)
    cout << endl
      << "Deleted Element is " << elem;

  q.display();
  q.display_index();


  q.enqueue(7);
  q.display_index();

  q.dequeue();
  q.display_index();

  q.display();
  q.display_index();


  // Fails to enqueue because front == rear + 1
  q.enqueue(8);
  q.display_index();

  return 0;
}