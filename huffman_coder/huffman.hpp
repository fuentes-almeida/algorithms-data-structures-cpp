#ifndef HUFFMAN_HPP_INCLUDED
#define HUFFMAN_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <cstdlib>
//numero de caracteres imprimibles
#define n 127

using namespace std;

class Node
{
private:
    //Atributos de la clase
    int freq;   //frecuencia
    char key;   //caracter
    Node* left;
    Node* right;
    bool is_leaf;

public:
    Node(char k, int f); //constructor con parametros
    Node();//constructor por default

    //Sobrecarga de operadores
    friend bool operator>(const Node& A,const Node& B);
    friend bool operator<(const Node& A,const Node& B);

    //Funciones de Codificacion Huffman
    typedef priority_queue<Node, vector<Node>, greater<vector<Node>::value_type> > Nodequeue;
    friend Node HuffmanCoding(Nodequeue pqNode);
    friend void PrintHuffmanTree(Node* raiz, int heigh);
    friend void CompressionCode(Node* root,string* strvector);
    friend void PrintCompresedFile(Node *root ,string *strvector, char* input_filename,char* output_filename);
    friend void StorePreOrderTree(Node* root,string *Treevector);
    friend Node* ReconstructTree(int *num_chars);
    friend void ReconstructFile(Node* root, char* filename,int num_chars);
    friend void FreeBinaryTree(Node* raiz);
};

typedef priority_queue<Node, vector<Node>, greater<vector<Node>::value_type> > Nodequeue;
int* GetFrequencies(char* filename);
Nodequeue CreatePriorityQueue(int *freq);
Node* ReconstructTree(int *num_chars);
void DecompressFile(char* output_filename);
void CompressFile(char* input_filename, char* output_filename);

#endif // HUFFMAN_HPP_INCLUDED
