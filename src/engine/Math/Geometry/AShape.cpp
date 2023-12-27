#include "AShape.h"

bool AShape::checkCollision(AShape *A, AShape *B, Vector2D<float> &mtv)
{
    float minOverlap = std::numeric_limits<float>::infinity();

    for (auto &axis: A->axes()) {
        std::pair<float, float> projectionA = A->projection(axis);
        std::pair<float, float> projectionB = B->projection(axis);

        // Check for overlap
        float overlapLength = gap(projectionA.first, projectionA.second, projectionB.first, projectionA.second);
        if(overlapLength == 0.0f)
        {
            mtv.Zeros();
            return false;
        }
        else
        {
            if(overlapLength < minOverlap)
            {
                minOverlap = overlapLength;
                mtv = axis * minOverlap;
            }
        }
    }

    for (auto &axis: B->axes()) {
        std::pair<float, float> projectionA = A->projection(axis);
        std::pair<float, float> projectionB = B->projection(axis);

        // Check for overlap
        float overlapLength = gap(projectionA.first, projectionA.second, projectionB.first, projectionA.second);
        if(overlapLength == 0.0f)
        {
            mtv.Zeros();
            return false;
        }
        else
        {
            if(overlapLength < minOverlap)
            {
                minOverlap = overlapLength;
                mtv = axis * minOverlap;
            }
        }
    }

    // need to reverse MTV if center offset and overlap are not pointing in the same direction
    bool notPointingInTheSameDirection = Vector2D<float>::dotProduct(A->center() - B->center(), mtv) < 0;
    if (notPointingInTheSameDirection) { mtv = mtv.reverse(); }
    return true;
}
