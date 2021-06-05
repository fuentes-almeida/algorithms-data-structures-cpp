#include <iostream>
#include <stdlib.h>
#include "tree.hpp"

using namespace std;

 link Tree::getroot()
 {
     return root;
 }

int Tree::altura()
{
    return BinaryTreeHeigh(root);
}

void Tree::insertar(tipo item)
{
    root=insertTreeNode(root,item);
}

void Tree::print()
{
    imprimir(root,1);
}

bool Tree::busca(tipo item)
{
    return buscar(root,item);
}


friend Tree::ostream& operator<<(ostream& out,const Tree<tipo> &arbol)
{
    ((Tree<tipo> )arbol).print();
    //arbol.imprimir(arbol.getroot,1);
    return out;
}
