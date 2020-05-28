#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <vector>
// using namespace std;

class HuffmanNode
{
public:
	
    int character;
    uint32_t weight;
    HuffmanNode* right ;
    HuffmanNode* left;
    HuffmanNode* parent;

    // HuffmanNode(){
    //     character = NULL;
    //     weight = 0;
    //     left = NULL;
    //     right = NULL;
    //     parent = NULL;
    // }

    HuffmanNode(){
        this->character = 0;
        this->weight = 0;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL; 
    }

    HuffmanNode(int character, uint32_t weight){
        this->character = character;
        this->weight = weight;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }

    HuffmanNode(int character, 
                uint32_t weight, 
                HuffmanNode* left,
                HuffmanNode* right
                ){
        this->character = character;
        this->weight = weight;
        this->left = left;
        this->right = right;
        this->parent = NULL;
    }

    ~HuffmanNode(){
        delete this->left;
        delete this->right;
        this->left = this->right = NULL;
    };

    bool isLeaf(){
        return (this->right == NULL && this->left == NULL);
    }

    // Desc:  Comparators
    bool operator()(const HuffmanNode* l, const HuffmanNode* r)const;
    void print();
};


class HuffmanTree
{
    public:
        HuffmanTree();
        HuffmanTree(char action, std::map<char, uint32_t> frequencyTable );
        void printTree(HuffmanNode* root);
        void printPQ();
        HuffmanNode* getRoot();
        
    private:
        HuffmanNode* root;
        int size();
        std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, HuffmanNode > pq;
        std::map<char, uint32_t> frequencyTable;
};

#endif /* HUFFMANTREE_HPP */