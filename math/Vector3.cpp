#include "Vector3.h"
#include <cmath>

// コンストラクタ
Vector3::Vector3(float vx, float vy, float vz) : x(vx), y(vy), z(vz) {}

// 値を設定
void Vector3::Set(float vx, float vy, float vz) {
	this->x = vx;
	this->y = vy;
	this->z = vz;
}

// 加算
Vector3 Vector3::operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }

// 減算
Vector3 Vector3::operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }

// スカラー倍
Vector3 Vector3::operator*(float f) const { return Vector3(x * f, y * f, z * f); }

// スカラー除算
Vector3 Vector3::operator/(float f) const { return Vector3(x / f, y / f, z / f); }

// 符号反転
Vector3 Vector3::operator-() const { return Vector3(-x, -y, -z); }

// 加算代入
void Vector3::operator+=(const Vector3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
}

// 減算代入
void Vector3::operator-=(const Vector3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

// スカラー倍代入
void Vector3::operator*=(float f) {
	x *= f;
	y *= f;
	z *= f;
}

// スカラー除算代入
void Vector3::operator/=(float f) {
	x /= f;
	y /= f;
	z /= f;
}

// ベクトルの大きさの2乗を返す
float Vector3::SqMag() const { return x * x + y * y + z * z; }

// 大きさの2乗（`SqMag()` と同じ機能）
float Vector3::MagSq() const { return SqMag(); }

// ベクトルの大きさを返す
float Vector3::Mag() const { return std::sqrt(SqMag()); }

// ベクトルの大きさを設定
Vector3 Vector3::SetMag(float mag) { return Normalize() * mag; }

// ベクトルの大きさを制限
Vector3 Vector3::Limmit(float maxMag) {
	if (Mag() > maxMag) {
		return SetMag(maxMag);
	}
	return *this;
}

// 正規化したベクトルを返す
Vector3 Vector3::Normalize() {
	float magnitude = Mag();
	if (magnitude == 0)
		return Vector3(0, 0, 0);
	return *this / magnitude;
}

// 内積を計算
float Vector3::Dot(const Vector3& v) const { return x * v.x + y * v.y + z * v.z; }

// 外積を計算
Vector3 Vector3::Cross(const Vector3& v) const { return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }

// 2DベクトルのZ成分の外積
float Vector3::CrossXY(const Vector3& v) const { return x * v.y - y * v.x; }

// 2DベクトルのY成分の外積
float Vector3::CrossXZ(const Vector3& v) const { return x * v.z - z * v.x; }

// スカラーとベクトルの掛け算
Vector3 operator*(float f, const Vector3& v) { return Vector3(v.x * f, v.y * f, v.z * f); }

// ベクトルの正規化
//Vector3 Normalize(const Vector3& a) { return a.Normalize(); }

// ベクトルの内積
float Dot(const Vector3& a, const Vector3& b) { return a.Dot(b); }

// ベクトルの外積
Vector3 Cross(const Vector3& a, const Vector3& b) { return a.Cross(b); }

// 2DベクトルのZ成分の外積
float CrossXY(const Vector3& a, const Vector3& b) { return a.CrossXY(b); }

// 2DベクトルのY成分の外積
float CrossXZ(const Vector3& a, const Vector3& b) { return a.CrossXZ(b); }
