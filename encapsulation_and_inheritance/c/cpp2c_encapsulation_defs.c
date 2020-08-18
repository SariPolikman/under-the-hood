#include "cpp2c_encapsulation_defs.h"

//void Box::print() const
//{
//printf("Box: %f x %f x %f\n", length, width, height);
//}

void Z_3_Box_5_print_v(Box *this)
{
    printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}


//Box::Box(double dim)
//:   length(dim)
//,   width(dim)
//,   height(dim)
//{
//    print();
//}

void Z_3_Box_ctor_d(Box *this, double dim)
{
    this -> length = dim;
    this -> height = dim;
    this -> width = dim;
    Z_3_Box_5_print_v(this);

}

//Box::Box(double l, double w, double h)
//:   length(l)
//,   width(w)
//,   height(h)
//{
//    print();
//}

void Z_3_Box_ctor_ddd(Box *this, double l, double w, double h)
{
    this -> length = l;
    this -> height = h;
    this -> width = w;
    Z_3_Box_5_print_v(this);

}



void deafalt_copy_ctor_Box(Box *this,Box *box)
{
    this -> width = box->width;
    this ->height = box->height;
    this ->length = box->length;

}

//Box& Box::operator*=(double mult)
//{
//width *= mult;
//height *= mult;
//length *= mult;
//
//return *this;
//}

Box *operator_multi_equal_double(Box *this, double mult)
{
    this -> width *= mult;
    this ->height *= mult;
    this ->length *= mult;

return this;
}



//Box::~Box()
//{
//    std::printf("Box destructor, %f x %f x %f\n", width, height, length);
//}

void Box_dctor_v(Box *const this)
{
    printf("Box destructor, %f x %f x %f\n", this -> width, this -> height, this -> length);
}


//////////////////////////////////////////////////shelf


//const char* const GV_5_Shelf_7_DEF_MSG = ;
const char* GV_5_Shelf_7_message ="The total volume held on the shelf is";

//void Shelf::setBox(int index, const Box& dims)
//{
//boxes[index] = dims;
//}

void Shelf_6_setBox_iB(Shelf *const this,int index, const Box* dims)
{
    this -> boxes[index] = *dims;
}

//double Shelf::getVolume() const
//{
//double vol = 0;
//for (size_t i = 0; i < NUM_BOXES; ++i)
//vol += boxes[i].getVolume();
//
//return vol;
//}

double Shelf_getVolume_v_c(Shelf *const this)
{
    double vol = 0;

    for (size_t i = 0; i < 3; ++i)
        vol += this -> boxes[i].width * this -> boxes[i].length * this -> boxes[i].height;

return vol;
}

//void Shelf::print() const
//{
//std::printf("%s %f\n", message, getVolume());
//}

void Shelf_5_print_v_c(Shelf *const this)
{
    printf("%s %f\n", GV_5_Shelf_7_message, Shelf_getVolume_v_c(this));
}


