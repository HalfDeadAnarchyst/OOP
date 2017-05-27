#include <iostream>
#include "smart_queue.h"

#include "../Lab1/pentagon/pentagon.h"
#include "../Lab1/rhombus/rhombus.h"
#include "../Lab1/trapeze/trapeze.h"

int main() {
    int act;
    SmartQueue< Figure > queue;
    while(1) {
        std::cout <<"1. Push\n";
        std::cout <<"2. Top\n";
        std::cout <<"3. Pop\n";
        std::cout <<"4. Empty\n";
        std::cout <<"5. Print\n";
        std::cout <<"6. Iterator print\n";
        std::cout <<"7. Delete\n";
        std::cout <<"8. Exit\n\n";

        std:: cin >> act;

        if(act == 1) {
            std::cout <<"1. Pentagon\n";
            std::cout <<"2. Rhombus\n";
            std::cout <<"3. Trapeze\n\n";

            std::cin >> act;
            if(act == 1) {
                size_t side;
                std::cout << "Enter side: ";
                std::cin >>side;
                queue.push(std::shared_ptr<Figure>(new Pentagon(side)));
            }
            if(act == 2) {
                size_t side,angle;
                std::cout <<"Enter side and angle: ";
                std::cin >> side >> angle;
                queue.push(std::shared_ptr<Figure>(new Rhombus(side,angle)));

            }
            if(act == 3) {
                size_t a,b,c,d;
                std::cout << "Enter 2 bases:";
                std::cin >> a >> b;
                std::cout << "Enter 2 sides: ";
                std::cin >> c >> d;
                queue.push(std::shared_ptr<Figure>(new Trapeze(a,b,c,d)));
            }
            continue;
        }
        if(act == 2) {
            if(queue.Empty()) {
                std::cout << "Queue is empty.\n\n";
            }
            else {
                std::shared_ptr<Figure> f=queue.first();
                f->Print();
                f->Square();
            }
        }
        if(act == 3) {
            if(queue.Empty()) {
                std::cout << "Queue is empty.\n\n";
            }
            else {
                std::shared_ptr<Figure> f=queue.pop();
                f->Square();
                std::cout << "\n";
            }
        }
        if(act == 4) {
            if(queue.Empty()) {
                std::cout << "Queue is empty\n\n";
            }
            else {
                std::cout << "Queue is not empty\n\n";
            }
        }
        if(act == 5) {
            std::cout << queue;

        }
        if(act == 6) {
            for(auto i : queue) {
                i->Print();
            }
        }
        if(act == 7) {
            queue.del();
            std::cout << queue;
        }
        if(act == 8) {1
            if (!queue.Empty()) {
                queue.del();
            }
            break;
        }
    }
}
