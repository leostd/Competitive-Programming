#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))

double degToRad(double d) { return d * PI / 180.0; }
double radToDeg(double r) { return r * 180.0 / PI; }

/* PUNTOS - POINTS  */

/* Coordenadas Enteras -  Integer Coordinates */
struct point_i { 
    int x, y;     
    point_i() { x = y = 0; }                      
    point_i(int _x, int _y) : x(_x), y(_y) {} 
};

/* Coordenadas Doble Precision - Double Coordinates*/
struct point { 
    double x, y;
    point() { x = y = 0.0; }                      
    point(double _x, double _y) : x(_x), y(_y) {}        
    bool operator == (const point &other) const {
    return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } 
};

/*  LINEAS - LINES */

/*  Ecuacion general de la recta - General Form 
            ax + by + c = 0
    a y b no son simultaneamente nulos.
    a or b can be zero, but not both at the same time.*/
struct line { 
    double a, b, c; 
    };         

/* Ecuacion simplificada de la recta - Simplified Form 
            mx + b = y
    m representa la pendiente de la recta y b el intercepto o
    punto de corte con el eje y.
    m its the slope and b its the intercept.
*/
struct line2 {
    double m, b;
};

/* VECTOR 2D */
struct vec2 { 
    double x, y;
    vec2() {x = y = 0;}
    vec2(double _x, double _y) : x(_x), y(_y) {} 
};

/* VECTOR 3D */
struct vec3 { 
    double x, y, z;
    vec3() {x = y = z = 0;}
    vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {} 
};

/* DISTANCIA EUCLIDIANA ENTRE 2 PUNTOS - EUCLIDEAN DISTANCE BETWEEN 2 POINTS
            d(p1,p2) = sqrt( sqr(p1.x - p2.x) + sqr(p1.y - p2.y) ) 
    hypot(x, y) = sqrt( sqr(x) + sqr(y) )*/
double dist(point p1, point p2) {             
  return hypot(p1.x - p2.x, p1.y - p2.y);
}


/* ROTAR UN PUNTO P, THETA GRADOS CON RESPECTO AL ORIGEN 
    - ROTATE P BY THETA DEGREES CCW W.R.T ORIGIN (0, 0)

*/
point rotate(point p, double theta) {
  double rad = degToRad(theta);    // multiply theta with PI / 180.0
  return point(p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad)); 
}

/* RECTA QUE PASA POR 2 PUNTOS - POINTS TO LINE 
    vertical => L(1, 0, -p1.x)
    otherwise => L(a, 1, c)
    where:
        a = -(p1.x - p2.x) / (p1.y - p2.y)
        c = - p1.y - (slope * p1.x)
*/

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {              
        l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;
    } 
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    } 
}

/*  RECTA QUE PASA POR 2 PUNTOS A ECUACION DE LA RECTA SIMPLIFICADA
    - SIMPLIFIED LINE EQ. BETWEEN 2 POINTS  
        vertical => L2(INF, x) & return 0
        otherwise => L2(m, c) & return 1
        where:
            m = (p1.y - p2.y) / (p2.x - p1.x) */
int pointsToLine2(point p1, point p2, line2 &l) {
    if (abs(p1.x - p2.x) < EPS) {          
        l.m = INF;                    
        l.b = p1.x;                  
        return 0;   
    }
    else {
        l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = p1.y - l.m * p1.x;
        return 1;     
    } 
}

/*  SON RECTAS PARALELAS? - ARE PARALLEL?
        true <=> l1.a == l2.a && l1.b == l2.b
        otherwise => false */
bool areParallel(line l1, line l2) {       
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

/*  SON RECTAS IGUALES? - ARE EQUAL? 
        true <=> parallel(l1, l2) && l1.c == l2.c
        otherwise  => false */
bool areSame(line l1, line l2) {           
  return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); 
}


/* SON RECTAS INTERSECTADAS?  */
// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;            // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true; 
}

/*  CONVERSION DE UN PUNTO A UN VECTOR 2D - POINT TO VEC2
        convert P(a) & P(b) to vector a->b*/        
vec2 toVec2(point a, point b) {        
    return vec2(b.x - a.x, b.y - a.y); 
}

/*  ESCALAR UN VECTOR 2D POR s - SCALE A VEC2 BY s
        where:
            0 < s < INF */
vec2 scale(vec2 v, double s) {  
    return vec2(v.x * s, v.y * s); 
}

