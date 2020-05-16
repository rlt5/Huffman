#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class HuffmanNode
{
public:
	
    long int character;
    long int weight;
    HuffmanNode* right;
    HuffmanNode* left;
    HuffmanNode* parent;

    HuffmanNode(){
        character = 0;
        weight = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    HuffmanNode(long int character, long int weight){
        this.character = character;
        this.weight = weight;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    HuffmanNode(long int character){
        this.character = character;
        weight = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    ~HuffmanNode(){
        delete left;
        delete right;
        left = right = NULL;
    };

    bool isLeaf(){
        return (this->right == NULL && this->left == NULL);
    }

};

class HuffmanTree
{
    public:
        HuffmanTree(char action, string inputFileName, string outputFileName, char buffer[]);

    private:
        HuffmanNode* root;
};

#endif /* HUFFMANTREE_HPP */