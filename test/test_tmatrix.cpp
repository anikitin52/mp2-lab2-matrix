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
	/**/
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{	

}

TEST(TDynamicMatrix, can_get_size)
{
	const int size = 3;
	TDynamicMatrix<int> m(size);

	ASSERT_EQ(size, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	const int size = 3;
	TDynamicVector<int> v(size);
	v[0] = 1; v[1] = 2; v[2] = 3;

	TDynamicMatrix<int> m(size);

	m[0] = v;

	EXPECT_EQ(v, m[0]);
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
{/*
	const int size = 3;
	TDynamicMatrix<int> m(size);

	EXPECT_EQ(m = m, m); // тест верный
	*/
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{ /*
	const int size = 3;
	TDynamicMatrix<int> m(size);

	ASSERT_EQ(m == m, 1);
	*/
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{/*
	const int size = 3; тест правильный
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(size + 2);

	ASSERT_EQ(m1 == m2, 0);
	*/
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	const int size = 3;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(size + 1);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{ /*
	const int size = 3;
	TDynamicVector<int> v1, v2, v3;
	v1[0] = 1; v1[1] = 2; v2[2] = 3;
	v2[0] = 1; v2[1] = 2; v2[2] = 3;
	v3[0] = 1; v3[1] = 2; v3[2] = 3;

	TDynamicMatrix<int> m1(size);
	m1[0] = v1; m1[1] = v2; m1[2] = v3;

	TDynamicMatrix<int> m2(size);
	m1[0] = v1 * 2; m1[1] = v2 * 2; m1[2] = v3 * 2;

	ASSERT_EQ(m2 - m1, m1);
	*/
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const int size = 3;
	TDynamicMatrix<int> m1(size);
	TDynamicMatrix<int> m2(size + 2);

	ASSERT_ANY_THROW(m1 - m2);
}

