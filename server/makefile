#版本三
CC=g++
CFLAGS=-g -Wall

HEADER_PATH = -I/usr/local/mysql/mysql-8.0.29/include
LIB_PATH = -L/usr/local/mysql/mysql-8.0.29/lib 

target=server
src=$(wildcard *.cpp)
obj=$(patsubst %.cpp, %.o, $(src))
link=-lpthread `mysql_config --cflags --libs` -lcrypt  -I/usr/local/mysql/mysql-8.0.29/include -L/usr/local/mysql/mysql-8.0.29/lib -lmysqlclient
$(target):$(obj)
	$(CC) $(CFLAGS)  $^ -o $@ $(link)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(link)
clean:
	rm -rf $(target) $(obj)
