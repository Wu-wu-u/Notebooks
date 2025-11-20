#include <coroutine>
#include <fstream>
#include <string>
#include <iostream>
#include <optional>
#include <thread>

using namespace std;

// class Task {
// public:
//     struct promise_type {
//         string value_;
//         Task get_return_object() {
//             return Task{ 
//                 coroutine_handle<promise_type>::from_promise(*this)
//             };
//         }
//         suspend_always initial_suspend() { return {}; } 
//         suspend_always final_suspend() noexcept { return {}; }
//         void return_void() {}   
//         void unhandled_exception() { std::exit(1); }
//         suspend_always yield_value(const string&& value) {
//             value_ = std::move(value);
//             return {};
//         }
//     };
//     Task(coroutine_handle<promise_type> h) : handle_(h) {}
//     ~Task() {
//         if(handle_) handle_.destroy();
//     }
//     std::optional<string> next() {
//         if(!handle_ || handle_.done()) {
//             return std::nullopt;
//         }
//         handle_.resume();
//         if(handle_.done()) {
//             return std::nullopt;
//         }
//         return handle_.promise().value_;
//     }
// private:
//     coroutine_handle<promise_type> handle_{nullptr};
// };

// Task ReadFile() {
//     ifstream file("memory.md");
//     string line;
//     while(getline(file, line)) {
//         co_yield line;
//     }
// }

// int main() {
//     auto task = ReadFile();
//     while(auto line = task.next()) {
//         cout << *line << endl;
//     }
//     return 0;
// }

int main() {
    std::thread t = std::thread([](){
        std::cout << "Hello from thread!" << std::endl;
    });
    t.join();
    return 0;
}