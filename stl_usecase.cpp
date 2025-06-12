#ifdef __cplusplus
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <string>
#include <functional>
#include <tuple>
#include <utility>
#include <memory>
#include <chrono>
#include <random>
#include <thread>

using namespace std;
using namespace std::chrono;

void vector_demo() {
    cout << "\n=== Vector Demo ===" << endl;
    
    // 1. Initialization
    vector<int> v1 = {5, 2, 8, 3, 1};  // Initializer list
    vector<int> v2(5, 10);              // 5 elements with value 10
    vector<int> v3(v1.begin(), v1.end()); // Range constructor
    
    // 2. Element access
    cout << "First element: " << v1.front() << endl;
    cout << "Last element: " << v1.back() << endl;
    cout << "Element at index 2: " << v1.at(2) << endl;
    
    // 3. Modifiers
    v1.push_back(4);                    // Add to end
    v1.pop_back();                      // Remove from end
    v1.insert(v1.begin() + 2, 10);      // Insert at position 2
    v1.erase(v1.begin() + 1);           // Remove element at position 1
    
    // 4. Capacity
    cout << "Size: " << v1.size() << ", Capacity: " << v1.capacity() << endl;
    v1.shrink_to_fit();                 // Reduce capacity to fit size
    
    // 5. Algorithms
    sort(v1.begin(), v1.end());
    auto it = find(v1.begin(), v1.end(), 10);
    if (it != v1.end()) {
        cout << "Found 10 at position: " << distance(v1.begin(), it) << endl;
    }
    
    // 6. Range-based for loop
    cout << "Vector elements: ";
    for (const auto& num : v1) {
        cout << num << " ";
    }
    cout << "\n";
    
    // 7. Using emplace_back (more efficient than push_back for complex types)
    vector<pair<string, int>> items;
    items.emplace_back("Apple", 5);  // Constructs in-place
    items.push_back({"Banana", 3});  // Creates temporary pair then copies
    
    // 8. Reserve space to prevent reallocation
    vector<int> largeVec;
    largeVec.reserve(1000);  // Allocate space for 1000 elements
    
    // 9. Using move semantics
    vector<string> source = {"one", "two", "three"};
    vector<string> destination = std::move(source);  // Move constructor
    
    // 10. Using custom allocator (advanced)
    vector<int, allocator<int>> v4 = {1, 2, 3, 4, 5};
    
    cout << "Vector demo completed.\n";

} // End of vector_demo

void map_demo() {
    cout << "\n=== Map Demo ===" << endl;
    
    // 1. Initialization
    map<string, int> ages = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};
    map<string, int> otherAges = {{"Dave", 40}, {"Eve", 22}};
    
    // 2. Insertion methods
    ages.insert({"David", 28});
    ages.emplace("Eve", 27);  // More efficient for complex types
    ages.insert(otherAges.begin(), otherAges.end());  // Range insertion
    
    // 3. Access elements
    cout << "Charlie's age: " << ages.at("Charlie") << endl;
    cout << "Using operator[]: " << ages["Frank"] << endl;  // Creates entry if not exists
    
    // 4. Find and count
    auto it = ages.find("Alice");
    if (it != ages.end()) {
        cout << "Found Alice: " << it->second << " years old\n";
    }
    
    // 5. Erase elements
    ages.erase("Frank");  // Remove by key
    it = ages.find("Eve");
    if (it != ages.end()) {
        ages.erase(it);  // Remove by iterator
    }
    
    // 6. Bucket interface (for unordered_map)
    unordered_map<string, int> ageHash = {
        {"Alice", 30}, {"Bob", 25}, {"Charlie", 35}
    };
    cout << "Bucket count: " << ageHash.bucket_count() << endl;
    
    // 7. Custom comparator
    struct CaseInsensitiveCompare {
        bool operator()(const string& a, const string& b) const {
            return lexicographical_compare(
                a.begin(), a.end(),
                b.begin(), b.end(),
                [](char c1, char c2) { return tolower(c1) < tolower(c2); }
            );
        }
    };
    
    map<string, int, CaseInsensitiveCompare> caseInsensitiveMap = {
        {"apple", 1}, {"Banana", 2}, {"ORANGE", 3}
    };
    
    // 8. Using lower_bound and upper_bound
    auto lb = ages.lower_bound("B");
    auto ub = ages.upper_bound("D");
    cout << "Names between B and D:\n";
    for (; lb != ub; ++lb) {
        cout << lb->first << " ";
    }
    cout << "\n";
    
    cout << "Map demo completed.\n";
}


