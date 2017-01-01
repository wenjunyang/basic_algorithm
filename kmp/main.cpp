#include <iostream>

using namespace std;

/**
 * 计算next数组
 * @param pattern
 * @param out 输出，长度需要和pattern一致
 * @return
 */
bool next(const char* pattern, int* out) {
    if (NULL == pattern || NULL == out) {
        return false;
    }

    int len = strlen(pattern);
    out[0] = 0;
    for (int i = 1; i < len; i++) {
        int matched = out[i - 1];
        while (true) {
            if (pattern[i] == pattern[matched]) {
                out[i] = matched + 1;
                break;
            } else if (matched == 0) {
                out[i] = 0;
                break;
            } else {
                matched = out[matched];
            }
        }
    }
    return true;
}

/**
 * kmp字符串匹配算法
 * @param src
 * @param pattern
 * @param result 匹配的索引列表
 * @return 共匹配成功的次数
 */
int kmp(const char* src, const char* pattern, int* result) {
    if (NULL == src || NULL == pattern || NULL == result) {
        return -1;
    }

    int src_len = strlen(src);
    int pat_len = strlen(pattern);

    if (0 == src_len || 0 == pat_len) {
        return 0;
    }

    int src_idx = 0;
    int pat_idx = 0;
    int match_len = 0;

    int *pat_next = new int[strlen(pattern)];
    next(pattern, pat_next);

    while (src_idx < src_len) {
        if (src[src_idx] == pattern[pat_idx]) {
            if (pat_len - 1 == pat_idx) {
                result[match_len++] = src_idx - pat_idx;
                if (pat_idx > 0) {
                    pat_idx = pat_next[pat_idx];
                }
                src_idx += 1;
            } else {
                src_idx ++;
                pat_idx ++;
            }
        } else {
            if (0 == pat_idx) {
                src_idx += 1;
            } else {
                pat_idx = pat_next[pat_idx - 1];
            }
        }
    }
    delete pat_next;
    return match_len;

}

void test(const char* src, const char* pattern) {
    int* result = new int[strlen(src)];
    int len = kmp(src, pattern, result);
    cout << "src:" << src << ",pat:" << pattern << ",result:";
    for (int i = 0; i < len; i++) {
        cout << result[i] << ",";
    }
    cout << endl;
    delete result;
}

int main() {
    test("aaaaaaa", "a");
    test("aaaaaaaa", "aa");
    test("abababccccababav", "aba");
    test("abababccccababav", "av");
    return 0;
}
