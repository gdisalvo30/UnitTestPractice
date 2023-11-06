/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

//leading char tests
TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest, single_letter_password)
{
	//set your state
    Password my_password;
	//invoke unit
	int actual = my_password.count_leading_characters("Z");
	//assert my expected outcome
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, threeleading_pw)
{
	//set your state
    Password my_password;
	//invoke unit
	int actual = my_password.count_leading_characters("cccat");
	//assert my expected outcome
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, case_sensitive_pw)
{
	//set your state
    Password my_password;
	//invoke unit
	int actual = my_password.count_leading_characters("oooOoOctopus");
	//assert my expected outcome
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, special_char_pw)
{
	//set your state
    Password my_password;
	//invoke unit
	int actual = my_password.count_leading_characters("m!onkey");
	//assert my expected outcome
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, starting_special_char_pw)
{
	//set your state
    Password my_password;
	//invoke unit
	int actual = my_password.count_leading_characters("???raccoon");
	//assert my expected outcome
	ASSERT_EQ(3,actual);
}

//mixed_case tests
TEST(PasswordTest, mixed_case_simple)
{
	//set your state
    Password my_password;
	//invoke unit
	int actual = my_password.has_mixed_case("aA");
	//assert my expected outcome
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, mixed_special_char)
{
	//set your state
    Password my_password;
	//invoke unit
	int actual = my_password.has_mixed_case("b!?#B");
	//assert my expected outcome
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, dif_letters)
{
	//set your state
    Password my_password;
	//invoke unit
	int actual = my_password.has_mixed_case("asadflkj;dsalfjkZx");
	//assert my expected outcome
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, mixed_spaces)
{
	//set your state
    Password my_password;
	//invoke unit
	int actual = my_password.has_mixed_case("a A");
	//assert my expected outcome
	ASSERT_EQ(true,actual);
}