void algorithm_demo() {
    cout << "\n=== Algorithm Demo ===" << endl;
    
    // 1. Non-modifying sequence operations
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums2 = {10, 20, 30, 40, 50};
    
    // Count and search
    auto count_evens = count_if(nums.begin(), nums.end(), 
                              [](int x) { return x % 2 == 0; });
    cout << "Even numbers: " << count_evens << endl;
    
    // Find first even number
    auto first_even = find_if(nums.begin(), nums.end(), 
                            [](int x) { return x % 2 == 0; });
    if (first_even != nums.end()) {
        cout << "First even number: " << *first_even << endl;
    }
    
    // 2. Modifying sequence operations
    // Transform (map)
    vector<int> squares;
    transform(nums.begin(), nums.end(), back_inserter(squares),
             [](int x) { return x * x; });
    
    // Copy with condition
    vector<int> evens;
    copy_if(nums.begin(), nums.end(), back_inserter(evens),
           [](int x) { return x % 2 == 0; });
    
    // 3. Sorting and related operations
    vector<int> unsorted = {5, 3, 8, 1, 2, 9, 4, 7, 6};
    sort(unsorted.begin(), unsorted.end());
    
    // Binary search on sorted range
    bool has_five = binary_search(unsorted.begin(), unsorted.end(), 5);
    cout << "Contains 5: " << (has_five ? "Yes" : "No") << endl;
    
    // 4. Heap operations
    make_heap(unsorted.begin(), unsorted.end());
    cout << "Max element: " << unsorted.front() << endl;
    
    // 5. Min/max
    auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
    cout << "Min: " << *min_it << ", Max: " << *max_it << endl;
    
    // 6. Numeric operations
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int product = accumulate(nums.begin(), nums.end(), 1, multiplies<>());
    cout << "Sum: " << sum << ", Product: " << product << endl;
    
    // 7. Remove-erase idiom
    vector<int> with_dupes = {1, 2, 2, 3, 4, 4, 4, 5};
    auto last = unique(with_dupes.begin(), with_dupes.end());
    with_dupes.erase(last, with_dupes.end());
    
    // 8. Sample (C++17)
    vector<int> out;
    sample(nums.begin(), nums.end(), back_inserter(out), 3, 
          mt19937{random_device{}()});
    
    cout << "Random sample of 3 elements: ";
    for (int n : out) cout << n << " ";
    cout << "\n";
    
    // 9. Execution policies (C++17) - disabled as it requires linking with TBB or similar
    // vector<int> big_data(1000000, 1);
    // auto start = high_resolution_clock::now();
    // sort(execution::seq, big_data.begin(), big_data.end());
    // auto end = high_resolution_clock::now();
    // cout << "Sequential sort took: " 
    //      << duration_cast<milliseconds>(end - start).count() << "ms\n";
    
    cout << "Algorithm demo completed.\n";
}


// Additional STL container demos
void container_demo() {
    cout << "\n=== Additional Container Demos ===" << endl;
    
    // 1. Deque (Double-ended queue)
    deque<int> dq = {1, 2, 3};
    dq.push_front(0);    // Add to front
    dq.push_back(4);     // Add to back
    
    // 2. List (Doubly-linked list)
    list<int> lst = {1, 2, 3, 4, 5};
    lst.splice(lst.begin(), lst, next(lst.begin(), 2), lst.end()); // Move elements
    
    // 3. Forward list (Singly-linked list)
    forward_list<int> flst = {1, 2, 3};
    flst.insert_after(flst.before_begin(), 0); // Insert at beginning
    
    // 4. Stack (LIFO)
    stack<int> stk;
    stk.push(1); stk.push(2);
    stk.pop(); // Removes 2
    
    // 5. Queue (FIFO)
    queue<int> q;
    q.push(1); q.push(2);
    q.pop(); // Removes 1
    
    // 6. Priority queue (Max-heap by default)
    priority_queue<int> max_heap;
    max_heap.push(3); max_heap.push(1); max_heap.push(4);
    
    // 7. Set (Unique, sorted elements)
    set<int> s = {3, 1, 4, 1, 5};
    auto result = s.insert(4); // No duplicates
    // Demonstrate usage of insert result to avoid unused variable warnings
    if (result.second) {
        cout << "Successfully inserted 4 into the set\n";
    } else {
        cout << "4 already exists in the set\n";
    }
    
    // 8. Multiset (Allows duplicates)
    multiset<int> ms = {1, 2, 2, 3};
    
    // 9. Unordered containers (Hash tables)
    unordered_set<string> us = {"apple", "banana", "cherry"};
    
    // 10. Array (Fixed-size array)
    array<int, 3> arr = {1, 2, 3};
    cout << "Array elements: ";
    for (int n : arr) {
        cout << n << " ";
    }
    cout << "\n";
    
    cout << "Container demos completed.\n";
}


