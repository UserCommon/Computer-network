rm release/*
rm debug/*
rm requests/*
rm responses/*

clang++ client.cc -o release/client --std=c++17
clang++ server.cc -o release/server --std=c++17

clang++ client.cc -fstandalone-debug -g -o debug/client.out.dSYM --std=c++17
clang++ server.cc -fstandalone-debug -g -o debug/server.out.dSYM --std=c++17
