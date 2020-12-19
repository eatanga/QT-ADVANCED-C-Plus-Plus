#include <iostream>

#include <cmath>

using namespace std;



const int NUM_POINTS = 5;

const double SCALE = 0.5;



class Point {

    private:

        double x;

        double y;

    public:

        Point() : x(0), y(0) {}

        double getX() {return x;}

        double getY() {return y;}

        void setX(double x) {this->x = x;}

        void setY(double y) {this->y = y;}

};



Point inputPoint() // TODO: Complete function that inputs a point using cin.
{
    double x,y;
    cin>>x;
    cin>>y;
    Point p;
    p.setX(x);
    p.setY(y);
    return p;


}


void scalePoint(Point &pt) // TODO: Complete function that multiples x and y by a scale.
{
    double res1,res2;
   res1= pt.getX() * SCALE;
   res2 = pt.getY() * SCALE;
   pt.setX(res1);
   pt.setY(res2);

}


void getScaledPoints(const double SCALE, int NUM_POINTS,Point points[]) // TODO: Complete function that inputs an array of points
                      // and scales each one of them by calling the above functions.
{
    for(int i =0; i<NUM_POINTS; i++){
        points[i] = inputPoint();
        scalePoint(points[i]);

    }
}


int main() {

    Point points[NUM_POINTS];

    getScaledPoints(SCALE, NUM_POINTS, points);

    for (int i=0; i<NUM_POINTS; i++) {

        cout << "X: " << points[i].getX() <<  ", Y: " << points[i].getY() << endl;

    }

}
