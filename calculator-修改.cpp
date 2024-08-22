#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief 执行指定的算术操作
 *
 * @param operation 操作类型： "add"（加法），"minus"（减法），"multiply"（乘法），"divide"（除法）
 * @param numbers 操作的整数向量
 * @return 操作结果
 */
int calculate(const string& operation, const vector<int>& numbers) {
    if (numbers.empty()) {
        cerr << "错误：没有要处理的数字。" << endl;
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
                cerr << "错误：除数为零。" << endl;
                return 0;
            }
            result /= numbers[i];
        }
    }
    else {
        cerr << "错误：不支持的操作 '" << operation << "'。" << endl;
        return 0;
    }
    return result;
}

int main(int argc, char* argv[]) {
    // 检查命令行参数
    if (argc != 3) {
        cerr << "用法: " << argv[0] << " <operation> <filename>" << endl;
        cerr << "操作类型: add, minus, multiply, divide" << endl;
        cerr << "示例: " << argv[0] << " add numbers.txt" << endl;
        return 1;
    }

    string operation = argv[1];
    string filename = argv[2];
    vector<int> numbers;

    // 从文件中读取数字
    ifstream file(filename);
    if (!file) {
        cerr << "打开文件错误: " << filename << endl;
        return 1;
    }

    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    if (file.bad()) {
        cerr << "从文件读取错误: " << filename << endl;
        return 1;
    }

    file.close();

    if (numbers.empty()) {
        cerr << "错误：文件为空或没有找到有效的数字。" << endl;
        return 1;
    }

    // 计算并输出结果
    int result = calculate(operation, numbers);
    if (result != 0 || (operation == "divide" && numbers.size() == 1)) {
        cout << result << endl;
    }

    return 0;
}
