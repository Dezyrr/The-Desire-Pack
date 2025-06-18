#ifndef _VECTOR_H
#define _VECTOR_H

#ifndef M_PI
#define M_PI		3.14159265358979323846264338327950	// matches value in gcc v2 math.h
#endif

#define Vector2Clear(a) ((a)[0]=(a)[1]=0)
#define Vector3Clear(a) ((a)[0]=(a)[1]=(a)[2]=0)
#define Vector4Clear(a) ((a)[0]=(a)[1]=(a)[2]=(a)[3]=0)

typedef float vec_t;

struct vec2_t
{
	float x, y;

	vec2_t();
	~vec2_t();
	vec2_t(float x, float y);
	vec2_t(float vec[2]);

	bool operator==(vec2_t& coords);
	bool operator!=(vec2_t& coords);
	bool operator>=(vec2_t& coords);
	bool operator<=(vec2_t& coords);

	const vec2_t operator-();
	const vec2_t operator-(vec2_t const& coords);
	const vec2_t operator+(vec2_t const& coords);
	const vec2_t operator*(vec2_t const& coords);
	const vec2_t operator/(vec2_t const& coords);

	const vec2_t operator-(float const* vec);
	const vec2_t operator+(float const* vec);
	const vec2_t operator*(float const* vec);
	const vec2_t operator/(float const* vec);

	const vec2_t operator-=(vec2_t const& coords);
	const vec2_t operator+=(vec2_t const& coords);
	const vec2_t operator*=(vec2_t const& coords);
	const vec2_t operator/=(vec2_t const& coords);

	const vec2_t operator-=(float const* vec);
	const vec2_t operator+=(float const* vec);
	const vec2_t operator*=(float const* vec);
	const vec2_t operator/=(float const* vec);

	operator float* ();

	const float Length(void);
	const vec2_t normalize(void);
	const float GetDistance(vec2_t coords);
	const float DotProduct(vec2_t coords);
};

struct vec3_t
{
	float x, y, z;

	vec3_t();
	~vec3_t();
	vec3_t(float x, float y);
	vec3_t(float x, float y, float z);
	vec3_t(float vec[3]);

	bool operator==(vec3_t& coords);
	bool operator!=(vec3_t& coords);
	bool operator>=(vec3_t& coords);
	bool operator<=(vec3_t& coords);

	bool operator==(float* coords);
	bool operator!=(float* coords);
	bool operator>=(float* coords);
	bool operator<=(float* coords);

	const vec3_t operator-();

	const vec3_t operator-(vec3_t const& coords);
	const vec3_t operator+(vec3_t const& coords);
	const vec3_t operator*(vec3_t const& coords);
	const vec3_t operator/(vec3_t const& coords);

	const vec3_t operator-(float const* coords);
	const vec3_t operator+(float const* coords);
	const vec3_t operator*(float const* coords);
	const vec3_t operator/(float const* coords);

	const vec3_t operator-=(vec3_t const& coords);
	const vec3_t operator+=(vec3_t const& coords);
	const vec3_t operator*=(vec3_t const& coords);
	const vec3_t operator/=(vec3_t const& coords);

	const vec3_t operator-=(float const* coords);
	const vec3_t operator+=(float const* coords);
	const vec3_t operator*=(float const* coords);
	const vec3_t operator/=(float const* coords);

	operator float* ();

	const float Length(void);
	const vec3_t normalize(void);
	const float GetDistance(vec3_t coords);
	const float DotProduct(vec3_t coords);
	const vec3_t Radian();
};


struct vec4_t
{
	float x, y, z, w;

	vec4_t();
	~vec4_t();
	vec4_t(float x, float y, float z, float w);
	vec4_t(float vec[4]);

	operator float* ();
};

vec3_t AnglesToForward(vec3_t origin, vec3_t Angles, float distance);
float AngleNormalize360(float angle);
vec3_t VectorToAngles(vec3_t& Delta);

#endif
