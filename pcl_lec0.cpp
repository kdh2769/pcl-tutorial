// https://github.com/LimHyungTae/pcl_tutorial 를 학습하였음 
#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/conversions.h>
using namespace std;

template<class T>
void printPc(pcl::PointCloud<T>& cloud){
    int count = 0;
    // range-based for loops
    for(const auto& pt : cloud.points){ // const + auto + 참조자
        cout << count++ << " : ";
        cout << pt.x << ", "<< pt.y << ", "<< pt.z << '\n';
    }
}

int main (int argc, char **argv){
    cout << "------c0------"  << '\n';
    
    pcl::PointCloud<pcl::PointXYZ> c0;
    c0.resize(3);
    c0[0].x = 1; c0[0].y = 2; c0[0].z = 3;
    c0[1].x = 10; c0[1].y = 20; c0[1].z = 30;
    c0[2].x = 15; c0[2].y = 25; c0[2].z = 35;
    printPc(c0);

    // pcl::PointCloud 는 vector 에서 사용하는 멤버 함수를 사용할 수 있다.
    cout << "------c1------"  << '\n';
    pcl::PointCloud<pcl::PointXYZ> c1;
    pcl::PointXYZ pxyz;
    pxyz.x = 1 ; pxyz.y = 2 ; pxyz.z = 3;
    c1.push_back(pxyz);
    pxyz.x = 2; pxyz.y = 3 ; pxyz.z = 4;
    c1.push_back(pxyz);
    pxyz.x = 3; pxyz.y = 4 ; pxyz.z = 5;
    c1.push_back(pxyz);
    printPc(c1);

    cout << "------c2------" << '\n';
    pcl::PointCloud<pcl::PointXYZ> c2;
    c2.push_back(pcl::PointXYZ(2, 3, 4));
    c2.push_back(pcl::PointXYZ(3, 4, 5));
    c2.push_back(pcl::PointXYZ(4, 5, 6));
    printPc(c2);

    cout << "------Point Cloud sum------" << '\n';
    pcl::PointCloud<pcl::PointXYZ> c3;
    c3 = c2 + c1;
    printPc(c3); 

    cout << "size : " << c3.size() << '\n';
    cout << "-------push_back_c3---------" << '\n';
    c3.push_back(pcl::PointXYZ(22,33,44));
    printPc(c3);

    // begin ,end 는 iterator 반환
    cout << c2.begin() -> x << '\n';
    cout << c2.end() -> z << '\n'; // c++ vector 는 마지막에서 한 칸 뒤 위치를 리턴함
    cout << (c2.end() -1) -> z << '\n';    // 이는 c++ iterator 가 한칸 뒤 를 가리켜서다

    // front , back 는 원소 반환
    cout << c2.front() << '\n';
    cout << c2.front().x << '\n';

    cout << c2.back() << '\n';

    // at(index)  index 값 반환   
    cout << c2.at(0) << '\n';


    // deep copy 가 발생한다.
    cout << "---------c2--------- : "<< '\n';
    c2 += c1;
    printPc(c2);
    // deep copy 를 했기에  c1 에 값을 수정해줘도 c2 의 값엔 변화가 없다 
    c1.push_back(pcl::PointXYZ(10, 11, 12));
    cout << "---------c2--------- : "<< '\n';
    printPc(c2);
    cout << "---------c3--------- : " << '\n';
    printPc(c3);

    return 0;
}