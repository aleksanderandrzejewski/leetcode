class FooBar {
private:
    int n;
    bool last_printed_foo;
    std::condition_variable cv;
    std::mutex mtx;

public:
    FooBar(int n) : last_printed_foo(false) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);

            this->cv.wait(lock, [this] { return !this->last_printed_foo; });

            printFoo();
            last_printed_foo = true;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);

            this->cv.wait(lock, [this] { return this->last_printed_foo; });

        	printBar();
            last_printed_foo = false;
            cv.notify_one();
        }
    }
};
