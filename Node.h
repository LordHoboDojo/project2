//
// Created by Shaunak Kulkarni on 10/4/20.
//

#ifndef PROJECT2_NODE_H
#define PROJECT2_NODE_H

#include "Seat.h"

template <class T>
class Node {
public:


    Node() : payLoad(payLoad){
        up = nullptr;
        down = nullptr;
        left = nullptr;
        right = nullptr;

    };
    Node<T> (Node<T>* t):payLoad(payLoad){
        this->payLoad = t->payLoad;
        this->up = t->up;
        this->down = t->down;
        this->left = t->left;
        this->right = t->right;
    }
    Node* up;
    Node* down;
    Node* left;
    Node* right;
    T payLoad;
    Node<T>(Node *up, Node *down, Node *left, Node *right, T payLoad) : up(up), down(down), left(left), right(right),
                                                                     payLoad(payLoad) {}
    Node<T>(T payload) : payLoad(payLoad){}
    Node *getUp() const {
        return up;
    }

    void setUp(Node *up) {
        Node::up = up;
    }

    Node *getDown() const {
        return down;
    }

    void setDown(Node *down) {
        Node::down = down;
    }

    Node *getLeft() const {
        return left;
    }

    void setLeft(Node *left) {
        Node::left = left;
    }

    Node *getRight() const {
        return right;
    }

    void setRight(Node *right) {
        Node::right = right;
    }

    T getPayLoad() const {
        return payLoad;
    }

    void setPayLoad(T payLoad) {
        Node::payLoad = payLoad;
    }

};


#endif //PROJECT2_NODE_H
