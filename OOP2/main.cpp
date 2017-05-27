#include <cstdlib>
#include <iostream>
#include <cmath>
#include "queue.cpp"

//zhuravlyow.andrei@yandex.ru

int main()
{
    Queue q=Queue();

    while(1) {

        std::cout <<"1. Push\n";
        std::cout <<"2. Top\n";
        std::cout <<"3. Pop\n";
        std::cout <<"4. Empty\n";
        std::cout <<"5. Print\n";
        std::cout <<"6. Delete\n";
        std::cout <<"7. Exit\n";

        int act;
        std::cin >> act;

        if(act == 1) {

            size_t a,b,c,d;
            std::cout << "Enter two bases:\n";
            std::cin >> a >> b;
            std::cout << "Enter two sides:\n";
            std::cin >> c >> d;

            Trapeze el = Trapeze(a,b,c,d);

            q.push(el);
        }

        if(act == 2) {
            if( q.Empty()) {
                std::cout << "Queue is empty\n";
            }
            else
                q.top();
        }

        if(act == 3) {
            if (q.Empty()) {
                std::cout << "Queue is empty!\n\n";
            } else {

                Trapeze pop=q.pop();
                pop.Print();
                pop.Square();
            }
        }

        if(act == 4) {
            if( q.Empty()) {
                std::cout << "Queue is empty\n";
            }
            else {
                std::cout << "Queue is not empty\n";
            }
        }

        if(act == 5) {

            std::cout <<q;
        }

        if(act == 6) {

            q.Del();
        }

        if(act == 7) {

            if(!q.Empty()) {
                q.Del();
            }
            break;
        }
    }
}
