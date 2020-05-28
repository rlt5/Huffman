#include "HuffmanTree.hpp"

bool HuffmanNode::operator() (const HuffmanNode* l, const HuffmanNode* r) const{
    if ( l->weight == r->weight ){
        return l->character > r->character;
    } 
    return l->weight >= r->weight;
}

void HuffmanNode::print(){
    // std::cout   << "char="      << this->character;
    if ( this->character < 256)
        std::cout   << "char="      << "\033[31m" << (char)this->character << "\033[0m";
    else 
        std::cout   << "char="      << "\033[31m" << "T" << (int)this->character-255 << "\033[0m";
    std::cout   << " weight="   << this->weight;
    if (this->left) {
        if ( this->left->character < 256 ){
            std::cout   << " left="   << (char)this->left->character;
        } else 
            std::cout   << " left="   << "T" << (int)this->left->character-255;
    } else
        std::cout   << " left=NULL";
    if (this->right) {
        if ( this->right->character < 256 ){
            std::cout   << " right="   << (char)this->right->character;
        } else 
            std::cout   << " right="   << "T" << (int)this->right->character-255;
    }
    if (this->parent) 
        std::cout   << " parent="   << this->parent->character;
    else
        std::cout   << " parent=NULL";
    std::cout   << std::endl;
}

HuffmanTree::HuffmanTree(){;}

HuffmanTree::HuffmanTree(char action, std::map<char, uint32_t> frequencyTable ){
    
    // Set Up
    for ( auto iter : frequencyTable ){
        HuffmanNode* huffNode = new HuffmanNode(iter.first,iter.second);
        pq.push(huffNode);
    }

    // Building the Tree
    int i = 256;
    while ( pq.size() > 1 ){
        HuffmanNode* node1 =pq.top();
        pq.pop();
        HuffmanNode* node2 = pq.top();
        pq.pop();
        
        HuffmanNode* newNode = new HuffmanNode(i,node1->weight+node2->weight,node1,node2);
        pq.push(newNode);
        i++;
    }
    root = pq.top();
}

void HuffmanTree::printPQ(){
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, HuffmanNode >* pqCopy = new std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, HuffmanNode >();
    std::cout << "###### HuffmanTree printPQ" << std::endl;
    while ( !pq.empty() ){
        HuffmanNode* node = pq.top();
        pq.pop();
        pqCopy->push(node);
        node->print();
    }
    pq = *pqCopy;
}

HuffmanNode* HuffmanTree::getRoot(){
    return this->root;
}

// Print the tree in order using a STACK
void HuffmanTree::printTree(HuffmanNode* root){
    std::queue<HuffmanNode*> s;
    s.push(root);
    std::cout << std::endl << "HuffmanTree printTree: " << std::endl;
    while ( !s.empty()){
        HuffmanNode* tempNode = s.front();
        s.pop();
        tempNode->print();
        if ( tempNode->left != NULL ){
            s.push(tempNode->left);
        }
        if ( tempNode->right != NULL ){
            s.push(tempNode->right);
        }
    }
}



