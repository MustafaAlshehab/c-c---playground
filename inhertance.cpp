// ref: https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
#include <iostream>

class shape {
    public:
        shape() {
            std::cout << "I am shape constructor" << std::endl;
        }
        ~shape(){
            std::cout << "I am shape destructor" << std::endl;
        }
        void setWidth(int w){
            width = w;
        }
        void setHight(int h) {
            hight = h;
        }
    protected:
        int width;
        int hight;
}; 

class paintCost {
    public:
        paintCost() {
            std::cout << "I am paintCost constructor" << std::endl;
        }
        ~paintCost() {
            std::cout << "I am paintCost destructor" << std::endl;
        }
        int getPaintCost(int area) {
            return area * 70;
        }
};

class rectangle : public shape, public paintCost {
    public:
        rectangle() {
            std::cout << "I am rectangle constructor" << std::endl;
        }
        ~rectangle() {
            std::cout << "I am rectangle destructor" << std::endl;
        }
        int getArea() {
            return (width * hight);
        }
};

class test {
    public:
        test() {
            std::cout << "This is test constructor" << std::endl;
        }
        ~test() {
            std::cout << "This is test destructor" << std::endl;
        }
    private:
        shape s;
};

int main() {
    // rectangle rectangle1;
    // rectangle1.setHight(5);
    // rectangle1.setWidth(7);
    // int area = rectangle1.getArea();
    // int paintCost = rectangle1.getPaintCost(area);

    // std::cout << "area is: " << area << " Paint cost is: $" << paintCost << std::endl;
    test t;
    
    return 0;
}
