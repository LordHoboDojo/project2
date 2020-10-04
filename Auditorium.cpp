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
Auditorium<T>::Auditorium(string filename) : head(head){
    {

        ifstream file(filename);
        stringstream ss1;
        ss1 << file.rdbuf();
        string s = ss1.str();
        cout<< s[3];

    }
}



template class Auditorium<Seat>::Auditorium<Seat>;

