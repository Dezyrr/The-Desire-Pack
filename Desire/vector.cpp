#include "includes.h"
#include "vector.h"

vec2_t::vec2_t()
{
    x = 0.f;
    y = 0.f;
}

vec2_t::~vec2_t()
{
}

vec2_t::vec2_t(float x, float y)
{
    this->x = x;
    this->y = y;
}

vec2_t::vec2_t(float vec[2])
{
    if (vec != 0)
    {
        this->x = vec[0];
        this->y = vec[1];
    }
    else
    {
        this->x = this->y = 0;
    }
}

bool vec2_t::operator==(vec2_t& coords)
{
    return (this->x == coords.x && this->y == coords.y);
}

bool vec2_t::operator!=(vec2_t& coords)
{
    return !(this->x == coords.x && this->y == coords.y);
}

bool vec2_t::operator>=(vec2_t& coords)
{
    return (this->x >= coords.x && this->y >= coords.y);
}

bool vec2_t::operator<=(vec2_t& coords)
{
    return (this->x <= coords.x && this->y <= coords.y);
}

const vec2_t vec2_t::operator-()
{
    return vec2_t(-x, -y);
}

const vec2_t vec2_t::operator-(vec2_t const& coords)
{
    return vec2_t(this->x - coords.x, this->y - coords.y);
}

const vec2_t vec2_t::operator+(vec2_t const& coords)
{
    return vec2_t(this->x + coords.x, this->y + coords.y);
}

const vec2_t vec2_t::operator*(vec2_t const& coords)
{
    return vec2_t(this->x * coords.x, this->y * coords.y);
}

const vec2_t vec2_t::operator/(vec2_t const& coords)
{
    return vec2_t(this->x / coords.x, this->y / coords.y);
}

const vec2_t vec2_t::operator-(float const* vec)
{
    return vec2_t(this->x - vec[0], this->y - vec[1]);
}

const vec2_t vec2_t::operator+(float const* vec)
{
    return vec2_t(this->x + vec[0], this->y + vec[1]);
}

const vec2_t vec2_t::operator*(float const* vec)
{
    return vec2_t(this->x * vec[0], this->y * vec[1]);
}

const vec2_t vec2_t::operator/(float const* vec)
{
    return vec2_t(this->x / vec[0], this->y / vec[1]);
}

const vec2_t vec2_t::operator-=(vec2_t const& coords)
{
    return vec2_t(this->x -= coords.x, this->y -= coords.y);
}

const vec2_t vec2_t::operator+=(vec2_t const& coords)
{
    return vec2_t(this->x += coords.x, this->y += coords.y);
}

const vec2_t vec2_t::operator*=(vec2_t const& coords)
{
    return vec2_t(this->x *= coords.x, this->y *= coords.y);
}

const vec2_t vec2_t::operator/=(vec2_t const& coords)
{
    return vec2_t(this->x /= coords.x, this->y /= coords.y);
}

const vec2_t vec2_t::operator-=(float const* vec)
{
    return vec2_t(this->x -= vec[0], this->y -= vec[1]);
}

const vec2_t vec2_t::operator+=(float const* vec)
{
    return vec2_t(this->x += vec[0], this->y += vec[1]);

}

const vec2_t vec2_t::operator*=(float const* vec)
{
    return vec2_t(this->x *= vec[0], this->y *= vec[1]);

}

const vec2_t vec2_t::operator/=(float const* vec)
{
    return vec2_t(this->x /= vec[0], this->y /= vec[1]);

}

vec2_t::operator float* ()
{
    return (float*)&this[0];
}

const float vec2_t::Length(void)
{
    return sqrt(x * x + y * y);
}

const vec2_t vec2_t::normalize(void)
{
    float Len = Length();

    if (!Len)
        return vec2_t(0, 0);
    Len = 1 / Len;
    return vec2_t(x * Len, y * Len);
}

const float vec2_t::GetDistance(vec2_t coords)
{
    float x = this->x - coords.x;
    float y = this->y - coords.y;
    return sqrt((x * x) + (y * y)) * 0.03048f;
}

