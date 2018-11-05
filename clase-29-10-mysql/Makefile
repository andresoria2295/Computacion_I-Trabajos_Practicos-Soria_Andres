CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o fecha.o persona.o myconnection.o

LIBS =		-lmysqlcppconn -lmysqlcppconn-static

TARGET =	ejemplo2

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
