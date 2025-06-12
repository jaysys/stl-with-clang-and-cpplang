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
- **FIFO(선입선출)** 구조가 필요할 때
- 작업 대기열, BFS 알고리즘 등에 사용

#### 예제 코드
```cpp
queue<int> q;
q.push(10);
q.push(20);
q.push(30);

// 큐에서 요소 제거 및 출력
while (!q.empty()) {
    cout << q.front() << " ";  // 10 20 30
    q.pop();
}
```

### 7.2 Deque (덱)

#### 사용 사례
- 양쪽 끝에서의 삽입/삭제가 빈번할 때
- 슬라이딩 윈도우 알고리즘 등에 사용

#### 예제 코드
```cpp
deque<int> dq = {1, 2, 3};
dq.push_front(0);    // 앞에 0 추가
dq.push_back(4);     // 뒤에 4 추가

// 덱의 모든 요소 출력
for (int n : dq) {
    cout << n << " ";  // 0 1 2 3 4
}
```

### 7.3 Stack (스택)

#### 사용 사례
- **LIFO(후입선출)** 구조가 필요할 때
- 함수 호출 스택, 괄호 검사, 계산기 구현 등에 사용

#### 예제 코드
```cpp
stack<int> s;
s.push(1);
s.push(2);
s.push(3);

// 스택에서 요소 제거 및 출력
while (!s.empty()) {
    cout << s.top() << " ";  // 3 2 1
    s.pop();
}
```

### 7.4 수치 알고리즘

#### 사용 사례
- 수학적 연산이 필요한 경우
- 컬렉션의 합계, 곱, 내적 등을 계산할 때

#### 예제 코드
```cpp
vector<int> nums = {1, 2, 3, 4, 5};

// 합계 계산
int sum = accumulate(nums.begin(), nums.end(), 0);
// sum = 15

// 곱 계산
int product = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
// product = 120

// 내적 계산
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {4, 5, 6};
int dot_product = inner_product(v1.begin(), v1.end(), v2.begin(), 0);
// dot_product = 32
```

### 7.5 함수형 프로그래밍

#### 사용 사례
- 컬렉션에 대한 함수형 연산이 필요할 때
- 조건부 필터링, 변환, 리듀스 등에 사용

#### 예제 코드
```cpp
vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// 짝수만 필터링
cout << "Even numbers: ";
copy_if(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "),
       [](int n) { return n % 2 == 0; });
// 출력: 2 4 6 8 10

// for_each를 사용한 제곱 계산
cout << "\nSquared numbers: ";
for_each(numbers.begin(), numbers.end(), [](int& n) {
    cout << n * n << " ";
});
// 출력: 1 4 9 16 25 36 49 64 81 100
```

## 8. 추가 학습 자료

- [C++ Reference](https://en.cppreference.com/)
- [C++ Standard Library Tutorial](https://www.cplusplus.com/reference/)
- [STL 컨테이너 선택 가이드](https://en.cppreference.com/w/cpp/container)
