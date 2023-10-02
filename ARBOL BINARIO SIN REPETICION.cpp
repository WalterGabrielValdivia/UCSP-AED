#include <iostream>
using namespace std;
struct Cnode{
  int v;
  Cnode *nodes[2];
  Cnode(int _v) : v(_v){
    nodes[0] = nullptr;
    nodes[1] = nullptr;
  }
  ~Cnode() {
        for (int i = 0; i < 2; ++i) {
            if (nodes[i] != nullptr) {
                delete nodes[i];
                nodes[i] = nullptr;
            }
        }
    }
};
class CBinTree{
public:
bool find(int x,Cnode**&p);
bool insert(int x);
bool remove(int x);
Cnode** rep(Cnode**W);
Cnode*root=nullptr;
void inorder(Cnode *p);
void posorder(Cnode *p);
void preorder(Cnode *p);
};
bool CBinTree::find(int x, Cnode **&p){
  for(p=&root;*p && (*p)->v!=x;p =&((*p)->nodes[x>(*p)->v]))
  {}
  return !!*p;
}
bool CBinTree::insert(int x){
  Cnode **p2=nullptr;
  if(find(x,p2)) return 0;
  *(p2) = new Cnode(x);
  return 1;
  
}
Cnode** CBinTree::rep(Cnode**W){
  for(W=&((*W)->nodes[0]);(*W)->nodes[1];W=&((*W)->nodes[1]))
  {}
  return W;
}
bool CBinTree::remove(int x){
  Cnode**p = nullptr;
  if(!find(x,p)) return 0;
  if((*p)->nodes[0] &&(*p)->nodes[0])
  {
    Cnode **q = rep(p);
    (*p)->v = (*q)->v;
    p = q;
  }
  Cnode * T = *p;
  *p = (*p)->nodes[(*p)->nodes[1]!=0];
  delete T;
  T = nullptr;
  return 1;
}
void CBinTree::inorder(Cnode*p)
{
  if(!p) return;
  inorder(p->nodes[0]);
  cout<<p->v<<" ";
  inorder(p->nodes[1]);
}
void CBinTree::posorder(Cnode*p)
{
  if(!p) return;
  posorder(p->nodes[0]);
  posorder(p->nodes[1]);
  cout<<p->v<<" ";

}
void CBinTree::preorder(Cnode*p)
{
  if(!p) return;
  cout<<p->v<<" ";
  preorder(p->nodes[0]);
  preorder(p->nodes[1]);

}
int main() {
  CBinTree arbol;
}
