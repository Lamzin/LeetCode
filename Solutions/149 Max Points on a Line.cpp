/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

bool operator <(const Point &A, const Point &B){
    if (A.x != B.x) return A.x < B.x;
    return A.y < B.y;
}


int __gcd(int a, int b){
  if (a == 0) return b;
  if (b == 0) return a; 
  if (a < 0) a *= -1;
  if (b < 0) b *= -1;

  while (b){
    a %= b;
    swap(a, b);
  }
  return a;
}

struct Line{
  int a, b, c;
  Line(const Point &A, const Point &B){
    a = B.y - A.y;
    b = A.x - B.x;
    c = -a * A.x - b * A.y;
    int gcd = __gcd(__gcd(a, b), c);
    if (a < 0) gcd *= -1;
    if (gcd != 0){
      a /= gcd;
      b /= gcd;
      c /= gcd;
    }
  }

  bool operator <(const Line &B) const{
    if (a != B.a) return a < B.a;
    if (b != B.b) return b < B.b;
    return c < B.c;
  }
};





class Solution {
public:
  int maxPoints(vector<Point>& points) {
    if (points.size() <= 2) return points.size();
    map<Line, int> mp;
    map<Point, int> mp_points;
    int max_count = 0;

    for(Point p : points) mp_points[p]++;

    for (auto it_i = mp_points.begin(); it_i != mp_points.end(); it_i++){
        auto it_j = it_i;
        max_count = max(max_count, it_i->second);
        it_j++;
        for(; it_j != mp_points.end(); it_j++){
            mp[Line(it_i->first, it_j->first)] += it_i->second * it_j->second + it_i->second + it_j->second - 2;
        }
    }

    // for (int i = 0; i < points.size(); i++){
    //   for (int j = i + 1; j <points.size(); j++){
    //     mp[Line(points[i], points[j])]++;
    //   }
    // }

    for (auto it = mp.begin(); it != mp.end(); it++){
      if (it->second > max_count) max_count = it->second;
    }

    int sqrt_N = sqrt(8 * max_count + 1);
    for (int i = max(0, sqrt_N - 2); i < sqrt_N + 2; i++){
      if (i*i == 8 * max_count + 1){
        return (i - 1) / 2 + 1;
      }
    }

    return (sqrt(8 * max_count + 1) - 1) / 2 + 1;
  }
};