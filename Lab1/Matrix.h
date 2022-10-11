﻿#pragma once

#include <iostream>


constexpr double kPrecision = 0.00001;


// Клас рядка матриці. 
// До рядка можна додавати і віднімати інший рядок, множити чи ділити його на число.
// Існує прямий доступ до елемента рядка через оператор []. 
// Наприклад:
// Row row;
// row[2] = 16; - третій елемент рядка дорівнюватиме 16
class Row
{
public:
	// Повертає лінк на початок масиву рядків кількістю "row_count".
	// Кожний елемент массиву матиме виділену пам'ять на "numbers_count" даблів
	static Row* CreateRowArray(size_t rows_count, size_t numbers_count = 0);

	Row();
	Row(size_t numbers_count); // Виділяє пам'ять під "numbers_count" даблів
	Row(const Row&); // Конструктор копіювання (Правило трьох) 

	// Оператор присвоєння
	Row& operator=(const Row&);
	
	Row operator+(const Row&) const;
	Row operator-(const Row&) const;
	Row operator*(double) const;
	Row operator/(double) const;
	Row& operator+=(const Row&);
	Row& operator-=(const Row&);
	Row& operator*=(double);
	Row& operator/=(double);

	// оператори індексації
	double& operator[](size_t);
	const double& operator[](size_t) const;

	~Row();
	
private:
	double* _numbers;
	size_t _numbers_count;
};

// Клас матриці. Матриця складається з масиву рядків.
// Отримати доступ можна через подвійні квадратні дужки:
// Matrix m(10, 10);
// m[4][5] = 183; - шостий елемент п'ятого рядка дорівнюватиме 183
class Matrix
{
public:
	Matrix(size_t rows_count, size_t columns_count);
	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);

	Row& operator[](size_t index);
	const Row& operator[](size_t index) const;

	// Звичайне множення O(N^3)
	Matrix operator*(const Matrix&) const;
	Matrix& operator*=(const Matrix&);

	friend std::ostream& operator<<(std::ostream&, const Matrix&);
	friend std::istream& operator>>(std::istream&, Matrix&);

	~Matrix();

	size_t get_rows_count() const;
	size_t get_columns_count() const;

private:
	Row* _matrix;
	size_t _rows_count, _columns_count;
};