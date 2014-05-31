#include <stdio.h>
typedef int ElementType;

struct left_chil_right_sibl{
	struct left_chil_right_sibl * par;
	struct left_chil_right_sibl * left_child;
	struct left_chil_right_sibl * right_sibling;
	ElementType data;
};



