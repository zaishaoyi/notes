#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
// https://blog.csdn.net/hellozhxy/article/details/79911867
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
/**********************
 * 1、冒泡排序
 * 是否比较排序： 比较排序
 * 平均时间复杂度：O(n^2)
 * 最好情况： O(n) 原始数组顺序排列。需要记录交换情况，如果一轮遍历没有发生交换，则数组已经有序，无需处理。
 * 最坏情况： O(n^2) 原始数组逆序排列
 * 排序方式：In-Place
 * 空间复杂度： O(1)
 * 稳定性： 稳定
 */
/*********************************
 * 其他： bool 和 BOOL的区别
 * bool 类型，C++关键字，一个字节大小，取值 true(1)/false(0)
 * BOOL 类型，C++中宏定义（#define FALSE 0），四个字节大小(有些环境int型为两个字节)，实际为int型,取值TRUE(1)/FALSE(0)
 * int型大小：编译器可以根据自身硬件来选择合适的大小，但是需要满足约束：
 *     1、short和int型至少为16位，long型至少为32位
 *     2、short型长度不能超过int型，而int型不能超过long型。
 * 这即是说各个类型的变量长度是由编译器来决定的
*/

void BubbleSort(int arr[], int len) {
	if (NULL == arr) {
		return;
	}
	for (int i = 0; i < len; i++) {
		bool is_swap = false;
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				is_swap = true;
			}
		}
		if (!is_swap) {
			break;
		}
	}

}
/**********************************************
 * 2、选择排序
 * 是否比较排序： 比较排序
 * 平均时间复杂度： O（N^2）
 * 最好情况： O(N^2)
 * 最差情况： O(N^2)
 * 排序方式：In-Place
 * 空间复杂度： O(1)
 * 稳定性： 不稳定，比如{5，5，2}；但是如果新开辟一个数据，即Out-Place，或者用链表实现，则稳定
 */ 
void SelectionSort(int arr[], int len) {
	if (NULL == arr) {
		return;
	}
	for (int i = 0; i < len; i++) {
		int min = arr[i];
		int index = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}
		if (index != i) {
			swap(arr[i], arr[index]);
		}
	}
}

/******************************************
 * 3、插入排序
 * 是否比较排序： 比较排序
 * 平均时间复杂度： O（N^2）
 * 最好情况： O(N)
 * 最差情况： O(N^2)
 * 排序方式：In-Place
 * 空间复杂度： O(1)
 * 稳定性： 稳定
 */
// 直观写法
void InsertionSort(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	for (int i = 1; i < len; i++) {
		int std = arr[i];
		int j = i - 1;
		for (j = i - 1; j >= 0; j--) {
			if (std > arr[j]) {
				break;
			}
		}
		for (int k = i; k > j + 1; k--) {
			arr[k] = arr[k - 1];
		}
		arr[j + 1] = std;
	}
}
void InsertionSortV2(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	for (int i = 1; i < len; i++) {
		int std = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > std) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = std;
	}
}
/***********************************
* 4、希尔排序
* desc: 简单插入排序的改进版，又称缩小增量排序。与插入排序的区别是优先比较距离较远的两个元素
* 是否比较排序： 比较排序
* 平均时间复杂度： O（NlogN）
* 最好情况： O(NlogN)
* 最差情况： O(NlogN)
* 排序方式：In-Place
* 空间复杂度： O(1)
* 稳定性： 不稳定
*/
// 4、希尔排序
void ShellSort(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}

	int gap = len / 2;
	while (gap > 0) {
		// gap之前的元素为子数组第一个元素的集合
		// 所以从gap向后，调整每个元素在子数组中的位置
		for (int i = gap; i < len; i++) {
			int j = i;
			int std = arr[i];
			while ((j - gap >= 0) && (arr[j - gap] > arr[j])) {
				swap(arr[j - gap], arr[j]);
				j -= gap;
			}
		}

		// 缩小gap
		gap = gap / 2;
	}
}

/***********************************
* 5、归并排序
* desc: 分治法。和选择排序一样，不受输入数据的影响。
* 是否比较排序： 比较排序
* 平均时间复杂度： O（NlogN）
* 最好情况： O(NlogN)
* 最差情况： O(NlogN)
* 排序方式：Out-Place
* 空间复杂度： O(n)
* 稳定性： 稳定
*/

