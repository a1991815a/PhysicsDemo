#ifndef __VEC__
#define __VEC__
#include "MathHeader.h"
NS_MATH_START;

struct Mat;

struct Vec2 
{
	float x, y;

	//Ԥ��������
	static Vec2 one;
	static Vec2 zero;
	static Vec2 up;
	static Vec2 down;
	static Vec2 left;
	static Vec2 right;


	Vec2();
	Vec2(const Vec2& vec);
	Vec2(float x, float y);

	bool operator==(const Vec2& vec) const;
	bool operator!=(const Vec2& vec) const;

	const Vec2& operator+=(const Vec2& vec2);
	const Vec2& operator-=(const Vec2& vec2);
	const Vec2& operator*=(const Vec2& vec2);
	const Vec2& operator/=(const Vec2& vec2);

	Vec2 operator+(const Vec2& vec2) const;
	Vec2 operator-(const Vec2& vec2) const;
	Vec2 operator*(const Vec2& vec2) const;
	Vec2 operator/(const Vec2& vec2) const;

	const Vec2& operator*=(float scale);
	Vec2 operator*(float scale) const;
	const Vec2& operator/=(float scale);
	Vec2 operator/(float scale) const;

	//�淶��
	const Vec2& normalize();
	//ģ
	float magnitude() const;
	//ƽ��ģ
	float squareMagnitude() const;

	const Vec2& TransformPoint(const Mat& mat);
	const Vec2& TransformDirection(const Mat& mat);
	//��̬����
public:
	//���
	static float Dot(const Vec2& _left, const Vec2& _right);
	//���
	static float Cross(const Vec2& _left, const Vec2& _right);
	//���ؽǶ�
	static float Angle(const Vec2& _left, const Vec2& _right);
	//2�����
	static float Distance(const Vec2& _left, const Vec2& _right);
	//ͶӰ
	static Vec2 Project(const Vec2& _left, const Vec2& _right);
	//����
	static Vec2 Reflect(const Vec2& vec, const Vec2& normal);
	//��ֵ
	static Vec2 Lerp(const Vec2& _left, const Vec2& _right, float t);
	//��ֵ���涨��Χ
	static Vec2 LerpUnclamped(const Vec2& _left, const Vec2& _right, float t);
};

struct Vec3 {
	float x, y, z;

//Ԥ��������
	static Vec3 one;
	static Vec3 zero;
	static Vec3 up;
	static Vec3 down;
	static Vec3 left;
	static Vec3 right;
	static Vec3 forward;
	static Vec3 back;


	Vec3();
	Vec3(const Vec3& vec);
	Vec3(float x, float y, float z);
	
	bool operator==(const Vec3& vec) const;
	bool operator!=(const Vec3& vec) const;

	const Vec3& operator+=(const Vec3& vec3);
	const Vec3& operator-=(const Vec3& vec3);
	const Vec3& operator*=(const Vec3& vec3);
	const Vec3& operator/=(const Vec3& vec3);

	Vec3 operator+(const Vec3& vec3) const;
	Vec3 operator-(const Vec3& vec3) const;
	Vec3 operator*(const Vec3& vec3) const;
	Vec3 operator/(const Vec3& vec3) const;

	const Vec3& operator*=(float scale);
	Vec3 operator*(float scale) const;
	const Vec3& operator/=(float scale);
	Vec3 operator/(float scale) const;

	//�淶��
	const Vec3& normalize();
	//ģ
	float magnitude() const;
	//ƽ��ģ
	float squareMagnitude() const;

	const Vec3& TransformPoint(const Mat& mat);
	const Vec3& TransformDirection(const Mat& mat);
//��̬����
public:
	//���
	static float Dot(const Vec3& _left, const Vec3& _right);
	//���
	static Vec3 Cross(const Vec3& _left, const Vec3& _right);
	//���ؽǶ�
	static float Angle(const Vec3& _left, const Vec3& _right);
	//2�����
	static float Distance(const Vec3& _left, const Vec3& _right);
	//ͶӰ
	static Vec3 Project(const Vec3& _left, const Vec3& _right);
	//����
	static Vec3 Reflect(const Vec3& vec, const Vec3& normal);
	//��ֵ
	static Vec3 Lerp(const Vec3& _left, const Vec3& _right, float t);
	//��ֵ���涨��Χ
	static Vec3 LerpUnclamped(const Vec3& _left, const Vec3& _right, float t);
};

// struct Vec4 {
// 	float x, y, z, w;
// 
// //Ԥ��������
// 	static Vec4 one;
// 	static Vec4 zero;
// 	static Vec4 up;
// 	static Vec4 down;
// 	static Vec4 left;
// 	static Vec4 right;
// 	static Vec4 forward;
// 	static Vec4 back;
// 
// 
// 	Vec4();
// 	Vec4(const Vec4& vec);
// 	Vec4(float x, float y, float z);
// 
// 	bool operator==(const Vec4& vec) const;
// 	bool operator!=(const Vec4& vec) const;
// 
// 	const Vec4& operator+=(const Vec4& Vec4);
// 	const Vec4& operator-=(const Vec4& Vec4);
// 	const Vec4& operator*=(const Vec4& Vec4);
// 	const Vec4& operator/=(const Vec4& Vec4);
// 
// 	Vec4 operator+(const Vec4& Vec4) const;
// 	Vec4 operator-(const Vec4& Vec4) const;
// 	Vec4 operator*(const Vec4& Vec4) const;
// 	Vec4 operator/(const Vec4& Vec4) const;
// 
// 	const Vec4& operator*=(float scale);
// 	Vec4 operator*(float scale) const;
// 	const Vec4& operator/=(float scale);
// 	Vec4 operator/(float scale) const;
// 
// 	//�淶��
// 	const Vec4& normalize();
// 	//ģ
// 	float magnitude() const;
// 	//ƽ��ģ
// 	float squareMagnitude() const;
// 
// //��̬����
// public:
// 	//���
// 	static float Dot(const Vec4& _left, const Vec4& _right);
// 	//���
// 	static Vec4 Cross(const Vec4& _left, const Vec4& _right);
// 	//���ؽǶ�
// 	static float Angle(const Vec4& _left, const Vec4& _right);
// 	//2�����
// 	static float Distance(const Vec4& _left, const Vec4& _right);
// 	//ͶӰ
// 	static Vec4 Project(const Vec4& _left, const Vec4& _right);
// 	//����
// 	static Vec4 Reflect(const Vec4& _left, const Vec4& _right);
// 	//��ֵ
// 	static Vec4 Lerp(const Vec4& _left, const Vec4& _right, float t);
// 	//��ֵ���涨��Χ
// 	static Vec4 LerpUnclamped(const Vec4& _left, const Vec4& _right, float t);
// };

NS_MATH_END;
#endif