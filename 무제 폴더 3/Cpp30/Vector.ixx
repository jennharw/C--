export module Vector;

export struct Vector
{
    float x, y;
    Vector operator+(const Vector& other) const{
        return Vector{x + other.x, y + other.y};
    }
}