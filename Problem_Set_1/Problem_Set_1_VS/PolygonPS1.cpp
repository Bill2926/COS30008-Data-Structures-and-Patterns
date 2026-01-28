#include "Polygon.h"
#include <cmath> 

float Polygon::getSignedArea() const
{
    float area = 0.0f;
    float abs_sum = 0.0f;

    for (int i = 0; i < fNumberOfVertices; i++) {
        Vector2D firstVertex = getVertex(i);
        int nextVertexIndex = (i + 1) % fNumberOfVertices;
        Vector2D secondVertex = getVertex(nextVertexIndex);
        float step = firstVertex.cross(secondVertex);
        abs_sum += step;
    }

    area = abs_sum / 2;
    return area;
}