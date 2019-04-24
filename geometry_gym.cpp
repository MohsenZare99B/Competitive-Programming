#include<bits/stdc++.h>
using namespace std;

const double PI = asin(1) * 2;
const double EPS = 1e-9;

struct point {
    double x, y;
    point() { 
        x = y = 0; 
    }
    point(double _x, double _y) {
        x = _x, y = _y;
    }
    bool operator < (point other) const {
      if(fabs(x - other.x) > EPS)
        return x < other.x;
      return y < other.y;
    }

    bool operator == ( point other) const {
      return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y); // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
}

double deg_to_rad(double theta) {
  return theta * PI / 180.0;
}
point rotate(point p, double theta) {
  double rad = deg_to_rad(theta);
  return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

struct vec {
    double x, y;
    vec(double _x, double _y) {
        x = _x, y = _y;
    }
};

vec to_vec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}

double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = to_vec(a, p), ab = to_vec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
}
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = to_vec(a, p), ab = to_vec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if(u < 0.0) {
        c = point(a.x, a.y);
        return dist(a, p);
    }
    if(u > 1.0) {
        c = point(b.x, b.y);
        return dist(b, p);
    }
    return distToLine(p, a, b, c);
} 
double angle(point a, point o, point b) {
  vec oa = to_vec(o, a), ob = to_vec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) {
  return a.x * b.y - a.y * b.x;
}

// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
  return cross(to_vec(p, q), to_vec(p, r)) > 0;
}

bool collinear(point p, point q, point r) {
  return fabs(cross(to_vec(p, q), to_vec(p, r))) < EPS;
}

struct line {
  double a, b, c; // ax + by + c = 0
};

void pointsToLine(point p1, point p2, line &l) {
  if(fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0, l.b = 0.0, l.c = -p1.x;
  }else {
    l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = (double)(l.a * p1.x) - p1.y;
  }
}

bool areParallel(line l1, line l2) {
  return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool areSame(line l1, line l2) {
  return fabs(l1.c - l2.c) < EPS && areParallel(l1, l2);
}

bool areIntersect(line l1, line l2, point &p) {
  if(areParallel(l1, l2)) return false;

  // solve system of 2 linear algebraic equations with 2 unknowns
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
  else p.y = -(l2.a * p.x + l2.c);

  return true;
}

signed main() {}