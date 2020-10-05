//
// Created by Shaunak Kulkarni on 10/4/20.
//

#ifndef PROJECT2_AUDITORIUM_H
#define PROJECT2_AUDITORIUM_H

#include <string>
#include "Node.h"
#include "Seat.h"
using namespace std;

template<class T> class Auditorium {
public:
    Node<T> *head;
    Auditorium<T>(const string& filename);

};


#endif //PROJECT2_AUDITORIUM_H
