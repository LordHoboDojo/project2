//
// Created by Shaunak Kulkarni on 10/4/20.
//

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include "Auditorium.h"
#include "Seat.h"
#include "Node.h"
template <class T>
    Auditorium<T>::Auditorium(const string& filename) : head(head){

        ifstream file(filename);
        string line1;
        int i = 0;
        auto *prevLine = ( Node<Seat> *)malloc(sizeof( Node<Seat>));
        while (getline(file, line1)) {
            for (int j = line1.length()-1; j >=0; j--) {
                Node<Seat> *temp = head;
                auto *add = (Node<Seat> *) malloc(sizeof(Node<Seat>));
                char seat = line1[j] ;
                Seat data(i, j, seat);
                add->payLoad = data;
                if (j == line1.length()-1) {
                    head = add;
                } else {
                    head = add;
                    temp->left = head;
                    head->right = temp;
                }
            }
            Node<Seat> *headT = head;
            if (i >= 1) {
            for (int k = line1.length() - 1; k >= 0; k--) {
                head->up = prevLine;
                prevLine->down = head;
                if(head->right != nullptr) head = head->right;
                prevLine = prevLine->right;
            }
        }
            prevLine = headT;
            i++;
        }
        rowCount = i-1;
        colCount = line1.length();
        for (int k = 0; k < rowCount;k++){
            head = head->up;
        }
        for (int k = 0; k < colCount-1;k++){
        head = head->left;
        }
        cout << head->payLoad.ticketType;
    }

template<class T>
char Auditorium<T>::printAuditorium(Node<Seat> *n) {
    Node<Seat>* rPtr;
    // pointer to move down
    Node<Seat>* dPtr = n;

    // loop till node->down is not NULL
    while (dPtr) {

        rPtr = dPtr;

        // loop till node->right is not NULL
        while (rPtr) {
            cout << rPtr->payLoad.ticketType;
            rPtr = rPtr->right;
        }
        cout << endl;
        dPtr = dPtr->up;
    }
    return 0;
}


template class Auditorium<Seat>::Auditorium<Seat>;

