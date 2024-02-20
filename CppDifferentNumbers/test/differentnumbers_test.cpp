#include <gtest/gtest.h>
#include "list.h"

/*
TEST(deriveKeys, HandlesHelloString) {
    const unsigned char* testString = (unsigned char*)"hello";
    char* hex = NULL;
    binToHex(testString, 5, &hex);
    ASSERT_STREQ(hex, "68656c6c6f");
    ASSERT_STREQ("hello", "Hello");
    delete[] hex;
}

TEST(deriveKeys, ShaSimple) {
    char* arg = (char*)"";
    char* result = sha256(arg);
    ASSERT_STREQ(result, "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
    
    char* arg2 = (char*)"hello";
    char* result2 = sha256(arg2);
    ASSERT_STREQ(result2, "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824");
                    
    char* arg3 = (char*)"Hello, World!";
    char* result3 = sha256(arg3);
    ASSERT_STREQ(result3, "dffd6021bb2bd5b0af676290809ec3a53191dd81c7f70a4b28688a362182986f");
        
    char* arg4 = (char*)"The quick brown fox jumps over the lazy dog";
    char* result4 = sha256(arg4);
    ASSERT_STREQ(result4, "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592");
}
*/

TEST(differentNumbers, Equality) {
    EXPECT_EQ(1, 1);
}

TEST(differentNumbers, TestF) {
	List list; 
	int result = list.f();
    EXPECT_EQ(17, result);
}