/*  TRANSLADAR UN PUNTO EN FUNCION DE UN VECTOR 2D
    - TRANSLATE p ACCORDING TO v */
point translate(point p, vec2 v) {   
    return point(p.x + v.x , p.y + v.y); 
} 

/*  CONVERSION DE PUNTO Y PENDIENTE A LINEA - POINT & SLOPE
    TO LINE 
    Sea m, la pendiente y b el intercepto de una recta, la
    ecuacion general de la recta viene dada por
        -mx + y  + (-mx + p.y) */
void pointSlopeToLine(point p, double m, line &l) {
    l.a = -m;                                               
    l.b = 1;
    l.c = -((l.a * p.x) + (l.b * p.y)); 
}

/*  PUNTO MAS CERCANO - CLOSEST POINT 
    ((POR ESTUDIAR)) */
void closestPoint(line l, point p, point &ans) {
    line perpendicular;         // perpendicular to l and pass through p
    if (fabs(l.b) < EPS) {              // special case 1: vertical line
        ans.x = -(l.c);   ans.y = p.y;      return; }

    if (fabs(l.a) < EPS) {            // special case 2: horizontal line
        ans.x = p.x;      ans.y = -(l.c);   return; }
    pointSlopeToLine(p, 1 / l.a, perpendicular);
    areIntersect(l, perpendicular, ans);  
}

/* PRODUCTO PUNTO ENTRE VECTORES 2D - DOT VEC2 PRODUCT */
double dot(vec2 a, vec2 b) { return (a.x * b.x + a.y * b.y); }

/* NORMA DE UN VECTOR 2D */
double norm_sq(vec2 v) { return v.x * v.x + v.y * v.y; }

/* REFLEXION DE UN PUNTO CON RESPECTO A UNA LINEA 
 - POINT p REFLECTED THROUGH LINE l */
void reflectionPoint(line l, point p, point &ans) {
    point b;
    closestPoint(l, p, b);                     
    vec2 v = toVec2(p, b);                             
    ans = translate(translate(p, v), v); 
}

/* DISTANCIA DESDE UN PUNTO HASTA UNA LINEA */
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
  vec2 ap = toVec2(a, p), ab = toVec2(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));                 
  return dist(p, c); 
}


/*  DISTANCIA DESDE p HASTA EL SEGMENTO ab - DISTANCE FROM p TO 
    ab SEGMENT 
    Retorna el punto mas cercano en el cuarto parametro y la distancia.
    where:
        a != b */
double distToLineSegment(point p, point a, point b, point &c) {
  vec2 ap = toVec2(a, p), ab = toVec2(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) { c = point(a.x, a.y);                   // closer to a
    return dist(p, a); }         // Euclidean distance between p and a
  if (u > 1.0) { c = point(b.x, b.y);                   // closer to b
    return dist(p, b); }         // Euclidean distance between p and b
  return distToLine(p, a, b, c); }          // run distToLine as above

/*  ANGULO ENTRE 3 PUNTOS - ANGLE BETWEEN 3 POINTS 
    aob angle in radians */
double angle(point a, point o, point b) {
    vec2 oa = toVec2(o, a), ob = toVec2(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

/* PRODUCTO CRUZ ENTRE 2 VECTORES 2D - CROSS VEC2 PRODUCT */
double cross(vec2 a, vec2 b) { return a.x * b.y - a.y * b.x; }

/*  DETERMINAR SI 2 PUNTOS ESTAN EN SENTIDO CONTRARIO DE LAS AGUJAS DEL RELOJ 
    - ARE PQ & PR CCW? 
    Se debe modificar la desigualdad para no aceptar vectores colineales */
bool ccw(point p, point q, point r) {
    return cross(toVec2(p, q), toVec2(p, r)) >= 0; }

/*  DETERMINAR SI 2 PUNTOS SON COLINEALES - ARE THESE POINTS COLLINEAR? 
    2 vectores son colineales <-> son paralelos */
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec2(p, q), toVec2(p, r))) < EPS; 
}

/* DETERMINAR SI UN PUNTO ESTA DENTRO DE UN CIRCULO - IS P INSIDE THE CIRCLE? */                         
int insideCircle(point_i p, point_i c, int r) { 
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; 
} 

