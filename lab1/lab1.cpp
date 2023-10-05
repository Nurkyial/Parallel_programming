#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main() {

    // открываем файл для чтения в двоичном формате
    ifstream infile("D:\\10.jpg", ios::binary);

    // создаем пустой вектор для хранения содержимого файла
    vector<unsigned char> buffer;

    // если файл успешно открыт, заполняем вектор содержимым файла
    if (infile.is_open()) {
        buffer.assign(istreambuf_iterator<char>(infile), {});
        infile.close();
        cout << "File opened succesfully\n";
    } else {
        cerr << "Error opening input file\n";
        return -1;
    }

    // определяем выходной файл
    ofstream outfile("D:\\output.jpg", ios::binary | ios::trunc);

    vector<unsigned char> newb(buffer.size());
    int x = 5;

    for (int i = 0; i < buffer.size(); i++)
        newb[i] = (buffer[i] * x % 256);

    outfile.write(reinterpret_cast<const char*>(newb.data()), buffer.size());

    cout << "File was succesfully saved to output file\n";



    return 0;  
}