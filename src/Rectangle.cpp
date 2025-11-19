#include <iostream>
using namespace std;

class Rectangle{
    private:
        int width;
        int height;
    public:
        Rectangle();
        Rectangle(int height, int width);

        int getHeight();
        int getWidth();
};

// 생성자
Rectangle :: Rectangle()
:height(1), width(1)
{}
Rectangle :: Rectangle(int height, int width)
{
    this -> height = height;
    this -> width = width;
}
// get함수
int Rectangle :: getHeight(){
    return height;
}
int Rectangle::getWidth(){
    return width;
}


int main(){
    Rectangle rect1;
    cout << rect1.getHeight() << " " << rect1.getWidth() << endl;

    Rectangle rect2(3, 4);
    cout << rect2.getHeight() << " " << rect2.getWidth() << endl;

    return 0;
}