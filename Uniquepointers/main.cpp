#include <iostream>

#include <cmath>

#include <memory>

#include <vector>

using namespace std;

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



unique_ptr<Point> inputPoint() // TODO: Complete function that inputs a point using cin.
{
    double x,y;
    cin>>x;
    cin>>y;
    unique_ptr<Point> p = make_unique<Point>();
    p->setX(x);
    p->setY(y);
    return p;


}


void scalePoint(Point &p) // TODO: Complete function that multiples x and y by a scale.
{
    double res1,res2;
   res1= p.getX() * SCALE;
   res2 = p.getY() * SCALE;
   p.setX(res1);
   p.setY(res2);

}


vector<unique_ptr<Point>> getScaledPoints(double SCALE, int NUM_POINTS) {

    vector<unique_ptr<Point>> points;
    double res1, res2;
    for(int i =0; i<NUM_POINTS; i++){
        unique_ptr<Point> p = make_unique<Point>();
        p = inputPoint();
        //scalePoint(p);
        points.push_back(move(p));
        res1 = points[i]->getX() * SCALE;
        res2 =points[i]->getY() * SCALE;
        points[i]->setX(res1);
        points[i]->setY(res2);

    }
            return points;
}


int main() {

    vector<unique_ptr<Point>> pointsPtr = getScaledPoints(SCALE, NUM_POINTS);

    for (int i=0; i<NUM_POINTS; i++) {

        cout << "X: " << pointsPtr[i]->getX() <<  ", Y: " << pointsPtr[i]->getY();

        cout << endl;

    }

}
