# STL (Standard Template Library) Examples and Use Cases

C++의 STL(Standard Template Library)을 활용한 다양한 예제들을 제공합니다. 각 컨테이너와 알고리즘의 사용법과 실제 적용 사례를 설명합니다.
또한 C와 C++을 함께 사용하는 방법을 보여주는 예제입니다. C++의 STL 기능을 C에서 사용할 수 있도록 인터페이스를 제공합니다.

## 1. Vector (벡터)

### 사용 사례

- **동적 배열**이 필요할 때 (크기가 변할 수 있는 배열)
- **빈번한 랜덤 접근**이 필요할 때
- **맨 뒤**에서의 삽입/삭제가 빈번할 때

### 예제 코드

```cpp
vector<int> v = {5, 2, 8, 3, 1};

// 요소 추가
v.push_back(4);          // 맨 뒤에 4 추가
v.insert(v.begin(), 0);  // 맨 앞에 0 삽입

// 정렬
sort(v.begin(), v.end());

// 출력: 0 1 2 3 4 5 8

// 요소 검색
auto it = find(v.begin(), v.end(), 3);
if (it != v.end()) {
    cout << "Found 3 at position: " << distance(v.begin(), it);
    // 출력: Found 3 at position: 3
}
```

## 2. Map (맵)

### 사용 사례

- **키-값 쌍**으로 데이터를 저장해야 할 때
- **정렬된** 키 기반 검색이 필요할 때
- **빠른 검색**이 필요할 때 (O(log n) 시간 복잡도)

### 예제 코드

```cpp
map<string, int> ages = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35}
};

// 요소 추가/수정
ages["David"] = 28;


// 순회
for (const auto& [name, age] : ages) {
    cout << name << ": " << age << " years old\n";
}

// 검색
if (ages.find("Alice") != ages.end()) {
    cout << "Alice is " << ages["Alice"] << " years old\n";
}
```

## 3. STL 알고리즘

### 사용 사례

- **컬렉션 처리**가 필요할 때
- **정렬, 검색, 변환** 등의 일반적인 연산이 필요할 때
- **함수형 프로그래밍** 스타일의 연산이 필요할 때

### 예제 코드

```cpp
vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// 조건에 맞는 요소 개수 세기
int even_count = count_if(nums.begin(), nums.end(),
    [](int x) { return x % 2 == 0; });
// even_count = 5

// 변환 (transform)
vector<int> squares;
transform(nums.begin(), nums.end(), back_inserter(squares),
         [](int x) { return x * x; });
// squares = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100}

// 누적 합계
int sum = accumulate(nums.begin(), nums.end(), 0);
// sum = 55
```

## 4. 각 컨테이너 선택 가이드

| 필요 사항                              | 추천 컨테이너                              | 이유                                  |
| -------------------------------------- | ------------------------------------------ | ------------------------------------- |
| 빠른 검색이 필요할 때                  | `std::map`, `std::set`                     | 균형 이진 트리 기반으로 O(log n) 검색 |
| 동적 배열이 필요할 때                  | `std::vector`                              | 연속된 메모리 공간, 캐시 친화적       |
| 양 끝에서의 삽입/삭제가 필요할 때      | `std::deque`                               | 양방향 큐로 양쪽 끝에서 O(1) 연산     |
| 정렬이 필요 없고 빠른 검색이 필요할 때 | `std::unordered_map`, `std::unordered_set` | 해시 테이블 기반으로 평균 O(1) 검색   |

## 5. C/C++ 통합 아키텍처

이 프로젝트는 C와 C++을 함께 사용하는 방법을 보여주는 예제입니다. C++의 STL 기능을 C에서 사용할 수 있도록 인터페이스를 제공합니다.

### 주요 구성 요소

1. **C++ 소스 (stl_usecase.cpp)**

   - STL 컨테이너와 알고리즘 구현
   - `extern "C"`를 사용하여 C에서 호출 가능한 인터페이스 제공

2. **C 헤더 (stl_usecase.h)**

   - C++ 구현을 위한 C 호환 인터페이스 선언
   - `#ifdef __cplusplus`로 C와 C++ 모두에서 사용 가능하도록 처리

3. **C 메인 프로그램 (app.c)**

   - C++로 구현된 STL 기능을 호출
   - 메뉴 기반 인터페이스 제공

4. **유틸리티 함수 (utils.h/utils.c)**
   - C로 구현된 유틸리티 함수들
   - C++에서도 사용 가능

### C/C++ 상호 운용성 보장 방법

