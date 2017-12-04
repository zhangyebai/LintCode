//
//  k_closest_points.cpp
//  LintCode
//
//  Created by 张夜白 on 2017/11/30.
//  Copyright © 2017年 张夜白. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

static int distanceOfTwoPoints(const Point & src, const Point & dest);
static int square(int x);
static int distanceOfTwoPoints(const Point & src, const Point & dest){
    return square(src.x - dest.x) + square(src.y - dest.y);
}
static int square(int x){
    return x * x;
}
auto global_point = Point(0,0);
auto  compare = [](const Point & l_point, const Point & r_point){
    // lpd: left point distance between itself to global_point
    int lpd = distanceOfTwoPoints(l_point, global_point);
    int rpd =distanceOfTwoPoints(r_point, global_point);
    if(lpd == rpd){
        if(l_point.x == r_point.x)
            return l_point.y < r_point.y;
        else
            return l_point.x < r_point.x;
    }else{
        return lpd < rpd;
    }
};
class K_Closest_Points {
public:
    /*
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> points, Point origin, int k) {
        // write your code here
        global_point = origin;
        std::priority_queue<Point, std::vector<Point>, decltype(compare)> p_queue(compare);
        vector<Point> result;
        for(const auto & point: points){
            p_queue.push(point);
            if(p_queue.size() > k)
                p_queue.pop();

        }
        for(; !p_queue.empty();){
            const Point & key = p_queue.top();
            result.push_back(key);
            p_queue.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char * argv[]){
    std::vector<Point> points = {Point(4,6),Point(4,7),Point(4,4),Point(2,5),Point(1,1),Point(1, 0)};
    Point origin = Point(0, 0);
    int countOfPoints = 3;
    K_Closest_Points k_closest_points;
    vector<Point>  result = k_closest_points.kClosest(points, origin, countOfPoints);
    std::cout << "[";
    for(const auto & point : result){
        std::cout << "[" << point.x << "," << point.y << "]";
    }
    std::cout << "]" << std::endl;
}
