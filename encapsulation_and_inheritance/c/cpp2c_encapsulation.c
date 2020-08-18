#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"
extern const char* const GV_5_Shelf_7_DEF_MSG;
extern const char* GV_5_Shelf_7_message;

//static Box largeBox(10, 20, 30);
static Box SV_8_largeBox;




//void thisFunc()
//{
//    std::printf("\n--- thisFunc() ---\n\n");
//    static Box box99(99, 99, 99);
//    box99 *= 10;
//}
static char bool_this=0;
static Box box99;
void _8_thisFunc_v()
{
    printf("\n--- thisFunc() ---\n\n");

    if (!bool_this++)
        _3_Box_ctor_ddd(&box99,99,99,99);

    operator_multi_equal_double(&box99,10);
}

//void thatFunc()
//{
//    std::printf("\n--- thatFunc() ---\n\n");
//    static Box box88(88, 88, 88);
//    box88 *= 10;
//}

char bool_that = 0;
static Box box88;
void _8_thatFunc_v()
{
    printf("\n--- thatFunc() ---\n\n");

    if (!bool_that++)
        _3_Box_ctor_ddd(&box88, 88,88,88);
    operator_multi_equal_double(&box88, 10);

}


void _7_doBoxes_v()
{
    Box b1, b2, b3, b4;
    //    std::printf("\n--- Start doBoxes() ---\n\n");
    printf("\n--- Start doBoxes() ---\n\n");

    //    Box b1(3);
    //    Box b2(4, 5, 6);

    _3_Box_ctor_d(&b1, 3);
    _3_Box_ctor_ddd(&b2, 4,5,6);

    //    std::printf("b1 volume: %f\n", b1.getVolume());
    //    std::printf("b2 volume: %f\n", b2.getVolume());

    //    inline double Box::getVolume() const
    //    {
    //        return width * length * height;
    //    }
    printf("b1 volume: %f\n", b1.length * b1.width * b1.height);
    printf("b2 volume: %f\n", b2.length * b2.width * b2.height);

    //    b1 *= 1.5;
    //    b2 *= 0.5;
    operator_multi_equal_double(&b1,1.5); //TODO add Box to name mangling
    operator_multi_equal_double(&b2, 0.5);

    //    std::printf("b1 volume: %f\n", b1.getVolume());
    //    std::printf("b2 volume: %f\n", b2.getVolume());
    printf("b1 volume: %f\n", b1.length * b1.width * b1.height);
    printf("b2 volume: %f\n", b2.length * b2.width * b2.height);

    //    Box b3 = b2;

    b3 = b2;

    //    Box b4 = 3 * b2;
        //    inline Box operator*(const Box& box, double mult)
        //    {
        //        Box ret = box;
        //        ret *= mult;
        //        return ret;
        //    }

    b4 = b2;
    operator_multi_equal_double(&b4, 3);




    printf("b3 %s b4\n", b3.width == b4.width && b3.length == b4.length && b3.height == b4.height ? "equals" : "does not equal");

    //    b3 *= 1.5;
    //    b4 *= 0.5;
    operator_multi_equal_double(&b3,1.5);
    operator_multi_equal_double(&b4,0.5);

    //    std::printf("Now, b3 %s b4\n", b3 == b4 ? "equals" : "does not equal");
    printf("Now, b3 %s b4\n", b3.width == b4.width && b3.length == b4.length && b3.height == b4.height ? "equals" : "does not equal");

    //    std::printf("\n--- End doBoxes() ---\n\n");
    printf("\n--- End doBoxes() ---\n\n");

    Box_dctor_v(&b4);
    Box_dctor_v(&b3);
    Box_dctor_v(&b2);
    Box_dctor_v(&b1);



}


void _9_doShelves_v()
{
    Box aBox, box,box0,box1,box2;
    Shelf aShelf;
    //    std::printf("\n--- start doShelves() ---\n\n");
    printf("\n--- start doShelves() ---\n\n");

    //    Box aBox = 5;
    _3_Box_ctor_d(&aBox, 5);


    //    Shelf aShelf;



    _3_Box_ctor_d(&box0, 1);
    aShelf.boxes[0] = box0;

    _3_Box_ctor_d(&box1, 1);
    aShelf.boxes[1] = box1;

    _3_Box_ctor_d(&box2, 1);
    aShelf.boxes[2] = box2;




    //    aShelf.print();
    //    aShelf.setBox(1, largeBox);
    //    aShelf.setBox(0, aBox);
    Shelf_5_print_v_c(&aShelf);
    Shelf_6_setBox_iB(&aShelf, 1, &SV_8_largeBox);
    Shelf_6_setBox_iB(&aShelf,0,&aBox);

//    aShelf.print();
//    aShelf.setMessage("This is the total volume on the shelf:");
//    aShelf.print();
//    Shelf::setMessage("Shelf's volume:");
//    aShelf.print();

    Shelf_5_print_v_c(&aShelf);
    GV_5_Shelf_7_message = "This is the total volume on the shelf:" ;
    Shelf_5_print_v_c (&aShelf);
    GV_5_Shelf_7_message = "Shelf's volume:" ;
    Shelf_5_print_v_c (&aShelf);

    //    aShelf.setBox(1, Box(2, 4, 6));


    _3_Box_ctor_ddd(&box, 2, 4, 6);
    Shelf_6_setBox_iB(&aShelf, 1, &box);
    Box_dctor_v(&box);


    //    aShelf.setBox(2, 2);


    _3_Box_ctor_d(&box, 2);
    Shelf_6_setBox_iB(&aShelf, 2, &box);
    Box_dctor_v(&box);


    //    aShelf.print();
    Shelf_5_print_v_c( &aShelf );



    //    std::printf("\n--- end doShelves() ---\n\n");
    printf("\n--- end doShelves() ---\n\n");

    Box_dctor_v(&aShelf.boxes[2]);
    Box_dctor_v(&aShelf.boxes[1]);
    Box_dctor_v(&aShelf.boxes[0]);
    Box_dctor_v(&aBox);
}




int main() {
    _3_Box_ctor_ddd(&SV_8_largeBox, 10,20,30);

    printf("\n--- Start main() ---\n\n");

    _7_doBoxes_v(); //TODO name mangling

    _8_thisFunc_v();
    _8_thisFunc_v();
    _8_thisFunc_v();
    _8_thatFunc_v();
    _8_thatFunc_v();

    _9_doShelves_v();

    printf("\n--- End main() ---\n\n");

    Box_dctor_v ( &SV_8_largeBox );
    if(bool_this)
        Box_dctor_v ( &box99 );
    if(bool_that)
        Box_dctor_v ( &box88 );
    return 0;
}
