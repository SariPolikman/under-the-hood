#include "cpp2c_inheritance_defs.h"

//// PhysicalBox Defs ////////////


//void PhysicalBox::printp() const
//{
//printf("PhysicalBox, made of %s; ", material.name());
//print();
//}
void Z_11_PhysicalBox_6_printp_v(PhysicalBox *const this)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox, made of %s; ", names[this -> material.material]);
    Z_3_Box_5_print_v((Box *)this);

}


//PhysicalBox::PhysicalBox(double l, double w, double h)
//:   Box(l, w, h)
//{
//printp();
//}
void Z_11_PhysicalBox_ctor_ddd(PhysicalBox *const this, double l, double w, double h)
{
    Z_3_Box_ctor_ddd((Box *)this, l, w, h);
    this -> material.material = OTHER;
    printf("Material created, set to %s\n", "Other");
    Z_11_PhysicalBox_6_printp_v(this);
}


//PhysicalBox::PhysicalBox(double l, double w, double h, Materials::Types t)
//:   Box(l, w, h)
//,   material(t)
//        {
//                printp();
//        }
void Z_11_PhysicalBox_ctor_dddETypes(PhysicalBox *const this, double l, double w, double h,Types t)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    Z_3_Box_ctor_ddd((Box *)this, l, w, h);
    this -> material.material = t;
    printf("Material created, set to %s\n", names[t]);
    Z_11_PhysicalBox_6_printp_v(this);
}


//PhysicalBox::PhysicalBox(Materials::Types t)
//:   material(t)
//        {
//                printp();
//        }
void Z_11_PhysicalBox_ctor_ETypes(PhysicalBox *const this, Types h)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    Z_3_Box_ctor_ddd((Box *)this, 1, 1, 1);
    this -> material.material = h;
    printf("Material created, set to %s\n", names[h]);
    Z_11_PhysicalBox_6_printp_v(this);
}


//PhysicalBox::~PhysicalBox()
//{
//    printf("PhysicalBox dtor, %f x %f x %f, %s; ", getLength(), getWidth(), getHeight(), material.name());
//}
void Z_11_PhysicalBox_dctor_v(PhysicalBox *const this)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this -> length, this -> width, this -> height, names[this -> material.material]);
    Box_dctor_v((Box *)this);
}


/// WeightBox Defs ////////////


//WeightBox::WeightBox(double l, double w, double h, double wgt)
//:   Box(l, w, h)
//,   weight(wgt)
//        {
//                printw();
//        }
void Z_9_WeightBox_ctor_dddd(WeightBox *const this, double l, double w, double h, double wgt)
{
    Z_3_Box_ctor_ddd((Box *)this, l, w, h);
    this -> weight = wgt;
    Z_9_WeightBox_6_printw_v(this);
}


//WeightBox::WeightBox(const WeightBox& other)
//:   weight(other.weight)
//{
//printw();
//}
void Z_9_WeightBox_cctor_v(WeightBox *const this, const WeightBox* other)
{
    this -> weight = other -> weight;
    Z_3_Box_ctor_d((Box *)this, 1);
    Z_9_WeightBox_6_printw_v(this);
}


//WeightBox::~WeightBox()
//{
//    printf("Destructing WeightBox; ");
//    printw();
//}
void Z_9_WeightBox_dctor_v(WeightBox *const this)
{
    printf("Destructing WeightBox; ");
    Z_9_WeightBox_6_printw_v(this);
    Box_dctor_v((Box *)this);
}


//WeightBox& WeightBox::operator=(const WeightBox& other)
//{
//weight = other.weight;
//return *this;
//}
WeightBox * Z_9_WeightBox_assimentOperator_WeightBox(WeightBox *const this, const WeightBox* other)
{
    this -> weight = other -> weight;
    //TODO called deafault assimentoperator :)
    return this;
}

//void WeightBox::printw() const
//{
//printf("WeightBox, weight: %f; ", weight);
//print();
//}
void Z_9_WeightBox_6_printw_v(WeightBox *const this)
{
    printf("WeightBox, weight: %f; ", this -> weight);
    Z_3_Box_5_print_v((Box *)this);
}