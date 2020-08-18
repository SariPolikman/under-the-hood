#include <stdio.h>
#include "cpp2c_inheritance_defs.h"

void Z11_doMaterials_v()
{
    Materials mat;
    Material_t mat1;
    Material_t mat2;
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };

    printf("\n--- Start doMaterials() ---\n\n");

//    Materials mat;
//    printf("Size of Materials: %lu\n", sizeof(Materials));
//    printf("Size of mat: %lu\n", sizeof(mat));
//    printf("Size of Materials::Types: %lu\n", sizeof(Materials::Types));
//    printf("Size of Material_t: %lu\n", sizeof(Material_t));
//

    printf("Size of Materials: %lu\n",sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

//    struct MatTest { Materials mat; Material_t mat_t; };
//    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));
    typedef struct MatTest { Materials mat; Material_t mat_t; }MatTest;
    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));

//    Material_t mat1;
    //  Material_t(Types mat = OTHER): material(mat) { printf("Material created, set to %s\n", name()); }
        //    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
        //    return names[type];

    mat1.material = OTHER;
    printf("Material created, set to %s\n", names[mat1.material]);

//    Material_t mat2(Materials::METAL);
    mat2.material = METAL;
    printf("Material created, set to %s\n", names[mat2.material]);

//    printf("\n--- End doMaterials() ---\n\n");
    printf("\n--- End doMaterials() ---\n\n");
}

void Z11_doPhysicalBox_v()
{
    PhysicalBox pb1, pb2,pb4;
    printf("\n--- Start doPhysicalBox() ---\n\n");

    //    PhysicalBox pb1(8, 6, 4, Materials::PLASTIC);

    Z_11_PhysicalBox_ctor_dddETypes(&pb1, 8, 6, 4, PLASTIC);

    //  PhysicalBox pb2(Materials::WOOD);

    Z_11_PhysicalBox_ctor_ETypes(&pb2, WOOD);

    //  PhysicalBox pb3(7, 7, 7);
    PhysicalBox pb3;
    Z_11_PhysicalBox_ctor_ddd(&pb3, 7, 7, 7);

    printf("\npb4 is copy-constructed from pb1\n");

    //    PhysicalBox pb4 = pb1;
//    Z_3_Box_ctor_d((Box *)&pb1,1);//TODO why??
    pb4 = pb1;

//    pb4.printp();
//    pb1.printp();
    Z_11_PhysicalBox_6_printp_v(&pb4);
    Z_11_PhysicalBox_6_printp_v(&pb1);

    //    printf("pb4 %s pb1\n", pb4 == pb1 ? "equals" : "does not equal");
    printf("pb4 %s pb1\n",(pb4.width == pb1.width &&
                                 pb4.length == pb1.length &&
                                 pb4.height == pb1.height )&&
                                 (pb4.material.material == pb1.material.material) ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
    Z_11_PhysicalBox_6_printp_v(&pb4);
    Z_11_PhysicalBox_6_printp_v(&pb3);
    printf("pb4 %s pb1\n",(pb4.width == pb3.width &&
                           pb4.length == pb3.length &&
                           pb4.height == pb3.height )&&
                          (pb4.material.material == pb3.material.material) ? "equals" : "does not equal");


    printf("\n--- End doPhysicalBox() ---\n\n");
    Z_11_PhysicalBox_dctor_v(&pb4);
    Z_11_PhysicalBox_dctor_v(&pb3);
    Z_11_PhysicalBox_dctor_v(&pb2);
    Z_11_PhysicalBox_dctor_v(&pb1);


}

void Z9_doWeightBox_v()
{
    WeightBox pw1, pw2, pw3, pw4;
    printf("\n--- Start doWeightBox() ---\n\n");
//
//    WeightBox pw1(8, 6, 4, 25);
//    WeightBox pw2(1, 2, 3);
//    WeightBox pw3(10, 20, 30, 15);
    Z_9_WeightBox_ctor_dddd(&pw1, 8, 6, 4, 25);
    Z_9_WeightBox_ctor_dddd (&pw2, 1, 2, 3, 0.0);
    Z_9_WeightBox_ctor_dddd (&pw3,10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");

//    WeightBox pw4 = pw1;
    Z_9_WeightBox_cctor_v(&pw4, &pw1);

//    pw4.printw();
    Z_9_WeightBox_6_printw_v(&pw4);
//    pw1.printw();
    Z_9_WeightBox_6_printw_v(&pw1);
    printf("pw4 %s pw1\n", (pw4.width == pw1.width &&
                            pw4.length == pw1.length &&
                            pw4.height == pw1.height )
                              && pw4.weight == pw1.weight ?
                              "equals" : "does not equal");
//
    printf("\npw4 is copy-assigned from pw3\n");
//    pw4 = pw3;
    Z_9_WeightBox_assimentOperator_WeightBox(&pw4, &pw3);
//    pw4.printw();
    Z_9_WeightBox_6_printw_v(&pw4);
//    pw3.printw();
    Z_9_WeightBox_6_printw_v(&pw3);
//    printf("pw4 %s pw3\n", pw4 == pw3 ? "equals" : "does not equal");
    printf("pw4 %s pw3\n", (pw4.width == pw3.width &&
                            pw4.length == pw3.length &&
                            pw4.height == pw3.height )
                           && pw4.weight == pw3.weight ?
                           "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");

    Z_9_WeightBox_dctor_v(&pw4);
    Z_9_WeightBox_dctor_v(&pw3);
    Z_9_WeightBox_dctor_v(&pw2);
    Z_9_WeightBox_dctor_v(&pw1);
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    Z11_doMaterials_v();

    Z11_doPhysicalBox_v();

    Z9_doWeightBox_v();

    printf("\n--- End main() ---\n\n");

}