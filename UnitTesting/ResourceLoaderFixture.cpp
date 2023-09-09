#include "gtest/gtest.h"

#include "../ResourceLoader.h"
#include "MockProgressBar.h"


class ResourceLoaderSuite : public ::testing::Test {

protected:
    ResourceLoaderSuite(): myLoader1("NonExistentFile.txt"),
                           myLoader2("/home/mario/CLionProjects/ResourceLoader/FileVuoto.txt"),
                           myLoader3("/home/mario/CLionProjects/ResourceLoader/prova.txt"),
                           myPB(&myLoader3){}

    virtual void SetUp() {
        myLoader1.loadResources();
        myLoader2.loadResources();
        myLoader3.loadResources();
        myPBProgressHistory=myPB.getProgressHistory();

    }


    ResourceLoader myLoader1;
    ResourceLoader myLoader2;
    ResourceLoader myLoader3;
    MockProgressBar myPB;
    std::vector<int> myPBProgressHistory;
};


TEST_F(ResourceLoaderSuite , LoadFromNonExistentFile) {
    ASSERT_EQ(true, myLoader1.isFault());
    ASSERT_EQ(0, myLoader1.getProgress());
}

TEST_F(ResourceLoaderSuite , LoadFromEmptyFile) {
    ASSERT_EQ(false, myLoader2.isFault());
    ASSERT_EQ(100, myLoader2.getProgress());
}

TEST_F(ResourceLoaderSuite , ProgressCalculation) {
    ASSERT_EQ(9, myPBProgressHistory[0]);
    ASSERT_EQ(18, myPBProgressHistory[1]);
    ASSERT_EQ(27, myPBProgressHistory[2]);
    ASSERT_EQ(36, myPBProgressHistory[3]);
    ASSERT_EQ(46, myPBProgressHistory[4]);
    ASSERT_EQ(55, myPBProgressHistory[5]);
    ASSERT_EQ(64, myPBProgressHistory[6]);
    ASSERT_EQ(73, myPBProgressHistory[7]);
    ASSERT_EQ(82, myPBProgressHistory[8]);
    ASSERT_EQ(92, myPBProgressHistory[9]);
    ASSERT_EQ(100, myPBProgressHistory[10]);
}