#include <iostream>
#include <math.h>

using namespace std;


void kmeans(int *array, int len, int k, int *out) {
    if (array == NULL || len <= 0) {
        printf("参数非法");
        return;
    }

    double *center = (double *) malloc(k * sizeof(double));
    double *min_array = (double *) malloc(len * sizeof(double));

    for (int i = 0; i < k; i++) {
        center[i] = array[i];
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < len; ++j) {
            min_array[j] = 99999999.0;
            out[j] = -1;
            for (int m = 0; m < k; ++m) {
                double dist = fabs(array[j] - center[m]);
                if (dist < min_array[j]) {
                    min_array[j] = dist;
                    out[j] = m;
                }
            }

        }
        for (int m = 0; m < k; ++m) {
            int cnt = 0;
            int x_sum = 0;
            for (int j = 0; j < len; ++j) {
                if (out[j] == m) {
                    cnt++;
                    x_sum += array[j];
                }
            }
            if (cnt > 0) {
                center[m] = (double)x_sum / (double)cnt;
            }
        }
        printf("\n=========第%d轮=============\n", i);
        for (int j = 0; j < len; ++j) {
            printf("第%d个元素%d的类别是%d\n", j, array[j], out[j]);
        }
    }
}

int main() {
    int a[] = {1, 10, 11, 12, 0, -1, 1, 2, 2, -100, -99, -97, -96};
    int len = sizeof(a)/ sizeof(int);
    int b[len];
    int k = 3;
    kmeans(a, len, 3, b);

//    for (int i = 0; i < len; ++i) {
//        printf("第%d个元素%d的类别是%d\n", i, a[i], b[i]);
//    }


    return 0;
}