#include <iostream>
#include <fstream>
#include <vector>

/**
 * @brief 执行 input_maker.cpp
 *             solve_mine.cpp
 *             solve_others.cpp
 * @details input_maker.cpp 执行造出一份数据
 *          solve_mine.cpp solve_others.cpp 执行这份输入然后打入两个 output 文件中
 * 
 * @param i  第 i 次执行（待打入第 i 份样例）
 */
void run3Files (int id);

int main () {
    std::cout << "\n#######################\n";
    std::cout << "#     AC Detector     #";
    std::cout << "\n#######################\n\n";

    /* 编译三份待执行文件 */
    system("g++ ./input_maker.cpp -o ./compiled_file/input_maker -std=c++11");
    system("g++ ./solve_mine.cpp -o ./compiled_file/solve_mine -std=c++11");
    system("g++ ./solve_others.cpp -o ./compiled_file/solve_others -std=c++11");

    int error_cnt = 0;

    for (int i = 1; i <= 10; i ++) {
        run3Files(i);
        
        // ------- 两个输出文件进行比对 ------------
        std::ifstream fin_mine("./dst/sample" + std::to_string(i) + "/output_mine.txt"); 
        std::ifstream fin_others("./dst/sample" + std::to_string(i) + "/output_others.txt");
        bool flag = false;
        while (true) {
            char x, y;
            bool has_x = false, has_y = false;
            while (!fin_others.eof() && fin_mine >> x) {
                if (x != ' ' && x != '\n' && x != '\t' && x != '\r') {
                    has_x = true;
                    break; 
                }
            }
            while (!fin_others.eof() && fin_others >> y) {
                if (y != ' ' && y != '\n' && y != '\t' && y != '\r') {
                    has_y = true;
                    break; 
                }
            }
            if (!has_x && !has_y) {
                flag = true;
                break;
            }
            if (!has_x || !has_y || x != y) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << "detector> \033[32m" << "Accept" << "\033[0m in test " << i << std::endl;
        } else {
            std::cout << "detector> \033[31m" << "Wrong Answer" << "\033[0m in test " << i << std::endl;
            error_cnt ++;
        }
    }

    std::cout << "detector>\n";
    if (error_cnt == 0) {
        std::cout << "detector> 🎉 \033[1;37;42mAccept\033[0m";
        std::cout << "\033[1;32m for all samples!\033[0m\n\n";
    } else {
        std::cout << "detector> ❗ \033[1;37;41mWrong Answer\033[0m";
        std::cout << "\033[1;31m for " << error_cnt << " samples\033[0m\n\n";
    }
}

void run3Files (int i) {
    #ifdef _WIN32
        std::string cmd_input = "cd compiled_file && input_maker >../dst/sample" + std::to_string(i) + "/input.txt";
        std::string cmd_output_mine = "cd compiled_file && solve_mine <../dst/sample" + std::to_string(i) + "/input.txt >../dst/sample" + std::to_string(i) + "/output_mine.txt";
        std::string cmd_output_others = "cd compiled_file && solve_others <../dst/sample" + std::to_string(i) + "/input.txt >../dst/sample" + std::to_string(i) + "/output_others.txt";
        // ------- run input_maker.cpp ----------
        system(cmd_input.c_str());
        // ------- run solve_mine.cpp -----------
        system(cmd_output_mine.c_str());
        // ------- run solve_others.cpp -----------
        system(cmd_output_others.c_str());
    #else
        std::string cmd_input = "cd compiled_file && ./input_maker >../dst/sample" + std::to_string(i) + "/input.txt";
        std::string cmd_output_mine = "cd compiled_file && ./solve_mine <../dst/sample" + std::to_string(i) + "/input.txt >../dst/sample" + std::to_string(i) + "/output_mine.txt";
        std::string cmd_output_others = "cd compiled_file && ./solve_others <../dst/sample" + std::to_string(i) + "/input.txt >../dst/sample" + std::to_string(i) + "/output_others.txt";
        // ------- run input_maker.cpp ----------
        system(cmd_input.c_str());
        // ------- run solve_mine.cpp -----------
        system(cmd_output_mine.c_str());
        // ------- run solve_others.cpp -----------
        system(cmd_output_others.c_str());
    #endif
}