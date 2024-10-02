#pragma once
struct Vector3 final{
	float x, y, z;
	Vector3(float x = 0, float y = 0, float z = 0);
	void Set(float x, float y, float z = 0);
	Vector3 operator+(const Vector3& v) const;
	Vector3 operator-(const Vector3& v) const;
	Vector3 operator*(float f) const;
	Vector3 operator/(float f) const;
	Vector3 operator-() const;
	void operator+=(const Vector3& v);
	void operator-=(const Vector3& v);
	void operator*=(float f);
	void operator/=(float f);
	float SqMag() const;
	float MagSq() const; // 機能はsqMagと同じ
	float Mag() const;
	Vector3 SetMag(float mag);
	Vector3 Limmit(float maxMag);
	Vector3 Normalize();
	float Dot(const Vector3& v) const;
	Vector3 Cross(const Vector3& v) const;
	float CrossXY(const Vector3& v) const; // 外積Z成分のみ計算(２Ｄ用)
	float CrossXZ(const Vector3& v) const; // 外積Y成分のみ計算(２Ｄ用)
};

Vector3 operator*(float f, const Vector3& v); // VECTOR = float * VECTOR
//Vector3 Normalize(const Vector3& a);
float Dot(const Vector3& a, const Vector3& b);
Vector3 Cross(const Vector3& a, const Vector3& b);
float CrossXY(const Vector3& a, const Vector3& b); // 外積Z成分のみ計算(２Ｄ用)
float CrossXZ(const Vector3& a, const Vector3& b); // 外積Y成分のみ計算(２Ｄ用)