1. **extern "C" 사용**

   ```cpp
   #ifdef __cplusplus
   extern "C" {
   #endif

   // C 호환 함수 선언
   void run_vector_demo();

   #ifdef __cplusplus
   }
   #endif
   ```

2. **헤더 가드**

   - 모든 헤더 파일에 `#ifndef`, `#define`, `#endif`를 사용하여 중복 포함 방지

3. **이름 맹글링 방지**
   - C++의 이름 맹글링을 방지하기 위해 C 함수는 `extern "C"`로 래핑

## 6. 빌드 및 실행 방법

### Makefile을 사용한 빌드

프로젝트는 Makefile을 제공하여 빌드 과정을 단순화했습니다.

1. **프로젝트 빌드**

   ```bash
   make
   ```

   - 모든 소스 파일을 컴파일하고 실행 파일을 생성합니다.
   - C++17 표준을 사용하여 컴파일됩니다.

2. **프로그램 실행**

   ```bash
   make run
   ```

   - 빌드 후 프로그램을 자동으로 실행합니다.

3. **재빌드 및 실행**

   ```bash
   make rerun
   ```

   - 기존 빌드 파일을 정리하고 다시 빌드한 후 실행합니다.

4. **빌드 정리**
   ```bash
   make clean
   ```
   - 생성된 오브젝트 파일과 실행 파일을 삭제합니다.

### 수동 빌드 (Makefile을 사용하지 않는 경우)

```bash
g++ -Wall -Wextra -std=c++17 stl_usecase.cpp app.c utils.c -o app -lstdc++
./app
```

## 7. 컨테이너 유틸리티 데모

### 7.1 Queue (큐)

#### 사용 사례
- **FIFO(First-In-First-Out)** 구조가 필요할 때
- **순서대로 처리**가 필요한 작업에 적합
- BFS(Breadth-First Search) 알고리즘 구현 시

#### 예제 코드
```cpp
queue<int> q;
q.push(10);  // 10 삽입
q.push(20);  // 20 삽입
q.push(30);  // 30 삽입

// 큐의 모든 요소 출력 (FIFO 순서)
while (!q.empty()) {
    cout << q.front() << " ";  // 맨 앞 요소 접근
    q.pop();                    // 맨 앞 요소 제거
}
// 출력: 10 20 30
```

### 7.2 Deque (덱)

#### 사용 사례
- **양쪽 끝**에서의 삽입/삭제가 빈번할 때
- **슬라이딩 윈도우** 알고리즘 구현 시
- **큐와 스택**이 모두 필요한 경우

#### 예제 코드
```cpp
deque<int> dq = {1, 2, 3, 4, 5};

dq.push_front(0);  // 앞에 0 추가
dq.push_back(6);   // 뒤에 6 추가

dq.pop_front();    // 앞에서 제거
dq.pop_back();     // 뒤에서 제거

// 덱의 모든 요소 출력
for (int n : dq) {
    cout << n << " ";
}
// 출력: 1 2 3 4 5
```

### 7.3 Stack (스택)

#### 사용 사례
- **LIFO(Last-In-First-Out)** 구조가 필요할 때
- **되돌리기(Undo)** 기능 구현 시
- **괄호 짝 맞추기**와 같은 문제 해결 시

#### 예제 코드
```cpp
stack<int> s;
s.push(1);  // 1 삽입
s.push(2);  // 2 삽입
s.push(3);  // 3 삽입

// 스택의 모든 요소 출력 (LIFO 순서)
while (!s.empty()) {
    cout << s.top() << " ";  // 맨 위 요소 접근
    s.pop();                  // 맨 위 요소 제거
}
// 출력: 3 2 1
```

### 7.4 Numeric Algorithms (수치 알고리즘)

#### 사용 사례
- **누적 합계** 계산 시
- **내적(dot product)** 계산 시
- **수학적 연산**이 필요한 경우

#### 예제 코드
```cpp
vector<int> nums = {1, 2, 3, 4, 5};

// 합계 계산
int sum = accumulate(nums.begin(), nums.end(), 0);
// 곱 계산 (1*2*3*4*5)
int product = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());

// 내적 계산
vector<int> a = {1, 2, 3};
vector<int> b = {4, 5, 6};
int dot_product = inner_product(a.begin(), a.end(), b.begin(), 0);

cout << "Sum: " << sum << "\n";           // 출력: Sum: 15
cout << "Product: " << product << "\n";    // 출력: Product: 120
cout << "Dot product: " << dot_product;     // 출력: Dot product: 32
```

### 7.5 Functional Programming (함수형 프로그래밍)

