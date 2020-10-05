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
        head = nullptr;
        Node<Seat> *prevLine = ( Node<Seat> *)malloc(sizeof( Node<Seat>));
        while (getline(file, line1)) {
            for (int j = line1.length()-1; j >=0; j--) {
                Node<Seat> *temp = head;
                auto *add = (Node<Seat> *) malloc(sizeof(Node<Seat>));
                Seat data(i, j, line1[j]);
                add->payLoad = data;
                if (j == line1.length()-1) {
                    head = add;
                } else {
                    head = add;
                    add->left = temp;
                    temp->right = head;
                }
            }
            if (i >= 1) {
            for (int k = line1.length() - 1; k >= 0; k--) {
                Node<Seat> *headT = head;
                headT->up = prevLine;
                prevLine->down = headT;
                headT = headT->left;
                prevLine = prevLine->left;
            }
        }
            prevLine = head;
            i++;
        }
        Node<Seat> *ct = head;
        while(ct != nullptr){
           cout<<ct->payLoad.ticketType;
           ct = ct->left;
        }


    }

void printAuditorium(){

}

template class Auditorium<Seat>::Auditorium<Seat>;

