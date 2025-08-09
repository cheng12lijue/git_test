#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// 定义学生结构体
struct Student {
    char name[NAME_LENGTH];
    float score;
};

// 函数声明
void inputStudents(struct Student students[], int n);
void printStudents(struct Student students[], int n);
float calculateAverage(struct Student students[], int n);
float findHighestScore(struct Student students[], int n);
float findLowestScore(struct Student students[], int n);

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("=== 学生成绩管理系统 ===\n");
    
    // 输入学生人数
    do {
        printf("请输入学生人数（1-%d）：", MAX_STUDENTS);
        scanf("%d", &numStudents);
    } while (numStudents <= 0 || numStudents > MAX_STUDENTS);

    // 输入学生信息
    inputStudents(students, numStudents);

    // 打印所有学生信息
    printf("\n");
    printStudents(students, numStudents);

    // 计算并显示统计信息
    printf("\n--- 统计信息 ---\n");
    printf("平均分: %.2f\n", calculateAverage(students, numStudents));
    printf("最高分: %.2f\n", findHighestScore(students, numStudents));
    printf("最低分: %.2f\n", findLowestScore(students, numStudents));

    printf("\n程序结束，谢谢使用！\n");
    return 0;
}

// 输入学生信息
void inputStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("请输入第 %d 个学生的姓名: ", i + 1);
        scanf("%s", students[i].name);
        
        do {
            printf("请输入 %s 的成绩（0-100）: ", students[i].name);
            scanf("%f", &students[i].score);
        } while (students[i].score < 0 || students[i].score > 100);
    }
}

// 打印所有学生信息
void printStudents(struct Student students[], int n) {
    printf("\n--- 学生信息列表 ---\n");
    for (int i = 0; i < n; i++) {
        printf("姓名: %s\t成绩: %.2f\n", students[i].name, students[i].score);
    }
}

// 计算平均分
float calculateAverage(struct Student students[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].score;
    }
    return sum / n;
}

// 找出最高分
float findHighestScore(struct Student students[], int n) {
    float highest = students[0].score;
    for (int i = 1; i < n; i++) {
        if (students[i].score > highest) {
            highest = students[i].score;
        }
    }
    return highest;
}

// 找出最低分
float findLowestScore(struct Student students[], int n) {
    float lowest = students[0].score;
    for (int i = 1; i < n; i++) {
        if (students[i].score < lowest) {
            lowest = students[i].score;
        }
    }
    return lowest;
}
