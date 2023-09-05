#include "gtest/gtest.h"

#include "../Inventario.h"

TEST(Inventario, DefaultConstructor) {
    Inventario MyInv;
    ASSERT_EQ(-1, MyInv.getMax());
    ASSERT_EQ(0, MyInv.getElementsSize());
}

TEST(Inventario, ConstructorWithSize2) {
    Inventario MyInv(2);
    ASSERT_EQ(2, MyInv.getMax());
    ASSERT_EQ(0, MyInv.getElementsSize());
}

TEST(Inventario, AddElement) {
    Inventario MyInv(2);
    ASSERT_EQ(2, MyInv.getMax());
    ASSERT_EQ(0, MyInv.getElementsSize());
}
