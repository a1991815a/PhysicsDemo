#include "Vec.h"
#include "Mat.h"
NS_MATH_START;

Vec2 Vec2::one = Vec2(1, 1);
Vec2 Vec2::zero = Vec2(0, 0);
Vec2 Vec2::right = Vec2(1, 0);
Vec2 Vec2::left = Vec2(-1, 0);
Vec2 Vec2::down = Vec2(0, -1);
Vec2 Vec2::up = Vec2(0, 1);


Vec2 Vec2::LerpUnclamped(const Vec2& _left, const Vec2& _right, float t)
{
	Vec2 v(
		Mathf::LerpUnclamped(_left.x, _right.x, t),
		Mathf::LerpUnclamped(_left.y, _right.y, t)
		);
	return v;
}

Vec2 Vec2::Lerp(const Vec2& _left, const Vec2& _right, float t)
{
	Vec2 v(
		Mathf::Lerp(_left.x, _right.x, t),
		Mathf::Lerp(_left.y, _right.y, t)
		);
	return v;
}

Vec2 Vec2::Reflect(const Vec2& vec, const Vec2& normal)
{
	return vec - normal * 2 * Vec2::Dot(vec, normal);
}

Vec2 Vec2::Project(const Vec2& _left, const Vec2& _right)
{
	Vec2 rightNormal = _right;
	rightNormal.normalize();
	return _left - rightNormal * Vec2::Dot(_left, rightNormal);
}

float Vec2::Distance(const Vec2& _left, const Vec2& _right)
{
	Vec2 v = _right - _left;
	return v.magnitude();
}

float Vec2::Angle(const Vec2& _left, const Vec2& _right)
{
	Vec2 left = _left;
	Vec2 right = _right;
	left.normalize();
	right.normalize();
	return Mathf::Acos(Vec2::Dot(left, right));
}

float Vec2::Cross(const Vec2& _left, const Vec2& _right)
{
	return _left.x * _right.y - _right.x * _left.y;
}

float Vec2::Dot(const Vec2& _left, const Vec2& _right)
{
	return _left.x * _right.x + _left.y * _right.y;
}

float Vec2::squareMagnitude() const
{
	return x * x + y * y;
}

const Vec2& Vec2::TransformDirection(const Mat& mat)
{
	x = x * mat._11 + y * mat._21;
	y = x * mat._12 + y * mat._22;
	float w = x * mat._14 + y * mat._24;
	*this /= w;
}

const Vec2& Vec2::TransformPoint(const Mat& mat)
{
	x = x * mat._11 + y * mat._21 + mat._41;
	y = x * mat._12 + y * mat._22 + mat._42;
	float w = x * mat._14 + y * mat._24 + mat._44;
	*this /= w;
}

float Vec2::magnitude() const
{
	return Mathf::Sqrt(x * x + y * y);
}

const Vec2& Vec2::normalize()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	return *this;
}

Vec2 Vec2::operator*(float scale) const
{
	Vec2 v = *this;
	v *= scale;
	return v;
}

const Vec2& Vec2::operator*=(float scale)
{
	x *= scale;
	y *= scale;
	return *this;
}



Vec2 Vec2::operator/(const Vec2& vec2) const
{
	Vec2 v = *this;
	v /= vec2;
	return v;
}

Vec2 Vec2::operator/(float scale) const
{
	Vec2 v = *this;
	v /= scale;
	return v;
}

const Vec2& Vec2::operator/=(float scale)
{
	x /= scale;
	y /= scale;
	return *this;
}

Vec2 Vec2::operator*(const Vec2& vec2) const
{
	Vec2 v = *this;
	v *= vec2;
	return v;
}

Vec2 Vec2::operator-(const Vec2& vec2) const
{
	Vec2 v = *this;
	v -= vec2;
	return v;
}

Vec2 Vec2::operator+(const Vec2& vec2) const
{
	Vec2 v = *this;
	v += vec2;
	return v;
}

const Vec2& Vec2::operator/=(const Vec2& vec2)
{
	x /= vec2.x;
	y /= vec2.y;
	return *this;
}

const Vec2& Vec2::operator*=(const Vec2& vec2)
{
	x *= vec2.x;
	y *= vec2.y;
	return *this;
}

const Vec2& Vec2::operator-=(const Vec2& vec2)
{
	x -= vec2.x;
	y -= vec2.y;
	return *this;
}

const Vec2& Vec2::operator+=(const Vec2& vec2)
{
	x += vec2.x;
	y += vec2.y;
	return *this;
}

bool Vec2::operator!=(const Vec2& vec) const
{
	return !(*this == vec);
}

bool Vec2::operator==(const Vec2& vec) const
{
	return x == vec.x && y == vec.y;
}

Vec2::Vec2(float x, float y)
	:x(x), y(y)
{

}

Vec2::Vec2(const Vec2& vec)
	:x(vec.x), y(vec.y)
{

}

Vec2::Vec2()
	: x(0), y(0)
{

}




//Vec3******************************
Vec3 Vec3::one = Vec3(1, 1, 1);
Vec3 Vec3::zero = Vec3(0, 0, 0);
Vec3 Vec3::forward = Vec3(0, 0, 1);
Vec3 Vec3::back = Vec3(0, 0, -1);
Vec3 Vec3::right = Vec3(1, 0, 0);
Vec3 Vec3::left = Vec3(-1, 0, 0);
Vec3 Vec3::up = Vec3(0, 1, 0);
Vec3 Vec3::down = Vec3(0, -1, 0);