/* CIRCLE 2 POINTS RAD */
bool circle2PtsRad(point p1, point p2, double r, point &c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
              (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true; }         // to get the other center, reverse p1 and p2

/* PERIMETRO DE UN TRIANGULO */
double perimeter(double ab, double bc, double ca) {
    return ab + bc + ca; 
}

double perimeter(point a, point b, point c) {
      return dist(a, b) + dist(b, c) + dist(c, a); 
}

/* AREA DE UN TRIANGULO */
double area(double ab, double bc, double ca) {
  // Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
    double s = 0.5 * perimeter(ab, bc, ca);
    return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca); 
}

double area(point a, point b, point c) {
    return area(dist(a, b), dist(b, c), dist(c, a)); 
}

double rInCircle(double ab, double bc, double ca) {
  return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca)); }

double rInCircle(point a, point b, point c) {
  return rInCircle(dist(a, b), dist(b, c), dist(c, a)); }


/*******  POR ESTUDIAR!  *********/
// assumption: the required points/lines functions have been written
// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
  r = rInCircle(p1, p2, p3);
  if (fabs(r) < EPS) return 0;                   // no inCircle center

  line l1, l2;                    // compute these two angle bisectors
  double ratio = dist(p1, p2) / dist(p1, p3);
  point p = translate(p2, scale(toVec2(p2, p3), ratio / (1 + ratio)));
  pointsToLine(p1, p, l1);

  ratio = dist(p2, p1) / dist(p2, p3);
  p = translate(p1, scale(toVec2(p1, p3), ratio / (1 + ratio)));
  pointsToLine(p2, p, l2);

  areIntersect(l1, l2, ctr);           // get their intersection point
  return 1; }

double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * area(ab, bc, ca)); }

double rCircumCircle(point a, point b, point c) {
  return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); }

// assumption: the required points/lines functions have been written
// returns 1 if there is a circumCenter center, returns 0 otherwise
// if this function returns 1, ctr will be the circumCircle center
// and r is the same as rCircumCircle
int circumCircle(point p1, point p2, point p3, point &ctr, double &r){
  double a = p2.x - p1.x, b = p2.y - p1.y;
  double c = p3.x - p1.x, d = p3.y - p1.y;
  double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
  double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
  double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
  if (fabs(g) < EPS) return 0;

  ctr.x = (d*e - b*f) / g;
  ctr.y = (a*f - c*e) / g;
  r = dist(p1, ctr);  // r = distance from center to 1 of the 3 points
  return 1; }

// returns true if point d is inside the circumCircle defined by a,b,c
int inCircumCircle(point a, point b, point c, point d) {
  return (a.x - d.x) * (b.y - d.y) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)) +
         (a.y - d.y) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) * (c.x - d.x) +
         ((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.x - d.x) * (c.y - d.y) -
         ((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.y - d.y) * (c.x - d.x) -
         (a.y - d.y) * (b.x - d.x) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)) -
         (a.x - d.x) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) * (c.y - d.y) > 0 ? 1 : 0;
}

bool canFormTriangle(double a, double b, double c) {
  return (a + b > c) && (a + c > b) && (b + c > a); }

// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {
  double result = 0.0;
  for (int i = 0; i < (int)P.size()-1; i++)  // remember that P[0] = P[n-1]
    result += dist(P[i], P[i+1]);
  return result; }

// returns the area, which is half the determinant
double area(const vector<point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0; }

/* CONVEX HULL */
// Global Variable Pivot
point pivot;

// compare two angles 
bool angleCmp(point a, point b) {                 // angle-sorting function
    if (collinear(pivot, a, b))                               // special case
        return dist(pivot, a) < dist(pivot, b);    // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P) {   // the content of P may be reshuffled
  int i, j, n = (int)P.size();
  if (n <= 3) {
    if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
    return P;                           // special case, the CH is P itself
}

  // first, find P0 = point with lowest Y and if tie: rightmost X
  int P0 = 0;
  for (i = 1; i < n; i++)
    if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
      P0 = i;

  point temp = P[0]; P[0] = P[P0]; P[P0] = temp;    // swap P[P0] with P[0]

  // second, sort points by angle w.r.t. pivot P0
  pivot = P[0];                    // use this global variable as reference
  sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]

  // third, the ccw tests
  vector<point> S;
  S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);   // initial S
  i = 2;                                         // then, we check the rest
  while (i < n) {           // note: N must be >= 3 for this method to work
    j = (int)S.size()-1;
    if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);  // left turn, accept
    else S.pop_back(); }   // or pop the top of S until we have a left turn
  return S; 
} 
/********* FIN POR ESTUDIAR *************/

int main()
{
    return 0;
}
