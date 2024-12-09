# INF3105 / TP5
# Automne 2023
#
# Vos noms et codes permanents:
#  1) Jean-Christophe Clouâtre (CLOJ73020201)

CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++20 -O2
SRCS = $(wildcard *.cpp)
FICHIER = $(wildcard *.txt)
OBJS = $(SRCS:.cpp=.o)
TARGET = tp5

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET) $(FICHIER) Mapnik

# rm -rf $(OBJS) $(TARGET) Mapnik

.PHONY: all clean
