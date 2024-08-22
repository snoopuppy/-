#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief ִ��ָ������������
 *
 * @param operation �������ͣ� "add"���ӷ�����"minus"����������"multiply"���˷�����"divide"��������
 * @param numbers ��������������
 * @return �������
 */
int calculate(const string& operation, const vector<int>& numbers) {
    if (numbers.empty()) {
        cerr << "����û��Ҫ��������֡�" << endl;
        return 0;
    }

    int result = numbers[0];
    size_t size = numbers.size();

    if (operation == "add") {
        for (size_t i = 1; i < size; ++i) {
            result += numbers[i];
        }
    }
    else if (operation == "minus") {
        for (size_t i = 1; i < size; ++i) {
            result -= numbers[i];
        }
    }
    else if (operation == "multiply") {
        for (size_t i = 1; i < size; ++i) {
            result *= numbers[i];
        }
    }
    else if (operation == "divide") {
        for (size_t i = 1; i < size; ++i) {
            if (numbers[i] == 0) {
                cerr << "���󣺳���Ϊ�㡣" << endl;
                return 0;
            }
            result /= numbers[i];
        }
    }
    else {
        cerr << "���󣺲�֧�ֵĲ��� '" << operation << "'��" << endl;
        return 0;
    }
    return result;
}

int main(int argc, char* argv[]) {
    // ��������в���
    if (argc != 3) {
        cerr << "�÷�: " << argv[0] << " <operation> <filename>" << endl;
        cerr << "��������: add, minus, multiply, divide" << endl;
        cerr << "ʾ��: " << argv[0] << " add numbers.txt" << endl;
        return 1;
    }

    string operation = argv[1];
    string filename = argv[2];
    vector<int> numbers;

    // ���ļ��ж�ȡ����
    ifstream file(filename);
    if (!file) {
        cerr << "���ļ�����: " << filename << endl;
        return 1;
    }

    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    if (file.bad()) {
        cerr << "���ļ���ȡ����: " << filename << endl;
        return 1;
    }

    file.close();

    if (numbers.empty()) {
        cerr << "�����ļ�Ϊ�ջ�û���ҵ���Ч�����֡�" << endl;
        return 1;
    }

    // ���㲢������
    int result = calculate(operation, numbers);
    if (result != 0 || (operation == "divide" && numbers.size() == 1)) {
        cout << result << endl;
    }

    return 0;
}
