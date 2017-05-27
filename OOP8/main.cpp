#include <iostream>
#include "smart_queue.h"
#include <future>
#include <functional>
#include <random>
#include <thread>
#include <cstdlib>
#include <memory>

#include "../Lab7/pentagon/pentagon.h"
#include "../Lab7/rhombus/rhombus.h"
#include "../Lab7/trapeze/trapeze.h"

void PrintMenu() {
    std::cout <<"1. Push\n";
    std::cout <<"2. Top\n";
    std::cout <<"3. Pop\n";
    std::cout <<"4. Empty\n";
    std::cout <<"5. Print\n";
    std::cout <<"6. Iterator print\n";
    std::cout <<"7. Delete\n";
    std::cout <<"8. Exit\n\n";
    std::cout <<"9. Sort\n";
    std::cout <<"10. Parallel Sort\n";
    std::cout <<"11. Gen\n\n";
}


int main() {

    SmartQueue<Figure> queue;
    Tree<std::shared_ptr<std::function<void(void)> > > commands;

    std::function<void(void)> generate = [&]() {
        int cnt;
        std::cin >> cnt;
        std::cout << "Generating...\n";
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0, 2);
        std::uniform_int_distribution<int> distribution1(1, 180);
        std::uniform_int_distribution<int> distribution2(1, 20);


        for(int i = 0; i < cnt; ++i) {

            int mod = distribution(generator);

            if(!mod) {
                queue.push(std::shared_ptr<Figure>(new Pentagon(distribution2(generator))));
            }
            else if(mod == 1) {
                queue.push(std::shared_ptr<Figure>(new Rhombus(distribution2(generator), distribution1(generator))));
            }
            else if(mod == 2) {
                queue.push(std::shared_ptr<Figure>(
                        new Trapeze(distribution2(generator), distribution2(generator), distribution2(generator),
                                    distribution2(generator))));
            }
        }
        std::cout << "Done\n";
    };

    std::function<void(void)> print = [&]() {
        std::cout << "Printing:\n";
        std::cout << queue;
    };

    std::function<void(void)> del_less = [&]() {
        std::cout << "Enter value. Figures with Square, less than value will be deleted\n";
        int val;
        std::cin >> val;
        SmartQueue<Figure> tmp;

        int size = queue.GetSize();
        for(int i = 0; i < size; i++) {
            std::shared_ptr<Figure> item = queue.pop();
            if(item->Square() >= val) {
                queue.push(item);
            }
        }

    };


    std::shared_ptr<std::function<void(void)> > generate1_(&generate, [](std::function<void(void)>*) {});
    //std::shared_ptr<std::function<void (void)> > print_ (&print,[](std::function<void (void) >*) {});
    //std::shared_ptr<std::function<void (void)> > del_less_ (&del_less,[](std::function<void (void)>*){});



    while(true) {
        int act;
        std::cout << "1. Add operation GENERATE in the end of the cycle\n";
        std::cout << "2. Add operation PRINT in the end if the cycle\n";
        std::cout << "3. Add operation DEL_LESS in the end of the cycle\n";
        std::cout << "4. Add operation DEL_QUEUE in the end of the cycle\n";
        std::cout << "5. Run your cycle\n";
        std::cout << "6. Exit\n";

        if(act == 1) {
            std::cout << "How much figures you want to add?\n";
            int cnt;
            std::cin >> cnt;
            std::shared_ptr<std::function<void(void)> > generate_ = std::make_shared<std::function<void(void)> >(
                    [&, cnt]() {
                        std::cout << "Generating...\n";
                        std::default_random_engine generator;
                        std::uniform_int_distribution<int> distribution(0, 2);
                        std::uniform_int_distribution<int> distribution1(1, 180);
                        std::uniform_int_distribution<int> distribution2(1, 100);


                        for(int i = 0; i < cnt; ++i) {

                            int mod = distribution(generator);

                            if(!mod) {
                                queue.push(std::shared_ptr<Figure>(new Pentagon(distribution2(generator))));
                            }
                            else if(mod == 1) {
                                queue.push(std::shared_ptr<Figure>(
                                        new Rhombus(distribution2(generator), distribution1(generator))));
                            }
                            else if(mod == 2) {
                                queue.push(std::shared_ptr<Figure>(
                                        new Trapeze(distribution2(generator), distribution2(generator),
                                                    distribution2(generator), distribution2(generator))));
                            }
                        }
                        std::cout << "Done\n";
                    });


            commands.Insert(generate_);
            continue;
        }
        if(act == 2) {
            std::shared_ptr<std::function<void(void)> > print_ = std::make_shared<std::function<void(void)> >([&]() {
                std::cout << "Printing:\n";
                std::cout << queue;

            });
            commands.Insert(print_);
        }
        if(act == 3) {
            int val;
            std::cout << "Enter value\n";
            std::cin >> val;
            std::shared_ptr<std::function<void(void)> > del_less_ = std::make_shared<std::function<void(void)> >(
                    [&,val]() {

                        SmartQueue<Figure> tmp;

                        int size = queue.GetSize();
                        for(int i = 0; i < size; i++) {
                            std::shared_ptr<Figure> item = queue.pop();
                            if(item->Square() >= val) {
                                queue.push(item);
                            }
                        }

                    });
            commands.Insert(del_less_);
        }
        if(act == 4) {
            std::shared_ptr<std::function<void(void)> > del_queue_ = std::make_shared<std::function<void(void)> >(
                    [&]() {
                        queue.del();
                    }
            );
            commands.Insert(del_queue_);
        }
        if(act == 5) {
            if(commands.Empty()) {
                std::cout << "Your cycle is empty\n";
            }
            else {
                while(!commands.Empty()) {
                    std::shared_ptr<std::function<void(void)> > cmd = commands.Pull(0);
                    std::future<void> ft = std::async(*cmd);
                    ft.get();
                }
            }
        }
        if(act == 6) {
            while(!commands.Empty()) {
                commands.Pull(0);
            }
            queue.del();
            break;
        }

    }
}






/*    int act;
    SmartQueue< Figure > queue;
    while(1) {

        PrintMenu();

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
        if(act == 8) {
            if (!queue.Empty()) {
                queue.del();
            }
            break;
        }

        if(act == 9) {
            queue.sort();
            std::cout << queue;
        }

        if(act == 10) {
            queue.parallelSort();
            std::cout << queue;
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
                    queue.push(std::shared_ptr<Figure>(new Pentagon(rand() % 31)));
                }
                if(type == 1) {
                    queue.push(std::shared_ptr<Figure>(new Trapeze(rand() % 31,rand() % 31,rand() % 31,rand() % 31)));
                }
                if(type == 2) {
                    queue.push(std::shared_ptr<Figure>(new Rhombus(rand() % 31,rand() % 31)));
                }
            }
            std::cout << queue;
        }
    }
    */