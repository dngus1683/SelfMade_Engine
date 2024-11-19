#pragma once
#include <cmath>

namespace sme::math
{
#define PI 3.141592

	static float ConvertDegree(float radian) { return (radian * (180 / PI)); }
	struct Vector2
	{
		static Vector2 Rotate(Vector2& vector, float degree)
		{
			float rad = (degree / 180.f) * PI;
			vector.normalize();
			float x = cosf(rad) * vector.x - sinf(rad) * vector.y;
			float y = sinf(rad) * vector.x + cosf(rad) * vector.y;

			return Vector2(x, y);
		}

		static float Dot(Vector2& v1, Vector2& v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}
		static float Cross(Vector2& v1, Vector2& v2)
		{
			return v1.x * v2.y - v1.y * v2.x;
		}

		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

		float x;
		float y;

		Vector2()
			: x(0.f)
			, y(0.f)
		{
		}
		Vector2(float InX, float InY)
			: x(InX)
			, y(InY)
		{
		}

		Vector2 operator+(Vector2 other)
		{
			return Vector2(x + other.x, y + other.y);
		}
		Vector2 operator-(Vector2 other)
		{
			return Vector2(x - other.x, y - other.y);
		}
		Vector2 operator /(float value)
		{
			return Vector2(x / value, y / value);
		}
		Vector2 operator *(Vector2 other)
		{
			return Vector2(x * other.x, y * other.y);
		}
		Vector2 operator *(float value)
		{
			return Vector2(x * value, y * value);
		}
		void operator+=(Vector2 other)
		{
			x += other.x;
			y += other.y;
		}

		void clear()
		{
			x = 0.f;
			y = 0.f;
		}
		float length()
		{
			return sqrtf(x * x + y * y);
		}
		Vector2 normalize()
		{
			float len = length();
			x /= len;
			y /= len;

			return *this;
		}
	};
}