/*生产消费模式
lock保证只有一个线程能够访问共享数据，其他想要访问的线程会阻塞，也叫线程互斥、线程安全
*/
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <fstream>
#include <condition_variable>

class Boundbuff
{
private:
    size_t start_pos_;
    size_t end_pos_;
    size_t size_;
    std::vector<int> buff_;
    std::mutex mtx_;
    std::condition_variable not_full_;
    std::condition_variable not_empty_;
    std::ofstream os_;
    std::ofstream os2_;
    std::ofstream is_;
    std::ofstream is2_;

public:
    Boundbuff(size_t n);
    ~Boundbuff()
    {
        is_.close();
        is2_.close();
        os_.close();
        os2_.close();
    }
    void produce(int n);
    void consume();
};

Boundbuff::Boundbuff(size_t n)
{
    is_.open("test.txt");
    is2_.open("test2.txt");
    os_.open("test3.txt");
    os2_.open("test4.txt");
    start_pos_ = 0;
    end_pos_ = 0;
    size_ = 0;
    buff_.resize(n);
}

void Boundbuff::produce(int n)
{
    {
        std::unique_lock<std::mutex> lock(mtx_);
        not_full_.wait(lock, [this]()
                       { return size_ < buff_.size(); });
        buff_[end_pos_] = n;
        auto id = std::this_thread::get_id();
        std::cout << "thread:" << id << "-----produce------" << n << std::endl;
        if (id == std::thread::id(2))
        {
            os2_ << "thread:" << id << "-----produce------" << n << std::endl;
        }
        else
        {
            os_ << "thread:" << id << "-----produce------" << n << std::endl;
        }
        // usleep(1000 * 300);
        end_pos_ = (end_pos_ + 1) % buff_.size();
        ++size_;
    }
    not_empty_.notify_one();
}

void Boundbuff::consume()
{
    int n;
    {
        std::unique_lock<std::mutex> lock(mtx_);
        not_empty_.wait(lock, [this]()
                        { return size_ > 0; });
        n = buff_[start_pos_];
        auto id = std::this_thread::get_id();
        if (id == std::thread::id(3))
        {
            is2_ << "thread:" << id << "------consume-------" << n << std::endl;
        }
        else if (id == std::thread::id(5))
        {
            is_ << "thread:" << id << "------consume-------" << n << std::endl;
        }
        start_pos_ = (start_pos_ + 1) % buff_.size();
        --size_;
    }
    not_full_.notify_one();
    // std::cout << "thread:" << std::this_thread::get_id() << "------consume-------" << n << std::endl;
}

// int i = 0;
// int j = 0;

void Producer(Boundbuff &buff)
{
    for (int i = 0; i < 1000; ++i)
    {
        buff.produce(i);
    }
}

void Consumer(Boundbuff &buff)
{
    for (int j = 0; j < 1000; ++j)
    {
        buff.consume();
    }
}

int main()
{
    time_t start = time(NULL);
    Boundbuff buff(10);
    std::vector<std::thread> threads;
    threads.push_back(std::thread(Producer, std::ref(buff)));
    threads.push_back(std::thread(Consumer, std::ref(buff)));
    threads.push_back(std::thread(Producer, std::ref(buff)));
    threads.push_back(std::thread(Consumer, std::ref(buff)));
    for (auto &t : threads)
    {
        t.join();
    }
    time_t end = time(NULL);
    std::cout << "----------------------------" << std::endl;
    std::cout << end - start << std::endl;

    return 0;
}