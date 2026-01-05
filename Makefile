# 컴파일러 설정
CC = gcc
CFLAGS = -g -Wall

# 실행 파일 이름
TARGET = main

# 소스 파일 목록 (나중에 파일이 늘어나면 뒤에 추가하면 됨)
SRCS = main.c Dynamic/DynamicArray.c

# 빌드 규칙 (make 라고 치면 실행됨)
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# 정리 규칙 (make clean 이라고 치면 실행됨)
clean:
	rm -f $(TARGET)