/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, length_difference_0)
{
	// This will test the reference and entry being the same
	tappity instance("test");
	instance.entry("test");
	double actual = instance.length_difference();
    ASSERT_EQ(actual, 0);
}

TEST(tappityTest, length_difference_larger_reference)
{
	// This will test when the reference is larger and hows more different characters
	tappity instance("testing 1 2");
	instance.entry("test");
	double actual = instance.length_difference();
    ASSERT_EQ(actual, 7);
}

TEST(tappityTest, length_difference_larger_entry)
{
	// This will test when the entry is larger and hows more different characters
	tappity instance("test");
	instance.entry("1 2 3");
	double actual = instance.length_difference();
    ASSERT_EQ(actual, 1);
}

TEST(tappityTest, length_difference_both_empty)
{
	// This will test when the reference and entry are both empty
	tappity instance("");
	instance.entry("");
	double actual = instance.length_difference();
    ASSERT_EQ(actual, 0);
}

TEST(tappityTest, accuracy_empty_entry)
{ 
	// This will test if the entry is blank and you will have 0 accuracy
	tappity instance("The Dog pet the Cat");
	instance.entry("");
	double actual = instance.accuracy();
    ASSERT_EQ(actual, 0);
}

TEST(tappityTest, accuracy_empty_reference)
{ 
	// This will test if the referenece is blank and you will have 0 accuracy
	tappity instance("");
	instance.entry("Did I Win?");
	double actual = instance.accuracy();
    ASSERT_EQ(actual, 0);
}

TEST(tappityTest, accuracy_longer_reference)
{ 
	// This will test when the reference is larger than the entry and calculate accuracy
	tappity instance("See you loose!");
	instance.entry("Yee");
	double actual = instance.accuracy();
    ASSERT_EQ(actual, 14);
}

TEST(tappityTest, accuracy_longer_entry)
{ 
	// This will test when the entry is larger than the reference and calculate accuracy
	tappity instance("Yes");
	instance.entry("See I Win!");
	double actual = instance.accuracy();
    ASSERT_EQ(actual, 10);
}

TEST(tappityTest, accuracy_longer_entry_same_reference)
{ 
	// This will test when the reference and input match, but the input is larger
	tappity instance("win");
	instance.entry("win I did not");
	double actual = instance.accuracy();
    ASSERT_EQ(actual, 23);
}

TEST(tappityTest, accuracy_longer_reference_same_entry)
{ 
	// This will test when the input and reference match, but the reference is larger
	tappity instance("see I win");
	instance.entry("see");
	double actual = instance.accuracy();
    ASSERT_EQ(actual, 33);
}

TEST(tappityTest, accuracy_both_empty)
{
	// This will test when both the reference and input are empty and user is 100% accurate
	tappity instance("");
	instance.entry("");
	double actual = instance.accuracy();
    ASSERT_EQ(actual, 100);
}

TEST(tappityTest, accuracy_both_empty_NOT_0)
{
	// This will test when both the reference and entry are empty, but is not 0% accurate
	tappity instance("");
	instance.entry("");
	double actual = instance.accuracy();
    ASSERT_NE(actual, 0);
}

TEST(tappityTest, accuracy_same_string)
{
	// This will test when both the reference and entry are the same string but one is capitalized and the other isn't
	tappity instance("You are so good at typing!");
	instance.entry("You are so good at typing!");
	double actual = instance.accuracy();
    ASSERT_EQ(actual, 100);
}

TEST(tappityTest, accuracy_same_but_different_case)
{
	// This will test when both the reference and entry are the same string but one is capitalized and the other isn't
	tappity instance("test");
	instance.entry("TEST");
	double actual = instance.accuracy();
    ASSERT_EQ(actual, 0);
}