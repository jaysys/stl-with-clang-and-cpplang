#ifdef __cplusplus
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

void vector_demo() {
    cout << "\n=== Vector Demo ===" << endl;
    vector<int> v = {5, 2, 8, 3, 1};
    
    // Add elements
    v.push_back(4);
    v.insert(v.begin(), 0);
    
    // Sort
    sort(v.begin(), v.end());
    
    // Iterate
    cout << "Vector elements: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << "\n";
    
    // Find element
    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        cout << "Found 3 at position: " << distance(v.begin(), it) << endl;
    }
}

void map_demo() {
    cout << "\n=== Map Demo ===" << endl;
    map<string, int> ages = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};
    
    // Insert
    ages["David"] = 28;
    
    // Iterate
    cout << "People and their ages:\n";
    for (const auto& [name, age] : ages) {
        cout << name << ": " << age << " years old\n";
    }
    
    // Find
    if (ages.find("Alice") != ages.end()) {
        cout << "Alice is " << ages["Alice"] << " years old\n";
    }
}

void algorithm_demo() {
    cout << "\n=== Algorithm Demo ===" << endl;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Count even numbers
    int even_count = count_if(nums.begin(), nums.end(), [](int x) { 
        return x % 2 == 0; 
    });
    cout << "Even numbers count: " << even_count << endl;
    
    // Transform
    vector<int> squares;
    transform(nums.begin(), nums.end(), back_inserter(squares), 
             [](int x) { return x * x; });
    
    cout << "Squares: ";
    for (int n : squares) {
        cout << n << " ";
    }
    cout << "\n";
    
    // Accumulate
    int sum = accumulate(nums.begin(), nums.end(), 0);
    cout << "Sum of numbers: " << sum << endl;
}

// Function declarations for C compatibility
#ifdef __cplusplus
extern "C" {
#endif
void run_vector_demo() { vector_demo(); }
void run_map_demo() { map_demo(); }
void run_algorithm_demo() { algorithm_demo(); }
#ifdef __cplusplus
}
#endif

#endif // __cplusplus
