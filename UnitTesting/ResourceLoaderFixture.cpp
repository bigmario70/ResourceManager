#include "gtest/gtest.h"

#include "../ResourceLoader.h"


class ResourceLoaderSuite : public ::testing::Test {

protected:
    ResourceLoaderSuite(): MyLoader1("NonExistentFile.txt"),MyLoader2("/home/mario/CLionProjects/ResourceLoader/FileVuoto.txt"){}

    virtual void SetUp() {
        MyLoader1.loadResources();
        MyLoader2.loadResources();
    }


    ResourceLoader MyLoader1;
    ResourceLoader MyLoader2;
};


TEST_F(ResourceLoaderSuite , LoadFromNonExistentFile) {
    ASSERT_EQ(true, MyLoader1.isFault());
    ASSERT_EQ(0, MyLoader1.getProgress());
}

TEST_F(ResourceLoaderSuite , LoadFromEmptyFile) {
    ASSERT_EQ(false, MyLoader2.isFault());
    ASSERT_EQ(100, MyLoader2.getProgress());
}