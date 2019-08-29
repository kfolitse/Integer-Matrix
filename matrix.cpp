/*****************************************************************************
 * File: matrix.cpp
 * Author: Amenyo Folitse
 * 
 * Purpose: Creates 2D integer matrix and basic matrix arithmetic operations.
 * 
 * Description: Implementation of Matrix class and its operations.
 * Build with : g++  -std=c++14 -Wall -Werror  -c -o matrix.o matrix.cpp
 * 
 *****************************************************************************/

#include "matrix.h"
#include <iostream>

Matrix::Matrix (){
    this->cols = 0;
    this->rows = 0;
    this->data = new int;
    this->data[0] = 0;   
}
/* 
 * 2D Matrix elements are stored in a dynamically 
 * allocated 1D Array in "row-major".
 * The element data[i][j] can be accessed at Data [i * cols + j].
 */
Matrix::Matrix (int r, int c){
    this->rows = r;
    this->cols = c;
    if ((r < 0 ) || (c < 0)){
        std::string msg = "Invalid arguments! rows and columns must"
                " be positive";
        throw std::invalid_argument ("s");
    } 
    this->data = new int[r * c];
    for (int i = 0; i < r * c; i++) {
        this->data[i] = 0;
    }
}
/* Destructor */
Matrix::~Matrix(){
    delete [] this->data;
}

/* Copy-constructor implementation */
Matrix::Matrix(const Matrix& mat){
    this->rows = mat.rows;
    this->cols = mat.cols;
    /* Make a deep copy*/
    this->data = new int [this->rows * this->cols];
    for (int i = 0; i < (this->rows * this->cols); i++) {
        this->data[i] = mat.data[i];
    }
}

/* Copy-assignment implementation */
Matrix& Matrix::operator=(const Matrix  &rhs){
    /* Check for self-assignment */
    if(this == &rhs ){
        return *this;
    }
    /* Release old memory */
    delete [] this->data; 
    
    /* Allocate new memory */
    this->rows = rhs.rows;
    this->cols = rhs.cols;
    this->data = new int [this->rows * this->cols];
    
    /* Perform deep copy */
    for (int i = 0; i < (this->rows * this->cols); i++) {
        this->data[i] = rhs.data[i];
    }
    /* Returns a non-constant reference */
    return *this; 

}


/*
 // Move-constructor implementation  
Matrix::Matrix(Matrix &&mat){
    this->rows = mat.rows;
    this->cols = mat.cols;
    this->data = mat.data;
 
    mat.data = nullptr;
}
// Move-assignment implementation  
Matrix & Matrix::operator=(Matrix &&rhs){
    
    if(this == &rhs ){
        return *this;
    }
    // Release old memory 
    delete [] this->data; 
    this->rows = rhs.rows;
    this->cols = rhs.cols;
    this->data = rhs.data;
    rhs.data = nullptr;
    
    // Returns a non-constant reference        
    return *this;
}
 
 */

/* 
 * Get implementation.
 * Index r = [0:rows -1]
 * Index c = [0:cols -1].
 */
int Matrix:: get(int r, int c) const {
    if ((r >= this->rows) || (c >= this->cols) || (r < 0) || (c < 0)) {
        std::string msg = "Arguments out of bounds ";
        throw std::invalid_argument (msg);
    }
    return  this->data[r * this->cols + c];
}

/* 
 * Setter implementation 
 * Index r = [0:rows -1]
 * Index c = [0:cols -1]
 * 
 */
void Matrix:: set(int r, int c, int value) {  
    if ((r >= this->rows) || (c >= this->cols) || (r < 0) || (c < 0)) {
        std::string msg = "Argument out of bounds ";
        throw std::invalid_argument (msg);
    }
    this->data[r * this->cols + c] = value;
}

/* Comparison operator == overload implementation */
bool Matrix::operator==(const Matrix &rhs){
    if ((this->rows != rhs.rows) || (this->cols != rhs.cols)) {
        return false;
    }
    for (int i = 0; i < (this->rows * this->cols); i++) {
        if (this->data[i] != rhs.data[i]) {
            return false;
        }
    }
    return true;
}
/* Inequality operators != overload implementation */
bool Matrix::operator!=(const Matrix &rhs){
    return !(this->operator==(rhs));
}
