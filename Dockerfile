FROM gcc:4.9
WORKDIR /usr/local/
COPY rover-reader.cpp ./rover-reader.cpp
RUN g++ -o rover-reader rover-reader.cpp
CMD ["./rover-reader"]
