#include <iostream>
#include "./Queue/smart_queue.h"
#include "TreeLvl2/Tree.h"
#include <stdlib.h>
#include <time.h>
#include "../Lab7/pentagon/pentagon.h"
#include "../Lab7/rhombus/rhombus.h"
#include "../Lab7/trapeze/trapeze.h"

int main() {
    srand(time(NULL));
    Pentagon* pentagon = new Pentagon();
    Trapeze* trapeze = new Trapeze();
    Rhombus* rhombus = new Rhombus();
    int act;
    SmartQueue< TreeLvl2<Figure> ,Figure > queue;
    while(1) {
        std::cout <<"1. Push\n";
        std::cout <<"2. Top\n";
        std::cout <<"3. Pop\n";
        std::cout <<"4. Empty\n";
        std::cout <<"5. Print\n";
        std::cout <<"6. Iterator print\n";
        std::cout <<"7. Delete\n";
        std::cout <<"8. Exit\n\n";
        std::cout <<"9. Delete by Square\n";
        std::cout << "10. Delete by Type\n";
        std::cout << "11. Generate\n\n";

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
                queue.push(new Pentagon(side));
            }
            if(act == 2) {
                size_t side,angle;
                std::cout <<"Enter side and angle: ";
                std::cin >> side >> angle;
                queue.push(new Rhombus(side,angle));

            }
            if(act == 3) {
                size_t a,b,c,d;
                std::cout << "Enter 2 bases:";
                std::cin >> a >> b;
                std::cout << "Enter 2 sides: ";
                std::cin >> c >> d;
                queue.push(new Trapeze(a,b,c,d));
            }
            continue;
        }
        if(act == 2) {
            if(queue.Empty()) {
                std::cout << "Queue is empty.\n\n";
            }
            else {
                Figure* f=queue.top();
                f->Print();
                f->Square();
            }
        }
        if(act == 3) {
            if(queue.Empty()) {
                std::cout << "Queue is empty.\n\n";
            }
            else {
                Figure* f=queue.pop();
                f->Print();
                delete(f);
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
        if(act == 8) {
            if (!queue.Empty()) {
                queue.del();
            }
            break;
        }

        if(act == 9) {
            double val;
            std::cout << "1. Less or Equal\n";
            std::cout << "2. Greater of Equal\n";

            std::cin >> act;
            std::cout << "Enter value:\n";
            std::cin >> val;

            if(act == 1) {
                queue.DelLess(val);
                continue;
            }
            if(act == 2) {
                queue.DelGreater(val);
                continue;
            }
        }
        if(act == 10) {
            std::cout << "1. Pentagon\n";
            std::cout << "2. Trapeze\n";
            std::cout << "3. Rhombus\n";
            std::cin >> act;
            if(act == 1) {
                queue.DelByType(pentagon);
            }
            if(act == 2) {
                queue.DelByType(trapeze);
            }
            if(act == 3) {
                queue.DelByType(rhombus);
            }
            std::cout << queue;
            continue;
        }
        if(act == 11) {
            if(!queue.Empty()) {
                queue.del();
            }
            std::cout << "Enter quantity of figures:\n";
            std::cin >> act;
            for(int i = 0; i < act;i++) {
                int type = rand() % 3;
                if(type == 0) {
                    queue.push(new Pentagon(rand() % 31));
                }
                if(type == 1) {
                    queue.push(new Trapeze(rand() % 31,rand() % 31,rand() % 31,rand() % 31));
                }
                if(type == 2) {
                    queue.push(new Rhombus(rand() % 31,rand() % 31));
                }
            }
            std::cout << queue;
            continue;
        }
    }
}