// C++不能返回数组，可以通过返回指针实现
void merge(int arr[], int left, int right) {
	if (right - left < 1) {
		return;
	}
	int len = right - left + 1;
	int mid = len / 2;
	int *temp = new int[len];
	int i = left;
	int j = left + mid;
	int temp_len = 0;
	while ((i < left + mid) || (j <= right)) {
		if (i >= left + mid) {
			temp[temp_len++] = arr[j++];
		}
		else if (j > right) {
			temp[temp_len++] = arr[i++];
		}
		else if (arr[i] < arr[j]) {
			temp[temp_len++] = arr[i++];
		}
		else {
			temp[temp_len++] = arr[j++];
		}
	}
	for (int k = 0; k < temp_len; k++) {
		arr[left + k] = temp[k];
	}
	delete[] temp;
	temp = NULL;
}
void MergeSort(int arr[], int begin, int end) {
	int len = end - begin + 1;
	if (len < 2) {
		return;
	}
	int mid = len / 2;
	MergeSort(arr, begin, begin + mid - 1);
	MergeSort(arr, begin + mid, end);
	merge(arr, begin, end);

}

/****************************************
 * 6、快速排序
 * 是否比较排序： 比较排序
 * 平均时间复杂度： O（NlogN）
 * 最好情况： O(NlogN)
 * 最差情况： O(N^2)
 * 排序方式：In-Place
 * 空间复杂度： O(1)
 * 稳定性： 不稳定
 */
int partition(int arr[], int start, int end) {
	int privot = arr[start];
	int left = start;
	int right = end;
	while (left < right) {
		while ((left < right) && (arr[right] > privot)) {
			right--;
		}
		if (left < right) {
			arr[left++] = arr[right];
		}
		while ((left < right) && (arr[left] < privot)) {
			left++;
		}
		if (left < right) {
			arr[right--] = arr[left];
		}
	}
	arr[left] = privot;
	return left;
}
void QuickSort(int arr[], int start, int end) {
	int len = end - start + 1;
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	int pos = partition(arr, start, end);
	if (pos > start) {
		QuickSort(arr, start, pos - 1);
	}
	if (pos < end) {
		QuickSort(arr, pos + 1, end);
	}
}

/************************************
 * 7、堆排序
 * 是否比较排序： 比较排序
 * 平均时间复杂度： O（NlogN）
 * 最好情况： O(NlogN)
 * 最差情况： O(NlogN)
 * 排序方式：In-Place
 * 空间复杂度： O(1)
 * 稳定性： 不稳定
 */
// 当前节点 i
// 左子节点 2*i + 1
// 右子节点 2*i + 2
// 父节点 （i - 1）/2
// 最后一个非叶子节点：(len -1)/2
// 构建大顶堆
void HeadAdjust(int arr[], int i, int len) {
	int std = arr[i];
	while (2 * i + 1 < len) {
		int iMax = 2 * i + 1;
		if ((2 * i + 2 < len) && (arr[2 * i + 1] < arr[2 * i + 2])) {
			iMax = 2 * i + 2;
		}
		if (arr[iMax] > std) {
			arr[i] = arr[iMax];
			i = iMax;
			continue;
		}
		break;
	}
	arr[i] = std;
}
void HeapSort(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	// 构建大顶堆
	for (int i = (len - 1) / 2; i >= 0; i--) {
 		HeadAdjust(arr, i, len);
	}
	for (int j = len - 1; j > 0; j--) {
		swap(arr[0], arr[j]);
		HeadAdjust(arr, 0, j);
	}
}
/************************************
 * 8、计数排序
 * 是否比较排序： 非比较排序
 * 平均时间复杂度： O（N+K）（输入N个0-K之间的数字）
 * 最好情况： O(N+K)
 * 最差情况： O(N+K)
 * 排序方式：Out-Place
 * 空间复杂度： O(K)
 * 稳定性： 稳定
*/
// 8、计数排序
void CountingSort(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	if (max == min) {
		return;
	}
	int* bucket = new int[max - min + 1];
	memset(bucket, 0, sizeof(int) * (max - min + 1));
	int bias = min - 0;
	for (int i = 0; i < len; i++) {
		bucket[arr[i] - bias] += 1;
	}
	int index = 0;
	int i = 0;
	while (i < max - min + 1) {
		if (bucket[i] > 0) {
			arr[index++] = i + bias;
			bucket[i] -= 1;
		} else {
			i++;
		}
		
	}
	delete[] bucket;
	bucket = NULL;
}

