##시간 관련 함수들 정리

1. std:chrono

  - ms, micros, 
  
  - std::chrono::system_clock::to_time_t
  - std::chrono::system_clock::from_time_t
  - time_t로 변환 가능
  
``` c++
auto now = std::chrono::system_clock::now();
auto time = std::chrono::system_clock::to_time_t(now);

struct tm* gm = gmtime(&now);
time_t gmt = mktime(gm);

struct tm* loc = localtime(&now);
time_t local = mktime(loc);

double diffSecond = difftime(local, gmt);
```

2. ctime
3. SYSTEMTIME
4. tm

- ms 를 지원하지 않는다.

5. time_t

- ms 를 지원하지 않는다.
