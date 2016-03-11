#include "Mat.h"
NS_MATH_START;
const Mat Mat::identity = Mat(
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
	);

Mat::Mat()
	:Mat(identity)
{}

Mat::Mat(
	float _11, float _12, float _13, float _14, 
	float _21, float _22, float _23, float _24, 
	float _31, float _32, float _33, float _34, 
	float _41, float _42, float _43, float _44)
	:
	_11(_11), _12(_12), _13(_13), _14(_14),
	_21(_21), _22(_22), _23(_23), _24(_24),
	_31(_31), _32(_32), _33(_33), _34(_34),
	_41(_41), _42(_42), _43(_43), _44(_44)
{

}


NS_MATH_END;