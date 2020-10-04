//
// Created by Shaunak Kulkarni on 10/4/20.
//

#include "Seat.h"

Seat::Seat(int row, int col, char ticketType) : row(row), col(col), ticketType(ticketType) {}

int Seat::getRow() const {
    return row;
}

void Seat::setRow(int row) {
    Seat::row = row;
}

int Seat::getCol() const {
    return col;
}

void Seat::setCol(int col) {
    Seat::col = col;
}

char Seat::getTicketType() const {
    return ticketType;
}

void Seat::setTicketType(char ticketType) {
    Seat::ticketType = ticketType;
}
