#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include "huffman.hpp"
#include <cstdlib>
#include <assert.h>

//Constructores de la clase Node
Node::Node(char k, int f)
{
    key=k;
    freq=f;
    left=NULL;
    right=NULL;
    is_leaf=true;
}
Node::Node()
{
    freq=0;
    left=NULL;
    right=NULL;
    is_leaf=false;
}

//Sobrecarga de operadores
bool operator>(const Node& A,const Node& B){
    return A.freq>B.freq;
}
bool operator<(const Node& A,const Node& B){
    return A.freq<B.freq;
}

//Cuenta los caracteres del archivo y devuelve un vector
int* GetFrequencies(char* filename)
{
    ifstream input(filename);
    if (!input)
    {
        cout<<"Error: File could not be opened."<<endl;
        return NULL;
    }
    char aux;
    int index;
    int *freq=new int[n];

    while(input.get(aux))
    {
        index=aux;
        if (index<0)
            continue;
        freq[index]+=1;
    }
    input.close();
    return freq;
}

//Genera la cola de prioridad a partir de las frecuencias
Nodequeue CreatePriorityQueue(int *freq)
{
    Nodequeue pqNode;
    int i=0;
    while (i<n)
    {
        if (freq[i]!=0){
        Node *newNode=new Node(i,freq[i]);
        pqNode.push(*newNode);}
        i++;
    }
    return pqNode;
}

//Genera el arbol de compresion a partir de la cola de prioridad
Node HuffmanCoding(Nodequeue pqNode)
{
    int size=pqNode.size();

    for(int i=0;i<size-1;i++)
        {
            Node *Z,*X,*Y;
                Z=new Node[1];
                X=new Node[1];
                Y=new Node[1];

            *X=pqNode.top();
                Z->left=X;
                Z->freq+=X->freq;
            pqNode.pop();

            *Y=pqNode.top();
                Z->right=Y;
                Z->freq+=Y->freq;
            pqNode.pop();

            pqNode.push(*Z);
        }

    Node root=pqNode.top();
    return root;
}

//Imprime el arbol en pantalla
void PrintHuffmanTree(Node* raiz, int heigh)
{
    if(raiz==NULL)
        return;
    PrintHuffmanTree(raiz->right,heigh+1);

        for (int i=0;i<heigh;i++)
            cout<<"   ";
                cout<<raiz->freq;
                if (raiz->is_leaf)
                    cout<<":"<<(int)raiz->key;
                cout<<endl;
    PrintHuffmanTree(raiz->left,heigh+1);
}

//Genera el codigo binario de compresion
void CompressionCode(Node* root,string* strvector)
{
	static string bits = "";
	if (root->right != NULL)
	{
		bits += "1";
		CompressionCode(root->right,strvector);
		bits = bits.substr(0, bits.size() - 1);
	}
	if (root->left != NULL)
	{
		bits += "0";
		CompressionCode(root->left,strvector);
		bits = bits.substr(0, bits.size() - 1);
	}
	if(!root->left && !root->right)
	{
		strvector[(int)root->key] = bits;
	}
}

//Genera el archivo comprimido y el arbol de compresion en otro archivo
void PrintCompresedFile(Node *root, string *strvector, char* input_filename,char* output_filename)
{
    ifstream input(input_filename);
    ofstream output(output_filename);
    char aux;
    int index, num_char=0;
    string data,byte;

    while(input.get(aux))
    {
        index=aux;
        if (index<0)
            continue;
        data+=strvector[index];
        num_char++;
    }

    while(data.size()>8)
    {
        byte=data.substr(0,8);
        aux=stoi(byte,nullptr,2);
        output<<aux;
        data=data.substr(8);
    }
    byte=data.substr(0,data.size());
    aux=stoi(byte,NULL,2);
    output<<aux;

    output.close();

    output.open("CompressionTree.txt");
    output<<num_char<<endl;
    for (int i=0;i<n;i++)
        {
        if (strvector[i]!="")
        output<<strvector[i]<<" "<<i<<endl;
        }
    output.close();
    input.close();
}

