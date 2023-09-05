#include "gtest/gtest.h"

#include "../Inventario.h"


class InventarioSuite : public ::testing::Test {

protected:
    InventarioSuite():MyInv(),MyInvEmpty(),MyInvMax2(2){}

    virtual void SetUp() {
        MyInv.addElement(new Robot("Pippo", true));
        MyInv.addElement(new Equipment("Scudo", false));
        MyInv.addElement(new Weapon("Arco", 10));
    }

    Inventario MyInv;
    Inventario MyInvEmpty;
    Inventario MyInvMax2;
};


TEST_F(InventarioSuite , DefaultConstructor) {
    ASSERT_EQ(-1, MyInvEmpty.getMax());
    ASSERT_EQ(0, MyInvEmpty.getElementsSize());
}

