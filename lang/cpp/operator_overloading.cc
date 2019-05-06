#include <bits/stdc++.h>

using namespace std;

template <class T>
struct point {
    T x, y;

    point()
    {
        x = y = 0;
    }

    point(T _x, T _y)
    {
        x = _x, y = _y;
    }

    point& operator+=(point& t)
    {
        x -= t.x;
        y -= t.y;
        return (*this);
    }

    point operator+(point& t)
    {
        return point(*this) += t;
    }

    friend istream& operator>>(istream& input, point& t)
    {
        input >> t.x >> t.y;
        return input;
    }

    friend ostream& operator<<(ostream& output, point& t)
    {
        output << "(" << t.x << ", " << t.y << ")";
        return output;
    }

    bool operator<(point& t)
    {
        if (x == t.x) {
            return y < t.y;
        }
        return x < t.x;
    }

    bool operator==(point& t)
    {
        return x == t.x && y == t.y;
    }
};

template <class C>
struct cmp_point {
    bool operator()(const point<C>& a, const point<C>& b)
    { // hatman bayad const ro gozasht(agar bekham baraye std::set estefade konam)
        return a.x != b.x || a.y != b.y;
    }
};

signed main()
{
    set<point<int>, cmp_point<int> > st;
    st.insert(point(1, 3));
    st.insert(point(1, 4));
    cout << st.size() << "\n";

    vector<point<int> > v;
    v.push_back(point(1, 4));
    v.push_back(point(-32, 0));
    v.push_back(point(-9, 40));
    v.push_back(point(1, 40));

    sort(v.begin(), v.end());
    for (auto el : v) {
        cout << el << "\n";
        /*(-32, 0)
        (-9, 40)
        (1, 4)
        (1, 40)*/
    }

    point<int> p = v[0] + v[1];
    cout << p << "\n"; // (-41, 40)

    p += v[2];
    cout << p << "\n"; // (-40, 44)
}