/********************************
 * 9、桶排序
 * 是否比较排序： 非比较排序
 * 平均时间复杂度： O（N+K）（输入N个0-K之间的数字）
 * 最好情况： O(N+K)
 * 最差情况： O(N+K)
 * 排序方式：Out-Place
 * 空间复杂度： O(K)
 * 稳定性： 稳定
 */
// 
void BucketSort(int arr[], int len, int bucket_size) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	// 统计输入范围
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	// 初始化数组
	int range = max - min + 1;
	int bucket_count = range / bucket_size + 1;
	int** buckets = new int*[bucket_count];
	for (int i = 0; i < bucket_count; i++) {
		buckets[i] = new int[bucket_size];
		memset(buckets[i], 0, sizeof(int) * bucket_size);
	}

	// 填充数组
	for (int i = 0; i < len; i++) {
		int row = (arr[i] - min) / bucket_size;
		int col = (arr[i] - min) % bucket_size;
 		buckets[(arr[i] - min) / bucket_size][(arr[i] - min) % bucket_size] += 1;
	}

	// 排序结果
	int index = 0;
	for (int i = 0; i < bucket_count; i++) {
		int j = 0;
		while (j < bucket_size) {
			if (buckets[i][j] > 0) {
				arr[index++] = bucket_size * i + j + min;
				buckets[i][j] --;
			} else {
				j++;
			}
		}
	}
	// 删除动态数组
	for (int i = 0; i < bucket_count; i++) {
		delete[] buckets[i];
		buckets[i] = NULL;
	}
	delete[] buckets;
	buckets = NULL;
}

/********************************
* 10、基数排序
* 是否比较排序： 非比较排序
* 平均时间复杂度： O（N*K）（K为数组中最大数的位数）
* 最好情况： O(N*K)
* 最差情况： O(N*K)
* 排序方式：Out-Place
* 空间复杂度： O(K)
* 稳定性： 稳定
*/
void RadixSort(int arr[], int len) {
	if ((NULL == arr) || (len < 2)) {
		return;
	}
	// 寻找最大值
	int max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	// 算出位数
	int iDigit = 0;
	while (max > 0) {
		max /= 10;
		iDigit++;
	}
	// 排序,借助vector数据结构
	int radix = 1;
	for (int i = 0; i < iDigit; i++) {
		vector<vector<int>> temp_vec;
		for (int j = 0; j < 10; j++) {
			temp_vec.push_back(vector<int>());
		}
		for (int j = 0; j < len; j++) {
			temp_vec[arr[j] / radix % 10].push_back(arr[j]);
		}
		int index = 0;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < temp_vec[j].size(); k++) {
				arr[index++] = temp_vec[j][k];
			}
		}
		radix *= 10;
	}
}
// 输出
void output(int arr[], int len) {
	if (NULL == arr) {
		return;
	}

	for (int i = 0; i < len; i++) {
		std::cout << *(arr + i) << " ";
	}
	std::cout << std::endl;
	return;
}

int main(int argc, char** argv) {
	int arr[10] = { 0 };
	
	int retry = 3;
	int rangeL = 0;
	int rangeR = 100;
	srand(time(NULL));
	for (int i = 0; i < retry; i++) {
		// 生成随机数列
		for (int j = 0; j < 10; j++) {
			arr[j] = rand() % (rangeR - rangeL) + rangeL;
		}

		// 输出排序前结果
		std::cout << "random_array: ";
		output(arr, sizeof(arr)/sizeof(arr[0]));
		// 排序
		// BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
		// SelectionSort(arr, sizeof(arr) / sizeof(arr[0]));
		// InsertionSort(arr, sizeof(arr) / sizeof(arr[0]));
		// InsertionSortV2(arr, sizeof(arr) / sizeof(arr[0]));
		// ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
		// MergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) -1);
		// QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
		// HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
		// CountingSort(arr, sizeof(arr) / sizeof(arr[0]));
		// BucketSort(arr, sizeof(arr) / sizeof(arr[0]), 5);
		RadixSort(arr, sizeof(arr) / sizeof(arr[0]));
		// 输出排序后结果
		std::cout << "sorted array: ";
		output(arr, sizeof(arr) / sizeof(arr[0]));
	}
	system("pause");
	return 0;
}