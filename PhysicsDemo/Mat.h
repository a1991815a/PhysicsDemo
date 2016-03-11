#ifndef __MAT__
#define __MAT__
#include "MathHeader.h"
struct Vec3;

NS_MATH_START;
struct Mat {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		};
		float m[4][4];
	};

	static const Mat identity;

	Mat();
	Mat(float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34,
		float _41, float _42, float _43, float _44);

	const Mat& operator*=(const Mat* mat);
	const Mat& operator+=(const Mat* mat);
	const Mat& operator-=(const Mat* mat);
	const Mat& operator*=(float scale);
	const Mat& operator/=(float scale);

	Mat operator*(const Mat* mat) const;
	Mat operator+(const Mat* mat) const;
	Mat operator-(const Mat* mat) const;
	Mat operator*(float scale) const;
	Mat operator/(float scale) const;
	
	const Mat& Transpose();
	const Mat& Inverse();
	float Determinant();


//¾²Ì¬º¯Êý
public:
	static Mat Scale(float x, float y, float z);
	static Mat Translation(float x, float y, float z);
	static Mat RotationX(float angle);
	static Mat RotationY(float angle);
	static Mat RotationZ(float angle);
	static Mat RotationEuler(float x, float y, float z);

	static Mat LookAt(const Vec3& eye, const Vec3& pos, const Vec3& up);
	static Mat LookAt(
		float eyeX, float eyeY, float eyeZ,
		const float posX, const float posY, const float posZ,
		const float upX, const float upY, const float upZ);

	static Mat Ortho(float width, float height, float near, float far);
	static Mat Perspective(float fovy, float Aspect, float near, float far);


};

NS_MATH_END;
#endif