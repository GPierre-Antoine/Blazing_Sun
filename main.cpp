#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <set>
#include <chrono>
#include <cstring>

#include "src/generic/math/point.hpp"
#include "src/generic/math/polygon.hpp"
#include "src/generic/physic/colliding_tile.h"

constexpr unsigned char meta_size = 2;

constexpr unsigned char meta_multi0 = 2;
constexpr unsigned char meta_multi1 = 3;
constexpr unsigned char meta_multi2 = 4;


typedef pag::bs::math::geometric_point<int,meta_size> point;
typedef pag::bs::math::polygon<int,meta_size> poly;
typedef pag::bs::physic::colliding_tile<int,meta_size> tile;


namespace
{

    //build_data (filename,1000 * meta_multi0 * meta_multi1 * meta_multi2);
    void build_data (const char* filename, const size_t number_of_item)
    {
        std::ofstream ofs;
        ofs.open(filename);
        std::srand (unsigned(std::time(0)));

        for (unsigned long int i = 0;i<(number_of_item -1);++i)
        {

            ofs << abs(std::rand())%256 << ' ';
        }
        ofs << abs(std::rand())%256;

        ofs.close ();
    }
}

int main ()
{
    using std::cout;
    using std::endl;

    std::vector<std::chrono::high_resolution_clock::time_point> times;
    const char filename[] = "resources/pt_coordinates.data";
    std::vector<point> points;
    std::ifstream ifs;
    ifs.open(filename,std::ios::in);
    bool data_available = false;
    if (ifs.is_open ())
    {
        data_available = (ifs.peek() != EOF);

        //operation 1 read from file
        times.push_back (std::chrono::high_resolution_clock::now());
        for (;ifs.peek() != EOF;)
        {
            point p;
            for (auto i = p.begin ();i<p.end ()-1;++i)
            {
                ifs >> *i;
            }
            points.push_back (p);
        }
        times.push_back (std::chrono::high_resolution_clock::now());
        ifs.close ();
    }

    if (data_available)
    {
        //operation 2; display all read data (stored in vector)
        times.push_back (std::chrono::high_resolution_clock::now());
        cout << std::string(100,' ');
        for (const auto&i:points)
        {
            for (const auto&j:i)
            {
                cout << std::setw (3) << j  << ", ";
            }
            cout << endl;
        }
        cout.flush ();
        times.push_back (std::chrono::high_resolution_clock::now());

        endl(cout);
        cout << "There is " << points.size () << " geometric_points of " << int(meta_size) << " dimension." << endl;
        endl(cout);

        //operation 3 sort !
        times.push_back (std::chrono::high_resolution_clock::now());
        std::sort(points.begin (),points.end ());
        times.push_back (std::chrono::high_resolution_clock::now());

        //operation 4 display anew
        times.push_back (std::chrono::high_resolution_clock::now());
        for (const auto&i:points)
        {
            for (const auto&j:i)
            {
                cout << std::setw (3) << j  << ", ";
            }
            cout << endl;
        }
        cout.flush ();
        times.push_back (std::chrono::high_resolution_clock::now());


        //operation 5 push in set 1
        std::set<point> s;
        times.push_back (std::chrono::high_resolution_clock::now());
        s.insert (points.begin(),points.end());
        times.push_back (std::chrono::high_resolution_clock::now());




        std::set<size_t> s2;
        std::vector<size_t> holder;
        holder.reserve (s.size ());
        using namespace std;
        struct hash<pag::bs::math::geometric_point<int,meta_size>> hasher;

        //operation 6 hash
        times.push_back (std::chrono::high_resolution_clock::now());
        for (const auto&i:points)
            holder.push_back (hasher(i));
        times.push_back (std::chrono::high_resolution_clock::now());

        //operation 7 put in hash 2
        times.push_back (std::chrono::high_resolution_clock::now());
        s2.insert (holder.begin(),holder.end());
        times.push_back (std::chrono::high_resolution_clock::now());

        cout << "There is " << setw(15) << s.size () << " differents elements in original set" << endl;
        cout << "There is " << setw(15) << s2.size () << " differents elements in hashed set" << endl;
        cout << "There is " << setw(15) << s.size () - s2.size () << " collisions in hash function" << endl;


        for (size_t i = 0;i<times.size ();i+=2)
        {
            using namespace std::chrono;
            duration<double> time_span = duration_cast<duration<double>>(times[i+1] - times[i]);
            cout << "operation " << std::setw(3) << i/2 +1 << " took "  << std::setw(20) << time_span.count ()
                 << " seconds to achieve" << endl;
        }

    }
    else
        build_data (filename,1000 * meta_multi0 * meta_multi1 * meta_multi2);


    return 0;
}