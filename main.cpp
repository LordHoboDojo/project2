#include <iostream>
#include "Auditorium.h"
#include "Seat.h"
#include "Node.h"

bool check_availability(Auditorium<Seat> auditorium, int row, int num, int i);

void reserve_seats(Auditorium<Seat> auditorium, int row, int num, int t, int t1, int t2);

int main() {
    //variable for filename
    Auditorium<Seat> a("/Users/shaunakkulkarni/CLionProjects/project2/file.txt");
    cout<< a.getBestSeatAvailable(2)->payLoad.row<<endl;


    return 0;
}

void reserve_seats(Auditorium<Seat> auditorium, int row, int num, int t, int t1, int t2) {
    Node<Seat> *head = auditorium.head;
    for (int i = 0;i< num;i++){
        head = head->down;
    }
    for (int i = 0;i< row;i++){
        head = head->right;
    }
    for (int i = 0; i< t;i++){
        head->payLoad.ticketType = 'A';
        head = head->right;
    }
    for (int i = 0; i< t;i++){
        head->payLoad.ticketType = 'C';
        head = head->right;
    }
    for (int i = 0; i< t;i++){
        head->payLoad.ticketType = 'S';
        head = head->right;
    }
}

bool check_availability(Auditorium<Seat> auditorium, int row, int num, int j) {
    Node<Seat> *head = auditorium.head;
    for (int i = 0;i< num;i++){
        head = head->down;
    }
    for (int i = 0;i< row;i++){
        head = head->right;
    }
    for (int i = 0; i< j;i++){
        if (head == nullptr || head->payLoad.ticketType != '.') return false;
        head = head->right;
    }
    return true;
}
