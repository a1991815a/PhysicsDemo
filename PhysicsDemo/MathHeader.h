#ifndef __MATHHEADER__
#define __MATHHEADER__
#include <math.h>

#define NS_MATH_START namespace math{
#define NS_MATH_END }

NS_MATH_START
struct Mathf {
public:
	static const float vDeg2Rad;
	static const float vRad2Deg;
	static const float PI;

public:
	static float Deg2Rad(float degree);
	static float Rad2Deg(float radian);

	static float Abs(float val);
	static float Pow(float val, float p);
	static float Max(float _left, float _right);
	static float Min(float _left, float _right);
	static float Ceil(float val);
	static float Floor(float val);
	static float Clamp(float val, float MinVal, float MaxVal);
	static float Saturate(float val);

	static float Cos(float val);
	static float Sin(float val);
	static float Tan(float val);
	static float Acos(float val);
	static float Asin(float val);
	static float Atan(float val);
	static float Log(float val, float p);
	static float Log10(float val);

	static float Sign(float val);
	static float Sqrt(float val);

	static float Lerp(float MinVal, float MaxVal, float t);
	static float LerpAngle(float MinAngle, float MaxAngle, float t);
	static float LerpUnclamped(float MinVal, float MaxVal, float t);
};

NS_MATH_END;

#endif