FROM gcc:latest
COPY . /cpp-dev
WORKDIR /cpp-dev
EXPOSE 8080
RUN g++ main.cpp httplib.h -std=c++17 -pthread 
CMD ["./a.out"]