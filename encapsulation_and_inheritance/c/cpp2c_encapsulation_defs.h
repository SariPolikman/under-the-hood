//
// Created by sari on 6/14/20.
//

#ifndef C_CPP2C_ENCAPSULATION_DEFS_H
#define C_CPP2C_ENCAPSULATION_DEFS_H
#include <stdio.h>

typedef struct Box
{
    double length;
    double width;
    double height;
}Box;

void Z_3_Box_5_print_v(Box *this);
void Z_3_Box_ctor_d(Box *this, double dim);
void Z_3_Box_ctor_ddd(Box *this, double l, double w, double h);

void deafalt_copy_ctor_Box(Box *this,Box *box);
Box *operator_multi_equal_double(Box *this, double mult);
void Box_dctor_v(Box *const this);



////////////////////////////////////////////////////////////////shelf

//const char* const GV_5_Shelf_7_DEF_MSG;
const char* GV_5_Shelf_7_message;

typedef struct Shelf
{
    Box boxes[3];
}Shelf;

void Shelf_6_setBox_iB(Shelf *const this,int index, const Box* dims);
double Shelf_getVolume_v_c(Shelf *const this);
void Shelf_5_print_v_c(Shelf *const this);




#endif //C_CPP2C_ENCAPSULATION_DEFS_H
