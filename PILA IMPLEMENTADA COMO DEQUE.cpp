#include <iostream>
using namespace std;
template<typename T>
struct Array{
  T A[5];
  Array<T>*prev;
  Array(Array<T>*_prev)
  {
    prev = _prev;
  }
  ~Array()
  {
    if(prev!=nullptr) delete prev;
  }
};

template<typename T>
class Pila{
public:
  Array<T>*ptr=nullptr;
  T *top=nullptr;
  void push(T v)
  {
    if (!top)
    {
      ptr = new Array<T>(nullptr);
      top = ptr->A;
      *top = v;
    }
    else if(top!=((ptr->A)+4)&&top)
    {
      top++;
      *top = v;
    }
    else{
      ptr = new Array<T>(ptr);
      top= ptr->A;
      *top = v;
    }
  }
  void print()
  {
    Array<T>*ptr2 = ptr;
    T*primero = top;
    if(top==nullptr)
    {
        cout<<"Pila vacia "<<endl;
        return;
    }
    for(;primero>=ptr2->A;primero--)
    {
      if(primero==ptr2->A) cout<<*primero;
      else {cout<<*primero<<",";}
    }
    cout<<"->";
    ptr2 = ptr2->prev;
    while(ptr2)
    {
      for(int i=0;i<5;i++)
      {
        if(i==4) cout<<*(ptr2->A)<<"->"; 
        else{
          cout<<*((ptr2->A)+4-i)<<",";
        }
      }
      ptr2 = ptr2->prev;
    }
    cout<<"NULL"<<endl;
  }
  
 T pop()
  {
     if(top==nullptr && ptr==nullptr){
     cout<<"Pila vacia";
     return 0;
     }
    if(top==ptr->A && !ptr->prev)
    {
        T valor = *top;
        top = nullptr;
        delete ptr;
        ptr = nullptr;
        return valor;
    }
    else if(top==ptr->A && ptr->prev)
    {
        T valor = *top;
        ptr = ptr->prev;
        top = ptr->A+4;
        return valor;
    }
    else{
        T valor = *top;
        top--;
        return valor;
    }
  }
 
};

int main() {

}
