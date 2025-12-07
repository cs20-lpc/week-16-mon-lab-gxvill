SRC = Week16Mon.cpp

TARGET = Week16Mon

$(TARGET): $(SRC)
	g++ -std=c++23 $< -o $@

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)
