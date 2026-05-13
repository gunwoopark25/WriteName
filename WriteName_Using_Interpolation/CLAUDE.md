# C++ 프로젝트 가이드라인

## 코드 스타일

### 네이밍 규칙
- **클래스명**: PascalCase (예: `Approximation`, `Interpolation`, `WriteName`)
- **멤버 변수**: PascalCase (예: `Degree`, `Parameter`, `NumberOfConstraint`)
- **함수명**: PascalCase (예: `ChordLength()`, `makeBernsteinMatrix()`, `solveNormalization()`)
- **지역 변수**: camelCase 또는 단일 대문자 (예: `pivot`, `factor`, `Sum`, `X`)
- **루프 인덱스**: `i`, `j`, `k` 순서로 사용
- **포인터 배열**: `변수명 = new Type[크기]` 패턴

### 주석 스타일
- 섹션 구분은 반드시 `/*--- 내용 ---*/` 형식 사용
- 주석은 한국어로 작성
- 함수 내부 논리 단계마다 주석으로 구분
- 예시:
  ```cpp
  /*--- Bernstein Matrix 동적 할당 ---*/
  /*--- 행렬 곱 계산 ---*/
  /*--- 단위행렬 생성 ---*/
  ```

### 파일 구조
- 헤더 파일(`.h`): 클래스 선언, 멤버 변수, 함수 프로토타입만 포함
- 구현 파일(`.cpp`): 함수 구현, `using namespace std;` 선언
- `Point2D.h`: 2D 좌표 struct를 별도 파일로 관리
- `main.cpp`: 객체 생성 후 함수를 순서대로 호출하는 흐름만 담음

### 헤더 파일 형식
```cpp
#pragma once
#include "Point2D.h"

class ClassName {
public:
    // 생성자/소멸자
    ClassName();
    ~ClassName();

    // 변수 (public)
    int Degree;
    int Parameter;
    // ...

    // 함수
    void functionA();
    void functionB();
};
```
