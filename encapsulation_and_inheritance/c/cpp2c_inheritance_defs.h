#ifndef C_CPP2C_INHERITANCE_DEFS_H
#define C_CPP2C_INHERITANCE_DEFS_H

#include "cpp2c_encapsulation_defs.h"

//// Materials ////////////
typedef struct Materials
{
    char pad;
}Materials;

typedef enum Z_5_Types_9_Materials
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;

//inline const char* getName(enum Types type)
//{
//    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
//    return names[type];
//}

typedef struct Material_t_inheritance_Materials
{
//    Material_t(Types mat = OTHER): material(mat) { printf("Material created, set to %s\n", name()); }
//    const char* name() const { return getName(material); }
        Types material;
}Material_t;


//TODO// PhysicalBox ////////////

//class PhysicalBox: public Box
typedef struct PhysicalBox_inheritance_Box
{
//    Box box;
    double length;
    double width;
    double height;
    Material_t material;
}PhysicalBox;


    void Z_11_PhysicalBox_6_printp_v();

    void Z_11_PhysicalBox_ctor_ddd(PhysicalBox *const this, double l, double w, double h);
    void Z_11_PhysicalBox_ctor_dddETypes(PhysicalBox *const this, double l, double w, double h,Types t);
    void Z_11_PhysicalBox_ctor_ETypes(PhysicalBox *const this, Types h);
    void Z_11_PhysicalBox_dctor_v(PhysicalBox *const this);

//        ~PhysicalBox();

//        Materials::Types getMaterial() const;




//bool operator==(const PhysicalBox&, const PhysicalBox&);
//bool operator!=(const PhysicalBox&, const PhysicalBox&);


////// PhysicalBox Defs ////////////

//inline Materials::Types PhysicalBox::getMaterial() const
//{
//return material.material;
//}
//
//inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
//{
//return (const Box&)lhs == (const Box&)rhs && lhs.material.material == rhs.material.material;
//}
//
//inline bool operator!=(const PhysicalBox& lhs, const PhysicalBox& rhs)
//{
//return !(lhs == rhs);
//}



//TODO // WeightBox ////////////
typedef struct Z9_WeightBox_inheritance_3_Box
{
    double length;
    double width;
    double height;
    double weight;
}WeightBox;



//        WeightBox(double l, double w, double h, double wgt = 0.0);
void Z_9_WeightBox_ctor_dddd(WeightBox *const this, double l, double w, double h, double wgt);
//        WeightBox(const WeightBox& other);
void Z_9_WeightBox_cctor_v(WeightBox *const this, const WeightBox* other);
//        ~WeightBox();
void Z_9_WeightBox_dctor_v(WeightBox *const this);
//        WeightBox& operator=(const WeightBox& other);
WeightBox * Z_9_WeightBox_assimentOperator_WeightBox(WeightBox *const this, const WeightBox* other);
//
//        double getWeight() const;//TODO inline
//        void printw() const;
    void Z_9_WeightBox_6_printw_v(WeightBox *const this);


//bool operator==(const WeightBox&, const WeightBox&);//TODO inline
//bool operator!=(const WeightBox&, const WeightBox&);//TODO inline
//
//// TODO /// WeightBox Defs ////////////
//
//inline double WeightBox::getWeight() const
//{
//return weight;
//}
//
//inline bool operator==(const WeightBox& lhs, const WeightBox& rhs)
//{
//return (const Box&)lhs == (const Box&)rhs && lhs.getWeight() == rhs.getWeight();
//}
//
//inline bool operator!=(const WeightBox& lhs, const WeightBox& rhs)
//{
//return !(lhs == rhs);
//}

#endif //C_CPP2C_INHERITANCE_DEFS_H