// Smart pointers demo
void smart_pointer_demo() {
    cout << "\n=== Smart Pointers Demo ===" << endl;
    
    // 1. Unique pointer (exclusive ownership)
    unique_ptr<int> uptr = make_unique<int>(42);
    // unique_ptr<int> uptr2 = uptr; // Error: cannot copy
    unique_ptr<int> uptr2 = std::move(uptr); // Transfer ownership
    
    // 2. Shared pointer (reference counting)
    auto sptr1 = make_shared<int>(100);
    auto sptr2 = sptr1; // Shared ownership
    cout << "Shared use count: " << sptr1.use_count() << endl;
    
    // 3. Weak pointer (non-owning reference)
    weak_ptr<int> wptr = sptr1;
    if (auto locked = wptr.lock()) {
        cout << "Value through weak_ptr: " << *locked << endl;
    }
    
    // 4. Custom deleter
    auto deleter = [](FILE* f) { 
        if (f) {
            fclose(f);
            cout << "File closed.\n";
        }
    };
    unique_ptr<FILE, decltype(deleter)> file(fopen("example.txt", "w"), deleter);
    
    cout << "Smart pointer demo completed.\n";
}


// C++20 Ranges demo
void ranges_demo() {
    cout << "\n=== Ranges Demo (C++20) ===" << endl;
    
    // Disabling full ranges demo as it requires C++20 and proper includes
    // Here's a simpler version that works with C++17
    vector<int> nums = {8, 5, 3, 2, 7, 9, 1, 4, 6};
    
    // Sort and take first 5 elements (C++17 way)
    sort(nums.begin(), nums.end());
    vector<int> result;
    int count = 0;
    for (int n : nums) {
        if (count++ >= 5) break;
        result.push_back(n * 2);
    }
    
    cout << "First 5 elements doubled: ";
    for (int n : result) {
        cout << n << " ";
    }
    cout << "\n";
    
    cout << "Ranges demo completed.\n";
}


