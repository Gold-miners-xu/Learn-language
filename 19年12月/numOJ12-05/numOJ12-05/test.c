//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//
//示例 1 :
//
//给定数组 nums = [1, 1, 2],
//
//函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
//
//你不需要考虑数组中超出新长度后面的元素。



int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;
	int src = 0;
	int cont = 1;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != nums[src]) {
			src++;
			nums[src] = nums[i];
			cont++;
		}
	}
	numsSize = cont;
	return numsSize;
}
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入: [1, 2, 3, 4, 5, 6, 7] 和 k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]
void revers(int* nums, int begin, int end) {
	while (begin < end) {
		int tmp;
		tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;
		begin++;
		end--;
	}
}
void rotate(int* nums, int numsSize, int k) {
	//if(numsSize == 0)
	//   return;
	if (k > numsSize) {
		k %= numsSize;
	}
	revers(nums, 0, numsSize - 1);
	revers(nums, 0, k - 1);
	revers(nums, k, numsSize - 1);
}