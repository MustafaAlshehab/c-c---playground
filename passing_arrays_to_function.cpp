// ref https://www.cs.uic.edu/~jbell/CourseNotes/C_Programming/Arrays.html

#include <iostream>

using namespace std;

// Finds max in the array
float maxArray( const float numbers[ ], int arraySize, int & errorCode ); 

int main( void ) {

    float array1[ ] = { 10.0, 20.0, 100.0, 0.001 };
    float array2[ 2 ][ 3 ] = { { 5.0, 10.0, 20.0 },
                                { 8.0, 15.0, 42.0 } };
    
    int sizes[ 2 ] = { 4, 3 }, err1, err2, err3, err4, err5;
    float max1, max2, max3, max4, max5;
    
    max1 = maxArray( array1, 4, err1 );
    max2 = maxArray( array1, sizes[ 0 ], err2 );
    max3 = maxArray( array2[ 1 ], 3, err3 );
    max4 = maxArray( array2[ 0 ], 6, err4 );
    max5 = maxArray( array1, -4, err5 ); // Generates an error
    
    cout << "Maximums are " <<  max1 << ", " << max2 << ", " << max3 
            << ", " << max4 << ", " << max5 <<  endl;

    cout << "( Error codes are " <<  err1 << ", " << err2 << ", " << err3 
            << ", " << err4 << ", " << err5 << " )\n" ;      

    return 0;
    
}

float maxArray( const float numbers[ ], int arraySize, int & errorCode ) {

    /* Function to find the maximum in an array of floats
        Note the use of the keyword "const" to prevent changing array data */
    
    int i;
    float max;

    if( arraySize <= 0 ) {
        errorCode = -1;
        return 0.0;
    }
    
    errorCode = 0;
    
    max = numbers[ 0 ];
    
    for( i = 1; i < arraySize; i++ )
        max = ( numbers[ i ] > max ) ? numbers[ i ] : max;
        
    return max;
    
}  