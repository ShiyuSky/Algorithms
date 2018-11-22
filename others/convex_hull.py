"""
Algorithms for solving the Convex Hull problem
Ideas:
    1. To determine which side of the line from A=(x1, y1) to B=(x2, y2)
        a point falls on, compute the value: 
             d = (x-x1)(y2-y1) - (y-y1)(x2-x1)
        If d > 0, then the point lies on one side of the line
        If d < 0, then the point lies on the other side of the line
        If d = 0, then the point lies exactly on the line
    
"""
from sympy.geometry import Point, Segment


def is_point_above_line(p, l):
    p1, p2 = l.p1, l.p2
    x1, y1 = p1.x, p1.y
    x2, y2 = p2.x, p2.y
    x, y = p.x, p.y

    d = (x-x1)*(y2-y1) - (y-y1)*(x2-x1)

    return d < 0



def reduction_sol(points):
    # sort points by x
    points = sorted(points, key=lambda p: p.x)

    # get cross line from leftmost point to right-most point
    leftmost_p = points[0]
    rightmost_p = points[-1]
    cross_line = Segment(leftmost_p, rightmost_p)

    # get points above/below cross line
    upper_points = filter(lambda p: is_point_above_line(p, cross_line), points)
    lower_points = filter(lambda p: not is_point_above_line(p, cross_line), points)

    # find upper convex hull
    upper_segments = []

    # 1. TODO first line
    first_line = Segment(points[0], points[1])
    upper_segments.append(first_line)

    # 2. connect upper points sorted by x
    for p in upper_points[1:]:


    pass


reduction_sol([Point(0,0), Point(1,1), Point(2,1), Point(3,0.5), Point(4,10), Point(5,0), Point(3,-3)])