#ifndef MMATRIX_HPP
# define MMATRIX_HPP

namespace mmatrix
{
	class	Vec2;
	class	Vec3;
	class	Vec4;
	class	Mat4x4;
	class	Quat;

	class	Vec2
	{
	public:
		Vec2(void);
		Vec2(float v);
		Vec2(float x, float y);
		Vec2(const Vec2 &v);
		float		&operator[](const int i);
		const float	&operator[](const int i) const;
		Vec2 		&operator=(const Vec2 &v);
		bool 		operator==(const Vec2 &v);
		Vec2		operator+(const Vec2 &v);
		Vec2 		&operator+=(const Vec2 &v);
		Vec2		operator-(const Vec2 &v);
		Vec2 		&operator-=(const Vec2 &v);
		Vec2		operator*(const Vec2 &v);
		Vec2 		&operator*=(const Vec2 &v);
		Vec2		operator/(const Vec2 &v);
		Vec2 		&operator/=(const Vec2 &v);
		Vec2		operator+(float v);
		Vec2 		&operator+=(float v);
		Vec2		operator-(float v);
		Vec2 		&operator-=(float v);
		Vec2		operator*(float v);
		Vec2 		&operator*=(float v);
		Vec2		operator/(float v);
		Vec2 		&operator/=(float v);
		float		dot(const Vec2 &v);
		float		length(void);
		Vec2 		&normalise(void);
	private:
		float	_val[2];
	};
	class	Vec3
	{
	public:
		Vec3(void);
		Vec3(float v);
		Vec3(float x, float y, float z);
		Vec3(const Vec2 &v, float z);
		Vec3(const Vec3 &v);
		float		&operator[](const int i);
		const float	&operator[](const int i) const;
		Vec3 		&operator=(const Vec3 &v);
		bool 		operator==(const Vec3 &v);
		Vec3		operator+(const Vec3 &v);
		Vec3 		&operator+=(const Vec3 &v);
		Vec3		operator-(const Vec3 &v);
		Vec3 		&operator-=(const Vec3 &v);
		Vec3		operator*(const Vec3 &v);
		Vec3 		&operator*=(const Vec3 &v);
		Vec3		operator/(const Vec3 &v);
		Vec3 		&operator/=(const Vec3 &v);
		Vec3		operator+(float v);
		Vec3 		&operator+=(float v);
		Vec3		operator-(float v);
		Vec3 		&operator-=(float v);
		Vec3		operator*(float v);
		Vec3 		&operator*=(float v);
		Vec3		operator/(float v);
		Vec3 		&operator/=(float v);
		float		mulInner(const Vec3 &v);
		Vec3		cross(const Vec3 &v);
		float		dot(const Vec3 &v);
		float		length(void);
		Vec3 		&normalise(void);
	private:
		float	_val[3];
	};
	class	Vec4
	{
	public:
		Vec4(void);
		Vec4(float v);
		Vec4(float x, float y, float z, float w);
		Vec4(const Vec2 &v, float z, float w);
		Vec4(const Vec3 &v, float w);
		Vec4(const Vec4 &v);
		float		&operator[](const int i);
		const float	&operator[](const int i) const;
		Vec4 		&operator=(const Vec4 &v);
		bool 		operator==(const Vec4 &v);
		Vec4		operator+(const Vec4 &v);
		Vec4 		&operator+=(const Vec4 &v);
		Vec4		operator-(const Vec4 &v);
		Vec4 		&operator-=(const Vec4 &v);
		Vec4		operator*(const Vec4 &v);
		Vec4 		&operator*=(const Vec4 &v);
		Vec4		operator/(const Vec4 &v);
		Vec4 		&operator/=(const Vec4 &v);
		Vec4		operator+(float v);
		Vec4 		&operator+=(float v);
		Vec4		operator-(float v);
		Vec4 		&operator-=(float v);
		Vec4		operator*(float v);
		Vec4 		&operator*=(float v);
		Vec4		operator/(float v);
		Vec4 		&operator/=(float v);
		float		mulInner(const Vec4 &v);
		Vec4		cross(const Vec4 &v);
		float		dot(const Vec4 &v);
		float		length(void);
		Vec4 		&normalise(void);
		Vec3		&xyz(void);
	private:
		float	_val[4];
	};
	class	Mat4x4
	{
	public:
		Mat4x4(void);
		Mat4x4(float v);
		Mat4x4(float v[4][4]);
		Mat4x4(const Quat &v);
		Mat4x4(const Mat4x4 &v);
		static Mat4x4	Identity(void);
		static Mat4x4	FromEuler(Vec3 v);
		static Mat4x4	Frustum(float v[6]);
		static Mat4x4	LookAt(const Vec3 &eye, Vec3 &center,
			const Vec3 &up);
		static Mat4x4	Ortho(float v[6]);
		static Mat4x4	Perspective(const float y_fov, const float aspect,
			const float near, const float far);
		static Mat4x4	Translate(const Vec3 &v);
		Vec4			&operator[](const int i);
		const Vec4		&operator[](const int i) const;
		Mat4x4 			&operator=(const Mat4x4 &v);
		bool 			operator==(const Mat4x4 &v);
		Mat4x4			operator+(const Mat4x4 &v);
		Mat4x4 			&operator+=(const Mat4x4 &v);
		Mat4x4			operator-(const Mat4x4 &v);
		Mat4x4 			&operator-=(const Mat4x4 &v);
		Mat4x4			operator*(const Mat4x4 &v);
		Mat4x4 			&operator*=(const Mat4x4 &v);
		Mat4x4			operator*(const Quat &v);
		Mat4x4 			&operator*=(const Quat &v);
		Vec4			row(const int i);
		float			dot(const Mat4x4 &v);
		float			length(void);
		Mat4x4			&scale(const float v);
		Mat4x4			&scale_aniso(const Vec3 &v);
		Mat4x4			&rotate(const Vec3 &up, const float angle);
		Mat4x4			&rotate_x(const float angle);
		Mat4x4			&rotate_y(const float angle);
		Mat4x4			&rotate_z(const float angle);
		Mat4x4			&set_translate(const Vec3 &v);
		Mat4x4			&translate_in_place(const Vec3 &v);
		Mat4x4 			transpose();
	private:
		Vec4			_val[4];
	};
	class	Quat
	{
	public:
		Quat(void);
		Quat(float x, float y, float z, float w);
		Quat(const Mat4x4 &v);
		static Quat		Identity(void);
		static Quat		Rotate(const Vec3 &up, const float angle);
		static Quat		SetRotate(const Vec3 &angle);
		float			&operator[](const int i);
		const float		&operator[](const int i) const;
		Quat 			&operator=(const Quat &v);
		bool 			operator==(const Quat &v);
		Quat			operator+(const Quat &v);
		Quat 			&operator+=(const Quat &v);
		Quat			operator-(const Quat &v);
		Quat 			&operator-=(const Quat &v);
		Quat			operator*(const Quat &v);
		Quat 			&operator*=(const Quat &v);
		Vec3			operator*(const Vec3 &v);
		float			mulInner(const Quat &v);
		Quat			&scale(const float v);
		Vec3			&xyz(void);
	private:
		float			_val[4];
	};
}

#endif
