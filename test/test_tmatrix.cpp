#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	const int size = 2;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(m1);

	ASSERT_EQ(m1, m2);
	
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{	
	const int size = 2;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(m1);
	ASSERT_NE(m1.getMem(), m2.getMem());
}

TEST(TDynamicMatrix, can_get_size)
{
	const int size = 3;
	TDynamicMatrix<int> m(size);

	ASSERT_EQ(size, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	const int size = 2;
	TDynamicMatrix<int> m(size);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	m[1][1] = 4;

	EXPECT_EQ(2, m[0][1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	const int size = 3;
	TDynamicMatrix<int> m(size);

	ASSERT_ANY_THROW(m.at(-5));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	const int size = 3;
	TDynamicMatrix<int> m(size);

	ASSERT_ANY_THROW(m.at(10));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{ 
	const int size = 3;
	TDynamicMatrix<int> m(size);

	ASSERT_EQ(m = m, m);
	
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{ 
	const int size = 2;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(size);

	ASSERT_EQ(m2 = m1, m1);
	
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	const int size = 2;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(size + 1);

	m2 = m1;

	ASSERT_EQ(m2.size(), size);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	const int size = 2;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(size + 1);
	m2 = m1;
	ASSERT_EQ(m2, m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	const int size = 2;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(size);

	ASSERT_EQ(m1 == m2, 1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{ 
	const int size = 2;
	TDynamicMatrix<int> m(size);

	ASSERT_EQ(m == m, 1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{ 
	const int size = 2;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(size + 1);

	ASSERT_EQ(m1 == m2, 0);
	
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	const int size = 2;
	TDynamicMatrix<int> m1(size);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;
	m1[1][1] = 4;
	TDynamicMatrix<int> m2(size);
	m2[0][0] = 5;
	m2[0][1] = 6;
	m2[1][0] = 7;
	m2[1][1] = 8;

	TDynamicMatrix<int> res = m1 + m2;

	ASSERT_EQ(res[0][0], 6);
	ASSERT_EQ(res[0][1], 8);
	ASSERT_EQ(res[1][0], 10);
	ASSERT_EQ(res[1][1], 12);

}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	const int size = 3;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(size + 1);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{ 
	const int size = 2;
	TDynamicMatrix<int> m1(size);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;
	m1[1][1] = 4;
	TDynamicMatrix<int> m2(size);
	m2[0][0] = 5;
	m2[0][1] = 6;
	m2[1][0] = 7;
	m2[1][1] = 8;

	TDynamicMatrix<int> res = m1 - m2;

	ASSERT_EQ(res[0][0], -4);
	ASSERT_EQ(res[0][1], -4);
	ASSERT_EQ(res[1][0], -4);
	ASSERT_EQ(res[1][1], -4);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const int size = 3;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(size + 2);

	ASSERT_ANY_THROW(m1 - m2);
}

