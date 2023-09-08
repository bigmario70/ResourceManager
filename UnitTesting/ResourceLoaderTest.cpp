#include "gtest/gtest.h"

#include "../ResourceLoader.h"

TEST(ResourceLoader, LoadFromNonExistentFile) {
    ResourceLoader MyLoader("NonExistentFile.txt");
    MyLoader.loadResources();
    ASSERT_EQ(true, MyLoader.isFault());
    ASSERT_EQ(0, MyLoader.getProgress());
}

TEST(ResourceLoader, LoadFromEmptyFile) {
    ResourceLoader MyLoader("/home/mario/CLionProjects/ResourceLoader/FileVuoto.txt");
    MyLoader.loadResources();
    ASSERT_EQ(false, MyLoader.isFault());
    ASSERT_EQ(100, MyLoader.getProgress());
}