#### 사용 사례
- **조건에 맞는 요소**만 선택할 때
- **변환 작업**이 필요할 때
- **람다 표현식**을 활용한 유연한 연산이 필요할 때

#### 예제 코드
```cpp
vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// 짝수만 선택
vector<int> evens;
copy_if(nums.begin(), nums.end(), back_inserter(evens),
        [](int x) { return x % 2 == 0; });

// 5보다 큰 수 선택
vector<int> greater_than_five;
copy_if(nums.begin(), nums.end(), back_inserter(greater_than_five),
        [](int x) { return x > 5; });

// for_each로 각 요소에 제곱 연산 적용
vector<int> squares;
for_each(nums.begin(), nums.end(), 
         [&squares](int x) { squares.push_back(x * x); });
```

### 7.6 Set (집합)

#### 사용 사례
- **중복을 허용하지 않는** 컬렉션이 필요할 때
- **정렬된** 요소 집합이 필요할 때
- **집합 연산** (합집합, 교집합 등)이 필요할 때

#### 예제 코드
```cpp
set<string> fruits = {"apple", "banana", "orange"};

// 요소 추가 (중복은 자동 제거)
auto [it, inserted] = fruits.insert("banana");
if (!inserted) {
    cout << "'banana'는 이미 존재합니다.\n";
}

// 요소 검색
if (fruits.find("apple") != fruits.end()) {
    cout << "사과를 찾았습니다!\n";
}

// 정렬된 순서로 출력 (자동 정렬됨)
for (const auto& fruit : fruits) {
    cout << fruit << " ";
}
// 출력: apple banana orange
```

### 7.7 Tuple (튜플)

#### 사용 사례
- **서로 다른 타입**의 데이터를 하나로 묶을 때
- **함수에서 여러 값 반환**이 필요할 때
- **구조체 대신 간단하게** 사용할 때

#### 예제 코드
```cpp
// 튜플 생성
auto student1 = make_tuple("Kim", 25, 3.8);
tuple<string, int, double> student2("Lee", 23, 4.2);

// 요소 접근 (인덱스 사용)
cout << get<0>(student1) << "의 나이: " << get<1>(student1) << "\n";

// 구조화된 바인딩 (C++17)
auto [name, age, gpa] = student2;
cout << name << "의 학점: " << gpa << "\n";

// 참조를 사용한 튜플
int score = 85;
auto student3 = tie(name, age, score);
score = 90;  // 튜플의 값도 함께 변경됨
cout << "Updated score through tuple reference: " << get<2>(student3) << "\n";
    
cout << "Set and Tuple demo completed.\n";
```

### 7.8 Chrono (시간 라이브러리)

#### 사용 사례
- **실행 시간 측정**이 필요할 때
- **시간 간격**을 다룰 때
- **시스템 시간**을 다룰 때

#### 예제 코드
```cpp
// 1. 시간 간격 (Duration)
auto one_second = 1s;        // 1초
auto half_second = 500ms;    // 500밀리초
auto total = one_second + half_second;  // 1.5초

// 2. 실행 시간 측정
auto start = high_resolution_clock::now();
// 작업 수행...
int calc_sum = 0;
for (int i = 0; i < 1000000; ++i) {
    calc_sum += i;
}
auto end = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(end - start);
cout << "작업 소요 시간: " << duration.count() << "마이크로초\n";

// 3. 시스템 시간
auto now = system_clock::now();
time_t now_time = system_clock::to_time_t(now);
cout << "현재 시간: " << ctime(&now_time);

// 4. 에포크 이후 시간
auto epoch = system_clock::time_point{};
auto now_since_epoch = system_clock::now() - epoch;
cout << "에포크 이후 초: " << duration_cast<seconds>(now_since_epoch).count() << "초\n";

// 5. Steady Clock (측정용)
auto steady_start = steady_clock::now();
this_thread::sleep_for(100ms);
auto steady_end = steady_clock::now();
auto steady_duration = duration_cast<milliseconds>(steady_end - steady_start);
cout << "수면 시간: " << steady_duration.count() << "ms\n";
```

## 8. 추가 학습 자료

- [C++ Reference](https://en.cppreference.com/)
- [C++ Standard Library Tutorial](https://www.cplusplus.com/reference/)
- [STL 컨테이너 선택 가이드](https://en.cppreference.com/w/cpp/container)
```

## 8. 추가 학습 자료

- [C++ Reference](https://en.cppreference.com/)
- [C++ Standard Library Tutorial](https://www.cplusplus.com/reference/)
- [STL 컨테이너 선택 가이드](https://en.cppreference.com/w/cpp/container)
