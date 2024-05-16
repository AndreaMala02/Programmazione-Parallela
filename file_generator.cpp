#include <fstream>

int main() {
    std::fstream out;
    out.open("input.txt", std::ios::out);
    char inizio = 'a';
    char fine = 'z';
    int diff = fine-inizio;
    for(int i=0; i<1000; i++) {
        if(i!=999) {
            for(int j=0; j<=diff; j++) {
                out << char(inizio+j) << " ";
            }
            out << std::endl;
        }
        else {
            out << 0;
        }
    }
    return 0;
}