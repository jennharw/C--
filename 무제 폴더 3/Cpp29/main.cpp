#include <iostream>
#include <future>
#include <chrono>

using namespace std::chrono_literals;

//future
int main()
{
    {
        // promise - future - value
        std::promise<int> pro;
        std::future<int> fut = pro.get_future();

        std::thread th([](std::promise<int> pro) {
            std::this_thread::sleep_for(2s);
            pro.set_value(10);
            }, std::move(pro));

        std::cout << fut.get() << std::endl; // 10
        th.join();
    }
    {
        // promise - future - exception
        std::promise<int> pro;
        std::future<int> fut = pro.get_future();

        std::thread th([](std::promise<int> pro) {
            try {
                throw std::runtime_error("err");
            }
            catch (...) {
                std::exception_ptr e = std::current_exception();
                pro.set_exception(e);
            }
            }, std::move(pro));

        try 
        {
            std::cout << fut.get() << std::endl;
        }
        catch (const std::runtime_error& err)
        {
            std::cout << err.what() << std::endl;
        }
        th.join();
    }
    {
        // packaged_task, try catch 없앤다
        std::packaged_task<int(int)> task([](int value) {
            if (value < 0)
                throw std::runtime_error("err");
            return value;
            });

        std::future<int> fut = task.get_future();
        std::thread th(std::move(task), 10);
        try {
            std::cout << fut.get() << std::endl;
        }
        catch (const std::runtime_error& err) {
            std::cout << err.what() << std::endl;
        }
        th.join();
    }
    {
        //추상화 async callable
        std::cout << "thread Id: " << std::this_thread::get_id() << std::endl;
        // std::launch::deferred, fut.get()이 올때까지
        // std::launch::asnync 무조건 다른 스레드
        // default 는 둘중 하나 or 
        // async
        std::future<int> fut = std::async([](int value) {
            std::cout << "thread Id: " << std::this_thread::get_id() << std::endl;
            if (value < 0)
                throw std::runtime_error("errr");
            return value;
            }, -1);
        try {
            std::cout << fut.get() << std::endl;
        }
        catch (const std::runtime_error& err) {
            std::cout << err.what() << std::endl;
        }
    }
}
