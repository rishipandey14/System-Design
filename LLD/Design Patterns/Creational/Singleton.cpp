// Singleton Pattern is a creational design pattern that guarantees a class 
// has only one instance and provides a global point of access to it.

#include<iostream>
#include<mutex>
using namespace std;

//.............................................Implementation...........................................................


//...........................................1-> Lazy Initialization...................................................





// This approach creates the singleton instance only when it is needed, 
// saving resources if the singleton is never used in the application.

class LazySingleton {
    private:
    static LazySingleton* instance;
    
    LazySingleton() {}
    
    public:
    static LazySingleton* getInstance() {
        if (instance == nullptr) {
            instance = new LazySingleton();
        }
        return instance;
    }
};

// This implementation is not thread-safe. If multiple threads call getInstance() 
// simultaneously when instance is null, it's possible to create multiple instances.







//...........................................2-> Thread-Safe Singleton...................................................


// This approach is similar to lazy initialization but also ensures that the singleton is thread-safe.
// This is achieved by making the getInstance() method synchronized ensuring only one thread can execute this method at a time.

class ThreadSafeSingleton {
    private:
    static ThreadSafeSingleton* instance;
    static mutex lock;
    
    ThreadSafeSingleton() {}
    
    public:
    static ThreadSafeSingleton* getInstance() {
        unique_lock<mutex> guard(lock);
        if (instance == nullptr) {
            instance = new ThreadSafeSingleton();
        }
        return instance;
        guard.unlock();
    }
};

// Although this approach is straightforward, using synchronized can cause substantial 
// overhead and reduce performance, which can be a bottleneck if called frequently.






//...........................................3-> Double-Checked Locking...................................................

// This approach minimizes performance overhead from synchronization by only synchronizing 
// when the object is first created.

class DoubleCheckedSingleton {
    private:
    static DoubleCheckedSingleton* instance;
    static mutex lock;
    
    DoubleCheckedSingleton() {}
    
    public:
    static DoubleCheckedSingleton* getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> guard(lock);
            if (instance == nullptr) {
                instance = new DoubleCheckedSingleton();
            }
        }
        return instance;
    }
};

// If the first check (instance == null) passes, we synchronize on the class object.
// We check the same condition one more time because multiple threads may have passed the first check.
// The instance is created only if both checks pass.
// Although this method is a bit complex to implement, it can drastically reduce the performance overhead.










//...........................................4-> Eager Initialization...................................................

// This implementation is one of the simplest and inherently thread-safe without needing explicit synchronization.

class EagerSingleton {
    private:
    static EagerSingleton* instance;
    
    EagerSingleton() {}
    
    public:
    static EagerSingleton* getInstance() {
        return instance;
    }
};

// While it is inherently thread-safe, it could potentially waste resources if the singleton 
// instance is never used by the client application.











//...........................................5-> Bill Pugh Singleton...................................................

// This implementation uses a static inner helper class to hold the singleton instance. 
// The inner class is not loaded into memory until it's referenced for the first time in the getInstance() method.
// It is thread-safe without requiring explicit synchronization.

class BillPughSingleton {
    private:
    BillPughSingleton() {}
    
    public:
    static BillPughSingleton* getInstance() {
        static BillPughSingleton instance;
        return &instance;
    }
};

// The Bill Pugh Singleton implementation, while more complex than Eager Initialization provides 
// a perfect balance of lazy initialization, thread safety, and performance, without the complexities 
// of some other patterns like double-checked locking.










//...........................................6-> Static Block Initialization...................................................

// This is similar to eager initialization, but the instance is created in a static block.
// It provides the ability to handle exceptions during instance creation, which is not possible 
// with simple eager initialization.


class StaticBlockSingleton {
    private:
    static StaticBlockSingleton* instance;
    
    StaticBlockSingleton() {
        // Simulate possible exception
        // throw runtime_error("Failed to initialize");
    }
    
    public:
    static StaticBlockSingleton* getInstance() {
        return instance;
    }
    
    static void init() {
        try {
            instance = new StaticBlockSingleton();
        } catch (...) {
            throw runtime_error("Exception occurred in creating singleton instance");
        }
    }
};


// It is thread safe but not lazy-loaded, which might be a drawback if the initialization is 
// resource-intensive or time-consuming.








//...........................................7-> Enum Singleton...................................................

// In this method, the singleton is declared as an enum rather than a class.

class EnumSingleton {
private:
    EnumSingleton() {}

public:
    static EnumSingleton* getInstance() {
        static EnumSingleton instance;
        return &instance;
    }

    void doSomething() {
        cout << "Doing something..." << endl;
    }
};


// It may not always be suitable especially if you need to extend a class or if lazy initialization 
// is a strict requirement.

