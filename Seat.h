//
// Created by Shaunak Kulkarni on 10/4/20.
//

#ifndef PROJECT2_SEAT_H
#define PROJECT2_SEAT_H


class Seat {
public:
    int row;
    int col;
    char ticketType;

    int getRow() const;

    void setRow(int row);

    int getCol() const;

    void setCol(int col);

    char getTicketType() const;

    void setTicketType(char ticketType);

    Seat(int row, int col, char ticketType);
};


#endif //PROJECT2_SEAT_H
