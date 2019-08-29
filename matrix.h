/********************************************************* ******************
 * 
 * File:   matrix.h
 * Author: Amenyo Folitse
 * Created on:
 * Purpose: Creates 2D integer Matrix class and its operations.
 * 
 *****************************************************************************/

#ifndef MATRIX_H
#define MATRIX_H

/*
 * Creates a 2D integer matrix.
 * Example: Matrix m(2,4);
 * Matrix m1(m);
 */
class Matrix {
    public:
        /* Default constructor
         * initializes a 0x0 matrix.
         */
        Matrix ();
        
        /* 
         * Two arguments constructor.
         * Creates matrix rows x cols with all elements set to zero. 
         * @param row number of row of the matrix.
         * @param cols number of column of the matrix.
         */
        Matrix (int rows, int cols);
        
        /* 
         * Copy-constructor - - Deep copy.
         * 
         * Initializes a matrix object from a matrix object 
         * Example:  Matrix m1(2,3);
         *           Matrix m2(m1);
         * 
         * @param  mat  matrix used for the initialization.
         */
        Matrix(const Matrix &mat); 
        
        /* 
         * Copy- assignment- Deep copy
         * Assign a matrix object to another matrix object 
         * Example:  Matrix m1, m2;
         *           m1 = m2
         * @param  rhs right-hand side of the assignment.
         */
        Matrix& operator=(const Matrix &rhs);
        
        /*
         * Move-constructor.
         * Move the content of mat into the new object being initialized.
         * This is used for optimization.
         * Example: Matrix data = ...;
         *          Matrix filtered = filterAbove(data, 10.0)
         */
        Matrix(Matrix &&mat);
        
        /* 
         * Move-assignment.
         * This is used for optimization.
         * Example: Matrix data = ....,
         *          Matrix filtered;
         *          filtered = filterAbove(data, 10.0);
         */
        Matrix& operator=(Matrix &&mat);
        
         /* Destructor */
        ~Matrix ();
        
        /* Returns the number of rows  of the matrix */
        int numRows () const{ 
            return rows;
        }

        /* Returns the number of columns of the matrix  */
        int numCols() const {
            return cols;
        }
        
        /* 
         * Gets the value stored at row index r and column index c.
         * @param r row index 
         * @param c column index 
         * @return the value stored at row index r and column index c.
         * Index r = [0:rows -1] and c = [0:cols -1].
         * Throws an invalid argument exception if c or/and r are out of bounds.
         */
        int get(int r , int c) const;
        
        /*
         * Sets the number stored at row index r and column index c.
         * @param r row index 
         * @param c column index 
         * Index r = [0:rows -1] and c = [0:cols -1].
         * Throws an invalid_argument exception if r or/and c are out of bounds.
         */
        void set(int r, int c, int value) ;
        
        /* 
         * Equality operator == overload.
         * Tests equality of two matrix are equals.
         * @param rhs  right-hand side of the equality sign.
         */
        bool operator==(const Matrix &rhs);
        
        /* 
         * Inequality operator == overload
         * Tests inequality of two matrices.
         * @param rhs  right-hand side of the equality sign.
         */
        bool operator!=(const Matrix &rhs) ;
        
        /* Compound operator += overload */
       // Matrix & operator+=(const Matrix &rhs);
        
        /* Compound operator -= overload */
         // Matrix & operator-=(const Matrix &rhs);
        
        /* Compound operator *= overload */
        //Matrix & operator*=(const Matrix &rhs);
      
       
    
    private:
        int rows;
        int cols;
        /*
         * Matrix elements are stored in a 1D Array in a row ways.
         * The element data[i][j] = i * cols + j.
         */
        int *data;
       
};

#endif /* MATRIX_H */

