#include <gtest/gtest.h>

#include "version.h"

TEST(VersionTest, DefaultConstructor_NoVersionIsSet_VersionIsInvalid)
{
    luminator::version version;

    // Expect default version to be invalid
    EXPECT_FALSE(version.isValid());
}

TEST(VersionTest, ConstructorVersion_VersionIsValidAndCorrect)
{
    luminator::version version(1, 0, 2, 42);

    // Expect default version to be invalid
    EXPECT_TRUE(version.isValid());
    EXPECT_EQ(version.major(), 1);
    EXPECT_EQ(version.minor(), 0);
    EXPECT_EQ(version.subMinor(), 2);
    EXPECT_EQ(version.build(), 42);
}

TEST(VersionTest, ConstructorMinimalVersion_VersionIsValidAndCorrect)
{
    luminator::version version(3, 4);

    // Expect default version to be invalid
    EXPECT_TRUE(version.isValid());
    EXPECT_EQ(version.major(), 3);
    EXPECT_EQ(version.minor(), 4);
    EXPECT_EQ(version.subMinor(), 0);
    EXPECT_EQ(version.build(), 0);
}