// Container utilities demo showcasing queue, deque, stack, numeric, functional, and for_each
void container_utils_demo() {
    cout << "\n=== Container Utilities Demo ===" << endl;
    
    // 1. Queue (FIFO) demonstration
    cout << "\n1. Queue (FIFO) Demo:" << endl;
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Queue elements (FIFO order): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    // 2. Deque (Double-ended queue) demonstration
    cout << "\n2. Deque Demo:" << endl;
    deque<int> dq = {1, 2, 3};
    dq.push_front(0);    // Add to front
    dq.push_back(4);     // Add to back
    
    cout << "Deque elements: ";
    for (int n : dq) {
        cout << n << " ";
    }
    cout << "\nFront: " << dq.front() << ", Back: " << dq.back() << endl;
    
    // 3. Stack (LIFO) demonstration
    cout << "\n3. Stack (LIFO) Demo:" << endl;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    cout << "Stack elements (LIFO order): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    // 4. Numeric algorithms
    cout << "\n4. Numeric Algorithms:" << endl;
    vector<int> nums = {1, 2, 3, 4, 5};
    
    // Accumulate
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int product = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
    cout << "Sum: " << sum << ", Product: " << product << endl;
    
    // Inner product
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};
    int dot_product = inner_product(v1.begin(), v1.end(), v2.begin(), 0);
    cout << "Dot product: " << dot_product << endl;
    
    // 5. Functional programming with function objects
    cout << "\n5. Functional Programming:" << endl;
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Using function objects from <functional>
    cout << "Even numbers: ";
    copy_if(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "), 
           [](int n) { return n % 2 == 0; });
    cout << "\n";
    
    // Using bind to create function objects
    auto is_greater_than = [](int x, int y) { return x > y; };
    auto is_greater_than_5 = bind(is_greater_than, placeholders::_1, 5);
    cout << "Numbers > 5: ";
    copy_if(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "), is_greater_than_5);
    cout << "\n";
    
    // 6. for_each algorithm
    cout << "\n6. for_each Demo:" << endl;
    cout << "Squared numbers: ";
    for_each(numbers.begin(), numbers.end(), [](int& n) {
        cout << n * n << " ";
    });
    cout << "\n";
    
    // 7. Using all together
    cout << "\n7. Combined Example:" << endl;
    deque<int> data = {5, 3, 8, 1, 9, 4, 7, 2, 6};
    
    cout << "Original data: ";
    for_each(data.begin(), data.end(), [](int n) { cout << n << " "; });
    cout << "\n";
    
    // Move first 3 elements to end
    for (int i = 0; i < 3; ++i) {
        data.push_back(data.front());
        data.pop_front();
    }
    
    cout << "After moving first 3 to end: ";
    for_each(data.begin(), data.end(), [](int n) { cout << n << " "; });
    cout << "\n";
    
    // 8. Set and Tuple Demo
    cout << "\n8. Set and Tuple Demo:" << endl;
    
    // Set demo
    cout << "\nSet Demo:" << endl;
    set<string> fruits = {"apple", "banana", "orange", "mango"};
    
    // Insert elements
    auto [it, inserted] = fruits.insert("banana"); // Duplicate - not inserted
    cout << "Insert 'banana' again: " << (inserted ? "Inserted" : "Not inserted (duplicate)") << endl;
    fruits.insert("grape");
    
    // Find elements
    if (fruits.find("apple") != fruits.end()) {
        cout << "Found 'apple' in the set" << endl;
    }
    
    // Iterate through set (automatically sorted)
    cout << "All fruits (sorted): ";
    for (const auto& fruit : fruits) {
        cout << fruit << " ";
    }
    cout << "\n";
    
    // Tuple demo
    cout << "\nTuple Demo:" << endl;
    // Creating tuples
    tuple<string, int, double> student1("Kim", 25, 3.8);
    auto student2 = make_tuple("Lee", 23, 4.2);
    
    // Accessing tuple elements
    cout << "Student 1: " << get<0>(student1) << ", " 
         << get<1>(student1) << " years old, GPA: " 
         << get<2>(student1) << endl;
    
    // Structured binding with tuple (C++17)
    auto [name, age, gpa] = student2;
    cout << "Student 2: " << name << ", " << age << " years old, GPA: " << gpa << endl;
    
    // Tuple comparison
    if (student1 > student2) {  // Lexicographical comparison
        cout << "Student 1 is ordered after Student 2" << endl;
    }
    
    // Tuple with references
    int score = 85;
    auto student3 = tie(name, age, score);  // Creates tuple of references
    score = 90;  // Modifies the referenced variable
    cout << "Updated score through tuple reference: " << get<2>(student3) << endl;
    
    cout << "Set and Tuple demo completed.\n";
    
    // 9. Chrono Demo
    cout << "\n9. Chrono Time Library Demo:" << endl;
    
    // 9.1 Time durations
    cout << "\n1. Time Durations:" << endl;
    using namespace std::chrono_literals; // for h, min, s, ms, us, ns literals
    
    auto one_second = 1s;
    auto half_second = 500ms;
    auto total = one_second + half_second;
    
    cout << "1s + 500ms = " << total.count() << "ms\n";
    cout << "In seconds: " << duration_cast<seconds>(total).count() << "s\n";
    
    // 9.2 Time points and measurement
    cout << "\n2. Time Measurement:" << endl;
    
    auto start = high_resolution_clock::now();
    
    // Simulate some work
    int calc_sum = 0;
    for (int i = 0; i < 1000000; ++i) {
        calc_sum += i;
    }
    // Use the calculated sum to avoid unused variable warning
    if (calc_sum > 0) { /* just using the variable */ }
    
    auto end = high_resolution_clock::now();
    auto duration = end - start;
    
    cout << "Calculation took " << duration.count() << " ticks\n";
    cout << "Or " << duration_cast<microseconds>(duration).count() << " microseconds\n";
    
    // 9.3 System clock and time points
    cout << "\n3. System Clock:" << endl;
    
    auto now = system_clock::now();
    time_t now_time = system_clock::to_time_t(now);
    cout << "Current time: " << ctime(&now_time);
    
    // Add 1 day to current time
    auto tomorrow = now + 24h;
    time_t tomorrow_time = system_clock::to_time_t(tomorrow);
    cout << "This time tomorrow: " << ctime(&tomorrow_time);
    
    // 9.4 Time since epoch
    cout << "\n4. Time Since Epoch:" << endl;
    auto epoch = system_clock::time_point{};
    auto now_since_epoch = system_clock::now() - epoch;
    
    cout << "Seconds since epoch: " 
         << duration_cast<seconds>(now_since_epoch).count() << "s\n";
    cout << "Hours since epoch: " 
         << duration_cast<hours>(now_since_epoch).count() << "h\n";
    
    // 9.5 Steady clock (monotonic clock)
    cout << "\n5. Steady Clock (for measurements):" << endl;
    auto steady_start = steady_clock::now();
    
    // Do some work
    this_thread::sleep_for(100ms);
    
    auto steady_end = steady_clock::now();
    auto steady_duration = duration_cast<milliseconds>(steady_end - steady_start);
    
    cout << "Operation took " << steady_duration.count() << "ms (using steady_clock)\n";
    
    cout << "Chrono demo completed.\n";
    
    cout << "Container utilities demo completed.\n";
}

// Function declarations for C compatibility

#ifdef __cplusplus
extern "C" {
#endif
void run_vector_demo() { vector_demo(); }
void run_map_demo() { map_demo(); }
void run_algorithm_demo() { algorithm_demo(); }
void run_container_demo() { container_demo(); }
void run_smart_pointer_demo() { smart_pointer_demo(); }
void run_container_utils_demo() { container_utils_demo(); }
#ifdef __cplusplus
}
#endif

#endif // __cplusplus