//Reconstruye el arbol a partir del arbol de compresion
Node* ReconstructTree(int *num_chars)
{
    ifstream input("CompressionTree.txt");
    if (!input)
    {
        cout<<"Error: File could not be opened."<<endl;
        return NULL;
    }
    Node* root= new Node();
    Node* temp=NULL;
    char aux; string bits; int i,index;
    input>>*num_chars;
    input.get(aux);
    while(input.get(aux)!=NULL)
    {
        temp=root;
        bits="";
        bits+=aux;

        while(input.get(aux))
        {
            if (aux==32) break;
            bits+=aux;
        }
        input>>index;
        int size=bits.size();
        for (i=0;i<size-1;i++)
        {
            if (bits[i]=='0')
            {
                if(temp->left==NULL)
                    temp->left=new Node();
                temp=temp->left;

            }
            else if (bits[i]=='1')
            {
                if(temp->right==NULL)
                    temp->right=new Node();
                temp=temp->right;
            }
        }
        if (bits[i]=='0')
            temp->left=new Node(index,1);
        else if (bits[i]=='1')
            temp->right=new Node(index,1);
        input.get(aux);
    }
    return root;
}

//Reconstruye el archivo original
void ReconstructFile(Node* root, char* filename,int num_chars)
{
    ifstream input(filename);
    ofstream output("RebuiltFile.txt");
    char aux;
    string data;
    Node* temp=root;
    while (input.get(aux)!=NULL)
    {
        for (int i = 7; i >= 0; --i)
        {
            if(aux & (1 << i))
                data+='1';
            else data+='0';
        }
    }

    int size=data.size(),counter=1;
    for(int i=0;i<size&&counter<num_chars;i++)
    {
        if (temp==NULL)
        {
            cout<<"Error in compression Tree"<<endl;
            return;
        }
        if (data[i]=='0')
            temp=temp->left;
        else
            temp=temp->right;
        if (temp->freq==1)
        {
            output<<temp->key;
            counter++;
            temp=root;
        }
    }
    input.close();
    output.close();
}

void FreeBinaryTree(Node* raiz)
{
    if (raiz==NULL)
        return;
    if(raiz->left!=NULL)
        return FreeBinaryTree(raiz->left);
    if (raiz->right!=NULL)
        return FreeBinaryTree(raiz->right);
    delete raiz;
    raiz=NULL;
}

void CompressFile(char* input_filename, char* output_filename)
{
        cout<<"Generating frequency table..."<<endl;
        int *freq=NULL;
        freq=GetFrequencies(input_filename);
        if (freq==NULL) return;

        cout<<"Creating Priority Queue..."<<endl;
        Nodequeue pqNode;
        pqNode=CreatePriorityQueue(freq);
        delete [] freq;

        cout<<"Coding Huffman Tree..."<<endl;
        Node root=HuffmanCoding(pqNode);
        ///PrintHuffmanTree(&root,0);

        cout<<"Generating Compression Code..."<<endl;
        string *strvector=new string[n];
        CompressionCode(&root,strvector);

        cout<<"Compressing File..."<<endl;
        PrintCompresedFile(&root,strvector,input_filename,output_filename);
        FreeBinaryTree(&root);
        delete [] strvector;
}

void DecompressFile(char* output_filename)
{
        cout<<"Reconstructing Compression Tree..."<<endl;
        int num_chars;
        Node *rebuiltRoot=NULL;
        rebuiltRoot=ReconstructTree(&num_chars);
        if (rebuiltRoot==NULL) return;
        ///PrintHuffmanTree(rebuiltRoot,0);

        cout<<"Decompressing File..."<<endl;
        ReconstructFile(rebuiltRoot,output_filename,num_chars);
        FreeBinaryTree(rebuiltRoot);
}

