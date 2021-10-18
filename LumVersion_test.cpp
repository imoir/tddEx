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

    EXPECT_TRUE(version.isValid());
    EXPECT_EQ(version.major(), 1);
    EXPECT_EQ(version.minor(), 0);
    EXPECT_EQ(version.subMinor(), 2);
    EXPECT_EQ(version.build(), 42);
}

TEST(VersionTest, ConstructorMinimalVersion_VersionIsValidAndCorrect)
{
    luminator::version version(3, 4);

    EXPECT_TRUE(version.isValid());
    EXPECT_EQ(version.major(), 3);
    EXPECT_EQ(version.minor(), 4);
    EXPECT_EQ(version.subMinor(), 0);
    EXPECT_EQ(version.build(), 0);
}

TEST(VersionTest, ConstructorDefault_SetValidCompleteVersion_VersionIsValidAndCorrect)
{
    luminator::version version;

    bool result = version.fromString("3.4.2.42");

    EXPECT_TRUE(result);
    EXPECT_TRUE(version.isValid());
    EXPECT_EQ(version.major(), 3);
    EXPECT_EQ(version.minor(), 4);
    EXPECT_EQ(version.subMinor(), 2);
    EXPECT_EQ(version.build(), 42);
}

TEST(VersionTest, ConstructorDefault_SetValidMinimalVersion_VersionIsValidAndCorrect)
{
    luminator::version version;

    bool result = version.fromString("0.5");

    EXPECT_TRUE(result);
    EXPECT_TRUE(version.isValid());
    EXPECT_EQ(version.major(), 0);
    EXPECT_EQ(version.minor(), 5);
    EXPECT_EQ(version.subMinor(), 0);
    EXPECT_EQ(version.build(), 0);
}

TEST(VersionTest, ConstructorDefault_SetValidVersionNoBuild_VersionIsValidAndCorrect)
{
    luminator::version version;

    bool result = version.fromString("45.6.7");

    EXPECT_TRUE(result);
    EXPECT_TRUE(version.isValid());
    EXPECT_EQ(version.major(), 45);
    EXPECT_EQ(version.minor(), 6);
    EXPECT_EQ(version.subMinor(), 7);
    EXPECT_EQ(version.build(), 0);
}

TEST(VersionTest, ConstructorDefault_SetValidCompleteVersionLeadingSpacesOK_VersionIsValidAndCorrect)
{
    luminator::version version;

    bool result = version.fromString(" 32.49.24.425");

    EXPECT_TRUE(result);
    EXPECT_TRUE(version.isValid());
    EXPECT_EQ(version.major(), 32);
    EXPECT_EQ(version.minor(), 49);
    EXPECT_EQ(version.subMinor(), 24);
    EXPECT_EQ(version.build(), 425);
}

TEST(VersionTest, ConstructorDefault_SetValidCompleteVersionTrailingSpacesOK_VersionIsValidAndCorrect)
{
    luminator::version version;

    bool result = version.fromString("62.39.74.925 ");

    EXPECT_TRUE(result);
    EXPECT_TRUE(version.isValid());
    EXPECT_EQ(version.major(), 62);
    EXPECT_EQ(version.minor(), 39);
    EXPECT_EQ(version.subMinor(), 74);
    EXPECT_EQ(version.build(), 925);
}

TEST(VersionTest, ConstructorDefault_SetInvalidVersionNoMinor_VersionIsInvalid)
{
    luminator::version version;

    bool result = version.fromString("2");

    EXPECT_FALSE(result);
    EXPECT_FALSE(version.isValid());
}

TEST(VersionTest, ConstructorDefault_SetInvalidVersionIncompleteMinor_VersionIsInvalid)
{
    luminator::version version;

    bool result = version.fromString("2.");

    EXPECT_FALSE(result);
    EXPECT_FALSE(version.isValid());
}

TEST(VersionTest, ConstructorDefault_SetInvalidVersionMissingMinor_VersionIsInvalid)
{
    luminator::version version;

    bool result = version.fromString("2..6");

    EXPECT_FALSE(result);
    EXPECT_FALSE(version.isValid());
}

TEST(VersionTest, ConstructorDefault_SetInvalidVersionMissingSubMinor_VersionIsInvalid)
{
    luminator::version version;

    bool result = version.fromString("2.6.");

    EXPECT_FALSE(result);
    EXPECT_FALSE(version.isValid());
}

TEST(VersionTest, ConstructorDefault_SetInvalidVersionMissingBuild_VersionIsInvalid)
{
    luminator::version version;

    bool result = version.fromString("2.6.8.");

    EXPECT_FALSE(result);
    EXPECT_FALSE(version.isValid());
}

TEST(VersionTest, ConstructorDefault_SetInvalidVersionSpaceBeforeBuild_VersionIsInvalid)
{
    luminator::version version;

    bool result = version.fromString("2.6.8. 9");

    EXPECT_FALSE(result);
    EXPECT_FALSE(version.isValid());
}

TEST(VersionTest, ConstructorDefault_SetInvalidVersionSpaceAfterMinor_VersionIsInvalid)
{
    luminator::version version;

    bool result = version.fromString("2.6 .8.9");

    EXPECT_FALSE(result);
    EXPECT_FALSE(version.isValid());
}

TEST(VersionTest, ConstructorDefault_SetInvalidVersionLetterAfterMinor_VersionIsInvalid)
{
    luminator::version version;

    bool result = version.fromString("2.6a.8.9");

    EXPECT_FALSE(result);
    EXPECT_FALSE(version.isValid());
}

TEST(VersionTest, ConstructorDefault_SetInvalidVersionText_VersionIsInvalid)
{
    luminator::version version;

    bool result = version.fromString("hello");

    EXPECT_FALSE(result);
    EXPECT_FALSE(version.isValid());
}

TEST(VersionTest, ConstructorDefault_SetInvalidVersionBlank_VersionIsInvalid)
{
    luminator::version version;

    bool result = version.fromString("");

    EXPECT_FALSE(result);
    EXPECT_FALSE(version.isValid());
}
