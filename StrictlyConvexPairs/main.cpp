#include <iostream>
#include <vector>
#include <utility>
#include <limits.h>
#include <set>
#include <algorithm>

using namespace std;

struct Point 
{ 
    long int x; 
    long int y; 
    Point(int x, int y){this->x = x; this->y = y;}
    bool operator==(const Point &p) const {return this->x == p.x && this->y == p.y;}
    bool operator<(const Point &rhs) const {return this->x<rhs.x && this->y < rhs.y;}
}; 

bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 

int orientation(Point p, Point q, Point r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    long int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
  
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 

bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    long int o1 = orientation(p1, q1, p2); 
    long int o2 = orientation(p1, q1, q2); 
    long int o3 = orientation(p2, q2, p1); 
    long int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 


int main() {
    long int n, m;
    cin >> n >> m;
    long int x, y;
    vector<Point> vertices;
    long int max_x = INT_MIN, max_y = INT_MIN, min_x = INT_MAX, min_y = INT_MAX;
    while(n > 0){
        cin >> x >> y;
        if(x > max_x)
            max_x = x;
        if(x < min_x)
            min_x = x;
        if(max_y < y)
            max_y = y;
        if(min_y > y)
            min_y = y;
    
        vertices.push_back(Point(x, y));
        n--;   
    }
    vector<Point> points;

    while(m > 0){
        cin >> x >> y;
        points.push_back(Point(x, y));
        m--;
    }
    
    
    long int solution = 0;
    bool intersect = false;
    for(size_t i = 0; i < points.size(); i++){
        for(size_t j = i+1; j < points.size(); j++){

            intersect = false;
            for(size_t k = 0; k < vertices.size(); k++){
                if((intersect = doIntersect(points[i], points[j], vertices[k], vertices[(k+1)%vertices.size()]))){
                    
                    break;
                }
            }
            if(!intersect){
                solution++;
            }
        }   
    }
    
    cout << solution;
}