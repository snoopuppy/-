#include <iostream>  
#include <fstream>  
#include <vector>  
#include <string>  

using namespace std;

int calculate(string operation, vector<int>& numbers) {
    int result = numbers[0];
    if (operation == "add") {
        for (size_t i = 1; i < numbers.size(); i++) {
            result += numbers[i];
        }
    }
    else if (operation == "minus") {
        for (size_t i = 1; i < numbers.size(); i++) {
            result -= numbers[i];
        }
    }
    else if (operation == "multiply") {
        for (size_t i = 1; i < numbers.size(); i++) {
            result *= numbers[i];
        }
    }
    else if (operation == "divide") {
        for (size_t i = 1; i < numbers.size(); i++) {
            if (numbers[i] == 0) {
                cerr << "Error: Division by zero." << endl;
                return 0;
            }
            result /= numbers[i];
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "�÷��� " << argv[0] << " ������ѡ��ִ��������ļ���" << endl;
        cerr << "��ѡ������: add, minus, multiply, divide" <<"��������Ҫ���еļ���" << endl;
        cerr << "ʾ��: " << argv[0] << " add numbers.txt" << endl;
        cerr << "���򽫶��ļ��е����ֽ������Ӧ�ļӼ��˳��Ĳ�����" << endl;
        return 1;
    }

    string operation = argv[1];
    string filename = argv[2];
    vector<int> numbers;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    file.close();

    if (numbers.empty()) {
        cerr << "Error: File is empty." << endl;
        return 1;
    }

    int result = calculate(operation, numbers);
    cout << result << endl;

    return 0;
}