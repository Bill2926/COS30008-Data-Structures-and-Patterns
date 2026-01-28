
// COS30008, Tutorial 2, 2022

#pragma once

#include "Vector2D.h"
#include <iostream>
#include <string>
#include <fstream>

#define MAX_VERTICES 30

class Polygon
{
private:
    Vector2D fVertices[MAX_VERTICES];
    size_t fNumberOfVertices;
    
public:
    
    Polygon() : fNumberOfVertices(0) {};

    size_t getNumberOfVertices() const { return fNumberOfVertices; };

    const Vector2D& getVertex(size_t aIndex) const { return fVertices[aIndex]; };
    
    void readData(std::istream& aIStream) {
        while (aIStream >> fVertices[fNumberOfVertices] && fNumberOfVertices < MAX_VERTICES) {
            fNumberOfVertices++;
            // the fNumber acts as the index counter
            // everytime it inputs in, it will know the place in the fixed size array "fVertices"
            // then add into it, while also check for the limit
            // do not use getline() here bc it reads a string while my array strores Vector2D obj

            // After this, it will populate the 2DVector lists with 2DVector objs
        }
    };
    
    float getPerimeter() const {
        // use mod to handle circle closed loop
        // like the last node connects to the first ever node
        float perimeter = 0;
        for (int i = 0; i < fNumberOfVertices; i++) {
            int next_index = (i + 1) % fNumberOfVertices;
            Vector2D segment = fVertices[next_index] - fVertices[i];
            float seg_length = segment.length();
            perimeter += seg_length;
        };
        return perimeter;
    };
    
    Polygon scale(float aScalar) const {
        Polygon Result = *this; // Create a copy, therefore it won't modify the og<const>
        for (int i = 0; i < fNumberOfVertices; i++) {
            Vector2D multiplied = fVertices[i] * aScalar;
            Result.fVertices[i] = multiplied;
        };

        return Result;
    };
};
