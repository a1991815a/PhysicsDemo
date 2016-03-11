#include "MathHeader.h"
NS_MATH_START;

const float Mathf::vDeg2Rad = PI / 180.0f;
const float Mathf::vRad2Deg = 180.0f / PI;

const float Mathf::PI = 3.141592654f;

float Mathf::LerpUnclamped(float MinVal, float MaxVal, float t)
{
	float val = MinVal + t * (MaxVal - MinVal);
	return val;
}

float Mathf::LerpAngle(float MinAngle, float MaxAngle, float t)
{
	float angle = MinAngle + t * (MaxAngle - MinAngle);
	angle = ((int)angle) % 360 + angle - (int)angle;
	return angle;
}

float Mathf::Lerp(float MinVal, float MaxVal, float t)
{
	t = Saturate(t);
	float val = MinVal + t * (MaxVal - MinVal);
	return val;
}

float Mathf::Sqrt(float val)
{
	return ::sqrtf(val);
}

float Mathf::Sign(float val)
{
	if (val > 0)
		return 1.0f;
	else if (val < 0)
		return -1.0f;

	return 0.0f;
}

float Mathf::Log10(float val)
{
	return ::log10f(val);
}

float Mathf::Log(float val, float p)
{
	return ::logf(val) / ::logf(p);
}

float Mathf::Atan(float val)
{
	return ::atanf(val);
}

float Mathf::Asin(float val)
{
	return ::asinf(val);
}

float Mathf::Acos(float val)
{
	return ::acosf(val);
}

float Mathf::Tan(float val)
{
	return ::tanf(val);
}

float Mathf::Sin(float val)
{
	return ::sinf(val);
}

float Mathf::Cos(float val)
{
	return ::cosf(val);
}

float Mathf::Saturate(float val)
{
	if (val < 0)
		return 0;
	else if (val > 1)
		return 1;
	return val;
}

float Mathf::Clamp(float val, float MinVal, float MaxVal)
{
	if (val < MinVal)
		return MinVal;
	else if (val > MaxVal)
		return MaxVal;
	return val;
}

float Mathf::Floor(float val)
{
	return ::floorf(val);
}

float Mathf::Ceil(float val)
{
	return ::ceilf(val);
}

float Mathf::Min(float _left, float _right)
{
	return ::fminf(_left, _right);
}

float Mathf::Max(float _left, float _right)
{
	return ::fmaxf(_left, _right);
}

float Mathf::Pow(float val, float p)
{
	return ::powf(val, p);
}

float Mathf::Abs(float val)
{
	return ::fabsf(val);
}

float Mathf::Rad2Deg(float radian)
{
	return radian * vRad2Deg;
}

float Mathf::Deg2Rad(float degree)
{
	return degree * vDeg2Rad;
}


NS_MATH_END;

