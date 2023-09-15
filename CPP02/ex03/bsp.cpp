#include "Point.hpp"

// 두 평면 벡터 v1과 v2를 외적한 결과(벡터)의 z성분값을 반환
// v1과 v2는 평면 벡터이므로, 외적 결과는 평면에 수직인 벡터(x,y 성분의 값은 0, z 성분의 값은 실수)
// (v1 * v2) = (0, 0, v1.x * v2.y - v1.y * v2.x)
float operator*(Vector const &v1, Vector const &v2)
{
    return ((v1.getX() * v2.getY()) - (v1.getY() * v2.getX()));
}

// p1-p2-p3의 방향을 판별
// 양수 -> 반시계 방향, 음수 -> 시계 방향, 0 -> 일직선
float ccw(Point const &p1, Point const &p2, Point const &p3)
{
    Vector v1(p2.getX() - p1.getX(), p2.getY() - p1.getY()); // p1p2벡터
    Vector v2(p3.getX() - p1.getX(), p3.getY() - p1.getY()); // p1p3벡터

    return (v1 * v2);
}

// 점 a, b, c가 이루는 삼각형 안에 점 point가 위치하는지 참 혹은 거짓 판별
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float cw1 = ccw(point, a, b);
    float cw2 = ccw(point, b, c);
    float cw3 = ccw(point, c, a);

    return ((cw1 > 0 && cw2 > 0 && cw3 > 0) || (cw1 < 0 && cw2 < 0 && cw3 < 0));
}