Vec3 Vec3::LerpUnclamped(const Vec3& _left, const Vec3& _right, float t)
{
	Vec3 v(
		Mathf::LerpUnclamped(_left.x, _right.x, t),
		Mathf::LerpUnclamped(_left.y, _right.y, t),
		Mathf::LerpUnclamped(_left.z, _right.z, t)
		);
	return v;
}

Vec3 Vec3::Lerp(const Vec3& _left, const Vec3& _right, float t)
{
	Vec3 v(
		Mathf::Lerp(_left.x, _right.x, t),
		Mathf::Lerp(_left.y, _right.y, t),
		Mathf::Lerp(_left.z, _right.z, t)
		);
	return v;
}

Vec3 Vec3::Reflect(const Vec3& vec, const Vec3& normal)
{
	return vec - normal * 2 * Vec3::Dot(vec, normal);
}

Vec3 Vec3::Project(const Vec3& _left, const Vec3& _right)
{
	Vec3 rightNormal = _right;
	rightNormal.normalize();
	return _left - rightNormal * Vec3::Dot(_left, rightNormal);
}

float Vec3::Distance(const Vec3& _left, const Vec3& _right)
{
	Vec3 v = _right - _left;
	return v.magnitude();
}

float Vec3::Angle(const Vec3& _left, const Vec3& _right)
{
	Vec3 left = _left;
	Vec3 right = _right;
	return Mathf::Acos(Vec3::Dot(left.normalize(), right.normalize()));
}

Vec3 Vec3::Cross(const Vec3& _left, const Vec3& _right)
{
	return Vec3(
		_left.y * _right.z - _left.z * _right.y,
		_left.z * _right.x - _left.x * _right.z,
		_left.x * _right.y - _left.y * _right.x
		);
}

float Vec3::Dot(const Vec3& _left, const Vec3& _right)
{
	return _left.x * _right.x + _left.y * _right.y + _left.z * _right.z;
}

const Vec3& Vec3::TransformDirection(const Mat& mat)
{
	x = x * mat._11 + y * mat._21 + z * mat._31;
	y = x * mat._12 + y * mat._22 + z * mat._32;
	z = x * mat._13 + y * mat._23 + z * mat._33;
	float w = x * mat._14 + y * mat._24 + z * mat._34;
	*this /= w;

	return *this;
}

const Vec3& Vec3::TransformPoint(const Mat& mat)
{
	x = x * mat._11 + y * mat._21 + z * mat._31 + mat._41;
	y = x * mat._12 + y * mat._22 + z * mat._32 + mat._42;
	z = x * mat._13 + y * mat._23 + z * mat._33 + mat._43;
	float w = x * mat._14 + y * mat._24 + z * mat._34 + mat._44;
	*this /= w;

	return *this;
}

float Vec3::squareMagnitude() const
{
	return x * x + y * y + z * z;
}

float Vec3::magnitude() const
{
	return Mathf::Sqrt(x * x + y * y + z * z);
}

const Vec3& Vec3::normalize()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
	return *this;
}

Vec3 Vec3::operator*(float scale) const
{
	Vec3 v = *this;
	v *= scale;
	return v;
}

const Vec3& Vec3::operator*=(float scale)
{
	x *= scale;
	y *= scale;
	z *= scale;
	return *this;
}

Vec3 Vec3::operator/(float scale) const
{
	Vec3 v = *this;
	v /= scale;
	return v;
}

const Vec3& Vec3::operator/=(float scale)
{
	x /= scale;
	y /= scale;
	z /= scale;
	return *this;
}

Vec3 Vec3::operator/(const Vec3& vec3) const
{
	Vec3 v = *this;
	v /= vec3;
	return v;
}

Vec3 Vec3::operator*(const Vec3& vec3) const
{
	Vec3 v = *this;
	v *= vec3;
	return v;
}

Vec3 Vec3::operator-(const Vec3& vec3) const
{
	Vec3 v = *this;
	v -= vec3;
	return v;
}

Vec3 Vec3::operator+(const Vec3& vec3) const
{
	Vec3 v = *this;
	v += vec3;
	return v;
}

const Vec3& Vec3::operator/=(const Vec3& vec3)
{
	x /= vec3.x;
	y /= vec3.y;
	z /= vec3.z;
	return *this;
}

const Vec3& Vec3::operator*=(const Vec3& vec3)
{
	x *= vec3.x;
	y *= vec3.y;
	z *= vec3.z;
	return *this;
}

const Vec3& Vec3::operator-=(const Vec3& vec3)
{
	x -= vec3.x;
	y -= vec3.y;
	z -= vec3.z;
	return *this;
}

const Vec3& Vec3::operator+=(const Vec3& vec3)
{
	x += vec3.x;
	y += vec3.y;
	z += vec3.z;
	return *this;
}

bool Vec3::operator!=(const Vec3& vec) const
{
	return !(*this == vec);
}

bool Vec3::operator==(const Vec3& vec) const
{
	return x == vec.x && y == vec.y && z == vec.z;
}

Vec3::Vec3(float x, float y, float z)
	:x(x), y(y), z(z)
{

}

Vec3::Vec3(const Vec3& vec)
	:x(vec.x), y(vec.y), z(vec.z)
{

}

Vec3::Vec3()
	:x(0), y(0), z(0)
{

}

NS_MATH_END;