const float vec2_t::DotProduct(vec2_t coords)
{
    return (this->x * coords.x) + (this->y * coords.y);
}

vec3_t::vec3_t()
{
    this->x = this->y = this->z = 0;
}

vec3_t::~vec3_t()
{
}

vec3_t::vec3_t(float x, float y)
{
    this->x = x;
    this->y = y;
}

vec3_t::vec3_t(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vec3_t::vec3_t(float vec[3])
{
    if (vec != 0)
    {
        this->x = vec[0];
        this->y = vec[1];
        this->z = vec[2];
    }
    else
    {
        this->x = this->y = this->z = 0;
    }
}

bool vec3_t::operator==(vec3_t& coords)
{
    return (this->x >= coords.x && this->y >= coords.y && this->z >= coords.z);
}

bool vec3_t::operator!=(vec3_t& coords)
{
    return !(this->x == coords.x && this->y == coords.y && this->z == coords.z);
}

bool vec3_t::operator>=(vec3_t& coords)
{
    return (this->x >= coords.x && this->y >= coords.y && this->z >= coords.z);
}

bool vec3_t::operator<=(vec3_t& coords)
{
    return (this->x <= coords.x && this->y <= coords.y && this->z <= coords.z);
}

bool vec3_t::operator==(float* coords)
{
    return (this->x == coords[0] && this->y == coords[1] && this->z == coords[2]);
}

bool vec3_t::operator!=(float* coords)
{
    return !(this->x == coords[0] && this->y == coords[1] && this->z == coords[2]);
}

bool vec3_t::operator>=(float* coords)
{
    return (this->x >= coords[0] && this->y >= coords[1] && this->z >= coords[2]);
}

bool vec3_t::operator<=(float* coords)
{
    return (this->x <= coords[0] && this->y <= coords[1] && this->z <= coords[2]);
}

const vec3_t vec3_t::operator-()
{
    return vec3_t(-this->x, -this->y, -this->z);
}

const vec3_t vec3_t::operator-(vec3_t const& coords)
{
    return vec3_t(this->x - coords.x, this->y - coords.y, this->z - coords.z);
}

const vec3_t vec3_t::operator+(vec3_t const& coords)
{
    return vec3_t(this->x + coords.x, this->y + coords.y, this->z + coords.z);
}

const vec3_t vec3_t::operator*(vec3_t const& coords)
{
    return vec3_t(this->x * coords.x, this->y * coords.y, this->z * coords.z);
}

const vec3_t vec3_t::operator/(vec3_t const& coords)
{
    return vec3_t(this->x / coords.x, this->y / coords.y, this->z / coords.z);
}

const vec3_t vec3_t::operator-(float const* coords)
{
    return vec3_t(this->x - coords[0], this->y - coords[1], this->z - coords[2]);
}

const vec3_t vec3_t::operator+(float const* coords)
{
    return vec3_t(this->x + coords[0], this->y + coords[1], this->z + coords[2]);
}

const vec3_t vec3_t::operator*(float const* coords)
{
    return vec3_t(this->x * coords[0], this->y * coords[1], this->z * coords[2]);
}

const vec3_t vec3_t::operator/(float const* coords)
{
    return vec3_t(this->x / coords[0], this->y / coords[1], this->z / coords[2]);
}

const vec3_t vec3_t::operator-=(vec3_t const& coords)
{
    return vec3_t(this->x -= coords.x, this->y -= coords.y, this->z -= coords.z);
}

const vec3_t vec3_t::operator+=(vec3_t const& coords)
{
    return vec3_t(this->x += coords.x, this->y += coords.y, this->z += coords.z);
}

const vec3_t vec3_t::operator*=(vec3_t const& coords)
{
    return vec3_t(this->x *= coords.x, this->y *= coords.y, this->z *= coords.z);
}

const vec3_t vec3_t::operator/=(vec3_t const& coords)
{
    return vec3_t(this->x /= coords.x, this->y /= coords.y, this->z /= coords.z);
}

const vec3_t vec3_t::operator-=(float const* coords)
{
    return vec3_t(this->x -= coords[0], this->y -= coords[1], this->z -= coords[2]);
}

const vec3_t vec3_t::operator+=(float const* coords)
{
    return vec3_t(this->x += coords[0], this->y += coords[1], this->z += coords[2]);
}

const vec3_t vec3_t::operator*=(float const* coords)
{
    return vec3_t(this->x *= coords[0], this->y *= coords[1], this->z *= coords[2]);
}

const vec3_t vec3_t::operator/=(float const* coords)
{
    return vec3_t(this->x /= coords[0], this->y /= coords[1], this->z /= coords[2]);
}

vec3_t::operator float* ()
{
    return (float*)&this[0];
}

const float vec3_t::Length(void)
{
    return (float)sqrt(x * x + y * y + z * z);
}

const vec3_t vec3_t::normalize(void)
{
    vec3_t newvec;
    newvec.x = this->x / Length();
    newvec.y = this->y / Length();
    newvec.z = this->z / Length();
    return newvec;
}

const float vec3_t::GetDistance(vec3_t coords)
{
    float x = this->x - coords.x;
    float y = this->y - coords.y;
    float z = this->z - coords.z;
    return sqrt((x * x) + (y * y) + (z * z)) * 0.03048f;
}

const float vec3_t::DotProduct(vec3_t coords)
{
    return (this->x * coords.x) + (this->y * coords.y) + (this->z * coords.z);
}

const vec3_t vec3_t::Radian()
{
    return vec3_t(this->z * (M_PI / 180.f), this->x * (M_PI / 180.f), this->y * (M_PI / 180.f));
}

vec3_t AnglesToForward(vec3_t origin, vec3_t Angles, float distance)
{
    float angle, sr, sp, sy, cr, cp, cy, PiDiv;
    PiDiv = ((float)M_PI / 180);
    angle = Angles[1] * PiDiv;
    sy = (float)sinf(angle);
    cy = (float)cosf(angle);
    angle = Angles[0] * PiDiv;
    sp = sinf(angle);
    cp = (float)cosf(angle);
    angle = Angles[1] * PiDiv;
    sr = (float)sinf(angle);
    cr = (float)cosf(angle);
    float Final[3] = { (cp * cy * distance) + origin[0], (cp * sy * distance) + origin[1], (-sp * distance) + origin[2] };
    return Final;
}

vec4_t::vec4_t()
{
    this->x = this->y = this->z = this->w = 0;
}

vec4_t::~vec4_t()
{
}

vec4_t::vec4_t(float x, float y, float z, float w)
{
    this->x = (x > 1.0f) ? x / 255.f : x;
    this->y = (y > 1.0f) ? y / 255.f : y;
    this->z = (z > 1.0f) ? z / 255.f : z;
    this->w = (w > 1.0f) ? w / 255.f : w;
}

vec4_t::vec4_t(float vec[4])
{
    this->x = vec[0];
    this->y = vec[1];
    this->z = vec[2];
    this->w = vec[3];
}

vec4_t::operator float* ()
{
    return (float*)&this[0];
}

float AngleNormalize360(float angle) {
    return (360.0 / 65536) * ((int)(angle * (65536 / 360.0)) & 65535);
}

vec3_t VectorToAngles(vec3_t& Delta)
{
    float Forward, Yaw, Pitch;

    if (Delta.x == 0 && Delta.y == 0)
    {
        Yaw = 0;
        if (Delta.z > 0)
            Pitch = 90.0f;
        else
            Pitch = 270.0f;
    }
    else
    {
        if (Delta.x)
            Yaw = (atan2(Delta.y, Delta.x) * 57.2957804f);
        else if (Delta.y > 0)
            Yaw = 90.0f;
        else
            Yaw = 270.0f;

        if (Yaw < 0)
            Yaw += 360.0f;

        Forward = sqrt((Delta.x * Delta.x) + (Delta.y * Delta.y));
        Pitch = (atan2(Delta.z, Forward) * 57.2957804f);

        if (Pitch < 0)
            Pitch += 360;
    }
    return vec3_t(-Pitch, Yaw, 0);
}
