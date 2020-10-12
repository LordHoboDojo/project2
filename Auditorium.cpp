//
// Created by Shaunak Kulkarni on 10/4/20.
//

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <cmath>
#include "Auditorium.h"
#include "Seat.h"
#include "Node.h"
template <class T>
    Auditorium<T>::Auditorium(const string& filename) {

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
        rowCount = i;
        colCount = line1.length();
        for (int k = 0; k < rowCount-1;k++){
            head = head->up;
        }
        for (int k = 0; k < colCount-1;k++){
        head = head->left;
        }
    }

template<class T>
double Auditorium<T>::checkAvailability(Node<T>* start, int numOfSeats) {
    if (start->payLoad.col +numOfSeats >=colCount) return -1;
    double rowCenter = (rowCount-1)/2.0;
    double colCenter = (colCount-1)/2.0;
    double totalDistance = 0;
    for (int i =0; i< numOfSeats; i++){
        if (start->payLoad.ticketType !='.') return -1;
        totalDistance += sqrt(pow(rowCenter-start->payLoad.row,2)+pow(colCenter-start->payLoad.col,2));
        start = start->right;
    }
    return totalDistance/((double)numOfSeats);
}
template<class T>
Node<T>* Auditorium<T>::getBestSeatAvailable(int numOfSeats) {
    Node<T> *start = head;
    Node<T> *rowStart = head;
    double lowestAvgDistance=-1;
    int rowOfLowestAvgDistance=-1;
    auto *res = ( Node<Seat> *)malloc(sizeof( Node<Seat>));
    for (int i=0;i < rowCount; i++){
        for (int j=0; j< colCount;j++){
            double avgDistance = checkAvailability(start,numOfSeats);
            if (avgDistance != -1){
                if (lowestAvgDistance == avgDistance){
                    if (abs(rowOfLowestAvgDistance - (rowCount - 1) / 2.0) > abs(start->payLoad.row - (rowCount - 1) / 2.0))
                    {
                        rowOfLowestAvgDistance = start->payLoad.row;
                        res = start;
                    }
                    if (abs(rowOfLowestAvgDistance - (rowCount - 1) / 2.0) == abs(start->payLoad.row - (rowCount - 1) / 2.0))
                    {
                        if (start->payLoad.row < rowOfLowestAvgDistance){
                            res = start;
                        }
                        rowOfLowestAvgDistance = min(start->payLoad.row, rowOfLowestAvgDistance);
                    }
                }
                if (lowestAvgDistance > avgDistance|| lowestAvgDistance ==-1){
                    lowestAvgDistance = avgDistance;
                    rowOfLowestAvgDistance = start->payLoad.row;
                    res = start;
                }

            }
            start= start->right;
        }
        rowStart = rowStart->down;
        start = rowStart;
    }

return res;


}



template class Auditorium<Seat>::Auditorium<Seat>;

